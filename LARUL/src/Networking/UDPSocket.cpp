#include "UDPSocket.h"

#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <unistd.h>

#ifdef __VXWORKS__
	#include <VxWorks.h>
	#include <sockLib.h>
	#undef socklen_t
	#define socklen_t int
#endif

UDPSocket :: UDPSocket ( UDP :: AddressType Type ):
	SocketFD ( - 1 ),
	SendCounter ( 0 ),
	ReceiveCounter ( 0 ),
	Bound ( false ),
	Type ( Type ),
	SocketSync ( true ),
	UserDataSync ( true ),
	UserData ( NULL )
{
	
	int Namespace;
	
	switch ( Type )
	{
		
	case UDP :: kAddressType_IPV4:
		
		Namespace = PF_INET;
		
		break;
		
	case UDP :: kAddressType_IPV6:
		
		Namespace = PF_INET6;
		
		break;
		
	default:
		THROW_ERROR ( "AddressType must be a valid enum in UDP :: AddressType!" );
		
	}
	
	SocketFD = socket ( Namespace, SOCK_DGRAM, 0 );
	
	if ( SocketFD < 0 )
		THROW_ERROR ( "Couldn't create socket!" );
	
	Target ( "0.0.0.0", 65535 );
	
};

UDPSocket :: UDPSocket ( UDP :: AddressType Type, uint16_t Port ):
	SocketFD ( - 1 ),
	SendCounter ( 0 ),
	ReceiveCounter ( 0 ),
	Bound ( true ),
	BoundPort ( Port ),
	Type ( Type ),
	SocketSync ( true ),
	UserDataSync ( true ),
	UserData ( NULL )
{
	
	int Namespace;
	
	switch ( Type )
	{
		
	case UDP :: kAddressType_IPV4:
		
		Namespace = PF_INET;
		
		break;
		
	case UDP :: kAddressType_IPV6:
		
		Namespace = PF_INET6;
		
		break;
		
	default:
		THROW_ERROR ( "AddressType must be a valid enum in UDP :: AddressType!" );
		
	}
	
	SocketFD = socket ( Namespace, SOCK_DGRAM, 0 );
	
	if ( SocketFD < 0 )
		THROW_ERROR ( "Couldn't create socket!" );
	
	Target ( "0.0.0.0", 65535 );
	
};

UDPSocket :: ~UDPSocket ()
{
	
	
	
};

void UDPSocket :: Target ( const char * Address, uint16_t Port )
{
	
	SocketSync.Lock ();
	
	this -> Address = Address;
	this -> Port = Port;
	
	switch ( Type )
	{
		
	case UDP :: kAddressType_IPV4:
		
		IPV4Address.sin_family = AF_INET;
		IPV4Address.sin_port = htons ( Port );
		
		inet_pton ( AF_INET, Address, & IPV4Address.sin_addr );
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV4Address );
		AddressSize = sizeof ( IPV4Address );
		
		break;
		
	case UDP :: kAddressType_IPV6:
		
		IPV6Address.sin6_family = AF_INET6;
		IPV6Address.sin6_port = htons ( Port );
		
		inet_pton ( AF_INET6, Address, & IPV6Address.sin6_addr );
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV6Address );
		AddressSize = sizeof ( IPV6Address );
		
		break;
			
	default:
		THROW_ERROR ( "AddressType must be a valid enum in UDP :: AddressType!" );
		
	}
	
	SocketSync.Unlock ();
	
};

uint32_t UDPSocket :: GetWriteCount ()
{
	
	return SendCounter;
	
};

uint32_t UDPSocket :: GetReadCount ()
{
	
	return ReceiveCounter;
	
};

void UDPSocket :: Write ( const void * Buffer, size_t Length, bool DontBlock )
{
	
	SocketSync.Lock ();
	
	if ( sendto ( SocketFD, reinterpret_cast <const char *> ( Buffer ), Length, DontBlock ? MSG_DONTWAIT : 0, SocketAddress, AddressSize ) == - 1 )
	{
		
		switch ( errno )
		{
			
		case EACCES:
			THROW_ERROR ( "Invalid permissions to write to UDP socket!" );
			
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
			
		case EPIPE:
			THROW_ERROR ( "The local end has been shut down on this socket!" );
			
		default:
			THROW_ERROR ( "Unspecified TCP write error!" );
			
		}
		
	}
	
	SendCounter ++;
	
	SocketSync.Unlock ();
	
};

void UDPSocket :: ReadFrom ( char * InAddress, size_t MaxAddressLength, void * Buffer, size_t Length, bool Fill, size_t * Received )
{
	
	struct sockaddr_in IPV4SourceAddress;
	struct sockaddr_in6 IPV6SourceAddress;
	
	struct sockaddr * SourceAddr;
	socklen_t SourceAddrLen;
	
	SocketSync.Lock ();
	
	switch ( Type )
	{
		
	case UDP :: kAddressType_IPV4:
		
		SourceAddr = reinterpret_cast <sockaddr *> ( & IPV4SourceAddress );
		SourceAddrLen = sizeof ( sockaddr_in );
		
		break;
		
	case UDP :: kAddressType_IPV6:
		
		SourceAddr = reinterpret_cast <sockaddr *> ( & IPV6SourceAddress );
		SourceAddrLen = sizeof ( sockaddr_in6 );
		
		break;
		
	}
	
	ssize_t ReceivedBytes;
	
	ReceivedBytes = recvfrom ( SocketFD, Buffer, Length, Fill ? MSG_WAITALL : 0, SourceAddr, & SourceAddrLen );
	
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
	
	ReceiveCounter ++;
	
	if ( Received != NULL )
		* Received = ReceivedBytes;
	
	switch ( Type )
	{
		
	case UDP :: kAddressType_IPV4:
		
		inet_ntop ( AF_INET, SourceAddr, InAddress, MaxAddressLength );
		
		break;
		
	case UDP :: kAddressType_IPV6:
	
		inet_ntop ( AF_INET6, SourceAddr, InAddress, MaxAddressLength );
		
		break;
		
	}
	
	SocketSync.Unlock ();
	
}

void UDPSocket :: Read ( void * Buffer, size_t Length, bool Fill, size_t * Received )
{
	
	SocketSync.Lock ();
	
	ssize_t ReceivedBytes;
	
	ReceivedBytes = recv ( SocketFD, reinterpret_cast <char *> ( Buffer ), Length, Fill ? MSG_WAITALL : 0 );
	
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
	
	ReceiveCounter ++;
	
	if ( Received != NULL )
		* Received = ReceivedBytes;
	
	SocketSync.Unlock ();
	
};

void UDPSocket :: SetUserData ( void * UserData )
{
	
	UserDataSync.Lock ();
	
	this -> UserData = UserData;
	
	UserDataSync.Unlock ();
	
};

void * UDPSocket :: GetUserData ()
{
	
	UserDataSync.Lock ();
	
	void * Data = UserData;
	
	UserDataSync.Unlock ();
	
	return Data;
	
};
