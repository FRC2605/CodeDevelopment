#include "TCPSocket.h"

TCPSocket :: TCPSocket ( TCP :: AddressType Type, DisconnectBehavior Disconnection ):
	SocketFD ( - 1 ),
	SendCounter ( 0 ),
	ReceiveCounter ( 0 ),
	Bound ( false ),
	Type ( Type ),
	Disconnection ( Disconnection ),
	DisconnectCallback ( NULL ),
	Connected ( false ),
	SocketSync ( true ),
	UserDataSync ( true ),
	UserData ( NULL )
{
	
	int Namespace;
	
	switch ( Type )
	{
		
	case TCP :: kAddressType_IPV4:
		
		Namespace = PF_INET;
		
		break;
		
	case TCP :: kAddressType_IPV6:
		
		Namespace = PF_INET6;
		
		break;
		
	default:
		THROW_ERROR ( "AddressType must be a valid enum in TCPSocket :: AddressType!" );
		
	}
	
	SocketFD = socket ( Namespace, SOCK_STREAM, IPPROTO_TCP );
	
	if ( SocketFD < 0 )
		THROW_ERROR ( "Couldn't create socket!" );
	
};

TCPSocket :: TCPSocket ( TCP :: AddressType Type, DisconnectBehavior Disconnection, uint16_t Port ):
	SocketFD ( - 1 ),
	SendCounter ( 0 ),
	ReceiveCounter ( 0 ),
	Bound ( true ),
	BoundPort ( Port ),
	Type ( Type ),
	Disconnection ( Disconnection ),
	DisconnectCallback ( NULL ),
	Connected ( false ),
	SocketSync ( true ),
	UserDataSync ( true ),
	UserData ( NULL )
{
	
	int Namespace;
	
	switch ( Type )
	{
		
	case TCP :: kAddressType_IPV4:
		
		Namespace = PF_INET;
		
		break;
		
	case TCP :: kAddressType_IPV6:
	
		Namespace = PF_INET6;
		
		break;
		
	default:
	
		THROW_ERROR ( "AddressType must be a valid enum in TCPSocket :: AddressType!" );
		
	}
	
	SocketFD = socket ( Namespace, SOCK_STREAM, IPPROTO_TCP );
	
	if ( SocketFD < 0 )
		THROW_ERROR ( "Couldn't create socket!" );
	
};

void TCPSocket :: SetDisconnectionCallback ( IDelegate1 <void, TCPSocket *> * Callback )
{
	
	Synchronized Sync ( & SocketSync );
	
	DisconnectCallback = Callback;
	
};

void TCPSocket :: Connect ( const char * Address, uint16_t Port )
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( Connected )
		return;
	
	this -> Port = Port;
	this -> Address = Address;
	
	struct sockaddr * SocketAddress;
	size_t AddressSize;
	
	SendCounter = 0;
	ReceiveCounter = 0;
	
	switch ( Type )
	{
		
	case TCP :: kAddressType_IPV4:
	
		IPV4Address.sin_family = AF_INET;
		IPV4Address.sin_port = htons ( Port );
		
		inet_pton ( AF_INET, Address, & IPV4Address.sin_addr );
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV4Address );
		AddressSize = sizeof ( IPV4Address );
		
		break;
		
	case TCP :: kAddressType_IPV6:
	
		IPV6Address.sin6_family = AF_INET6;
		IPV6Address.sin6_port = htons ( Port );
		
		inet_pton ( AF_INET6, Address, & IPV6Address.sin6_addr );
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV6Address );
		AddressSize = sizeof ( IPV6Address );
		
		break;
		
	default:
		THROW_ERROR ( "AddressType must be a valid enum in TCP :: AddressType!" );
		
	}
	
	if ( connect ( SocketFD, SocketAddress, AddressSize ) < 0 )
		THROW_ERROR ( "Couldn't connect to the specified address!" );
	
	Connected = true;
	
};

void TCPSocket :: Disconnect ( bool Callback )
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( ! Connected )
		return;
	
	int ErrorCode = close ( SocketFD );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case EINTR:
		THROW_ERROR ( "The TCP socket closing was interrupted by a signal!" );
		
	case EIO:
		THROW_ERROR ( "An unspecified IO Error occured closing the TCP Socket!" );
		
	default:
		THROW_ERROR ( "Unspecified error disconnecting TCP socket!" );
		
	}
	
	Connected = false;
	
	if ( Callback && DisconnectCallback != NULL )
		DisconnectCallback -> Call ( this );
	
};

bool TCPSocket :: IsConnected ()
{
	
	Synchronized Sync ( & SocketSync );
	
	return Connected;
	
};

uint32_t TCPSocket :: GetWriteCount ()
{
	
	Synchronized Sync ( & SocketSync );
	
	return SendCounter;
	
};

uint32_t TCPSocket :: GetReadCount ()
{
	
	Synchronized Sync ( & SocketSync );
	
	return ReceiveCounter;
	
};

void TCPSocket :: Write ( const void * Buffer, size_t Length, bool DontBlock )
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( ! Connected )
		THROW_ERROR ( "Attempt to write from unconnected TCP socket!" );
	
	if ( send ( SocketFD, Buffer, Length, DontBlock ? MSG_DONTWAIT : 0 ) == - 1 )
	{
		
		switch ( errno )
		{
			
		case EACCES:
			THROW_ERROR ( "Invalid permissions to write to TCP socket!" );
		
		case ECONNRESET:
		
			Connected = false;
			
			switch ( Disconnection )
			{
				
			case kDisconnectBehavior_SilentError:
				return;
				
			case kDisconnectBehavior_FailureCallback:
				
				if ( DisconnectCallback != NULL )
				{
					
					DisconnectCallback -> Call ( this );
					return;
					
				}
				
				THROW_ERROR ( "TCP Socket disconnected! ( Disconnect behavior was kDisconnectBehavior_FailureCallback but no callback was set. )" );
				
			case kDisconnectBehavior_ThrowError:
			
				THROW_ERROR ( "TCP Socket disconnected! ( Disconnect behavior was kDisconnectBehavior_FailureCallback but no callback was set. )" );
				
			case kDisconnectBehavior_SpinReconnect:
			
				Connect ( Address, Port );
				return Write ( Buffer, Length, DontBlock );
				
			}
			
		case EFAULT:
			THROW_ERROR ( "Invalid user-space address given for buffer argument!" );
			
		case EINTR:
			THROW_ERROR ( "A signal occured before any data was sent from the socket!" );
			
		case EINVAL:
			THROW_ERROR ( "An invalid argument was passed!" );
			
		case ENOBUFS:
			THROW_ERROR ( "The output queue for the network interface this socket is using was full!" );
			
		case ENOMEM:
			THROW_ERROR ( "Insufficient memory to send from socket!" );
			
		case ENOTCONN:
			THROW_ERROR ( "The socket was not connected!" );
			
		case EPIPE:
			THROW_ERROR ( "The local end has been shut down on this socket!" );
			
		default:
			THROW_ERROR ( "Unspecified TCP write error!" );
			
		}
		
	}
	
	SendCounter ++;
	
};

void TCPSocket :: Read ( void * Buffer, size_t Length, bool Fill, size_t * Received, bool * Closed )
{
	
	Synchronized Sync ( & SocketSync );
	
	size_t ReceivedBytes;
	
	if ( ! Connected )
		THROW_ERROR ( "Attempt to read from unconnected TCP Socket!" );
	
	if ( Closed != NULL )
		* Closed = false;
	
	if ( Fill )
	{
		
		ReceivedBytes = recv ( SocketFD, Buffer, Length, MSG_WAITALL );
		
		if ( ReceivedBytes == -1 )
		{
			
			switch ( errno )
			{
				
			case EFAULT:
				THROW_ERROR ( "TCP Read failed because the passed buffer was outside of this process's address space!" );
			
			case EINTR:
				THROW_ERROR ( "TCP Read failed due to being signaled!" );
			
			default:
				THROW_ERROR ( "TCP Read failed due to an unspecified error!" );
				
			}
			
		}
		
		if ( ReceivedBytes == 0 )
		{
			
			if ( Closed != NULL )
				* Closed = true;
			else
				THROW_ERROR ( "The TCP Connection was closed and a status boolean was not provided to listen!" );
			
		}
		
		ReceiveCounter ++;
		
	}
	else
	{
		
		ReceivedBytes = recv ( SocketFD, Buffer, Length, 0 );
		
		if ( ReceivedBytes == -1 )
		{
			
			switch ( errno )
			{
				
			case EFAULT:
				THROW_ERROR ( "TCP Read failed because the passed buffer was outside of this process's address space!" );
			
			case EINTR:
				THROW_ERROR ( "TCP Read failed due to being signaled!" );
			
			default:
				THROW_ERROR ( "TCP Read failed due to an unspecified error!" );
				
			}
			
		}
		
		if ( ReceivedBytes == 0 )
		{
			
			if ( Closed != NULL )
				* Closed = true;
			else
				THROW_ERROR ( "The TCP Connection was closed and a status boolean was not provided to listen!" );
			
		}
		
		ReceiveCounter ++;
		
	}
	
	if ( Received != NULL )
		* Received = ReceivedBytes;
	
};

size_t TCPSocket :: GetBytesAvailible ()
{
	
	Synchronized Sync ( & SocketSync );
	
	int Value;
	int ErrorCode = ioctl ( SocketFD, FIONREAD, & Value );
	
	switch ( ErrorCode )
	{
	case 0:
		break;
		
	default:
		THROW_ERROR ( "Unspecified error getting the number of availible bytes in the TCP buffer!" );
		
	}
	
	return static_cast <size_t> ( Value );
	
};

void TCPSocket :: SetUserData ( void * UserData )
{
	
	UserDataSync.Lock ();
	
	this -> UserData = UserData;
	
	UserDataSync.Unlock ();
	
};

void * TCPSocket :: GetUserData ()
{
	
	UserDataSync.Lock ();
	
	void * Data = UserData;
	
	UserDataSync.Unlock ();
	
	return Data;
	
};

TCPSocket :: ~TCPSocket ()
{
	
	if ( Connected )
		Disconnect ();
	
};
