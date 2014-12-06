#include "TCPServerSocket.h"

#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <unistd.h>

#ifdef __VXWORKS__
	#include <ioLib.h>
	#include <sockLib.h>
#endif

TCPServerSocket :: TCPServerSocket ( TCP :: AddressType Type, DisconnectBehavior Behavior ):
	Type ( Type ),
	Disconnection ( Behavior ),
	DisconnectCallback ( NULL ),
	UserDataSync ( true ),
	UserData ( NULL ),
	SendCounter ( 0 ),
	ReceiveCounter ( 0 ),
	SocketSync ( true ),
	Connected ( false )
{
};

TCPServerSocket :: ~TCPServerSocket ()
{
	
	if ( Connected )
		Disconnect ( false );
	
};

void TCPServerSocket :: SetUserData ( void * UserData )
{
	
	UserDataSync.Lock ();
	
	this -> UserData = UserData;
	
	UserDataSync.Unlock ();
	
};

void * TCPServerSocket :: GetUserData ()
{
	
	UserDataSync.Lock ();
	
	void * Data = UserData;
	
	UserDataSync.Unlock ();
	
	return Data;
	
};

void TCPServerSocket :: SetDisconnectionCallback ( IDelegate1 <void, TCPServerSocket *> * Callback )
{
	
	SocketSync.Lock ();
	
	DisconnectCallback = Callback;
	
	SocketSync.Unlock ();
	
};

void TCPServerSocket :: Disconnect ( bool Callback )
{
	
	SocketSync.Lock ();
	
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
	{
		
		SocketSync.Unlock ();
		
		DisconnectCallback -> Call ( this );
		return;
	
	}
	
	SocketSync.Unlock ();
	
};

void TCPServerSocket :: Write ( const void * Buffer, size_t Length, bool DontBlock )
{
	
	SocketSync.Lock ();
	
	if ( ! Connected )
		THROW_ERROR ( "Attempt to write from unconnected TCP socket!" );
	
	if ( send ( SocketFD, reinterpret_cast <const char *> ( Buffer ), Length, DontBlock ? MSG_DONTWAIT : 0 ) == - 1 )
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
					
					SocketSync.Unlock ();
					
					DisconnectCallback -> Call ( this );
					
					return;
					
				}
				
				THROW_ERROR ( "TCP Socket disconnected! ( Disconnect behavior was kDisconnectBehavior_FailureCallback but no callback was set. )" );
				
			case kDisconnectBehavior_ThrowError:
			
				THROW_ERROR ( "TCP Socket disconnected! ( Disconnect behavior was kDisconnectBehavior_FailureCallback but no callback was set. )" );
				
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
	
	SocketSync.Unlock ();
	
};

void TCPServerSocket :: Read ( void * Buffer, size_t Length, bool Fill, size_t * Received, bool * Closed )
{
	
	SocketSync.Lock ();
	
	ssize_t ReceivedBytes;
	
	if ( ! Connected )
		THROW_ERROR ( "Attempt to read from unconnected TCP Socket!" );
	
	if ( Closed != NULL )
		* Closed = false;
	
	if ( Fill )
	{
		
		ReceivedBytes = recv ( SocketFD, reinterpret_cast <char *> ( Buffer ), Length, MSG_WAITALL );
		
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
		
		ReceivedBytes = recv ( SocketFD, reinterpret_cast <char *> ( Buffer ), Length, 0 );
		
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
	
	SocketSync.Unlock ();
	
};
