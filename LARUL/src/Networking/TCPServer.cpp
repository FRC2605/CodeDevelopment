#include "TCPServer.h"

TCPServer :: TCPServer ( TCP :: AddressType Type, uint16_t Port ):
	ServerSocketFD ( - 1 ),
	Type ( Type ),
	Port ( Port ),
	DefaultDisconnectionBehavior ( TCPServerSocket :: kDisconnectBehavior_ThrowError ),
	SocketSync ( true ),
	Active ( false )
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
		THROW_ERROR ( "AddressType must be a valid enum in TCP :: AddressType!" );
		
	}
	
	ServerSocketFD = socket ( Namespace, SOCK_STREAM, IPPROTO_TCP );
	
	if ( ServerSocketFD < 0 )
		THROW_ERROR ( "Couldn't create server socket!" );
	
};

TCPServer :: ~TCPServer ()
{
	
	if ( Active )
		Close ();
	
};

void TCPServer :: Open ( int PendableConnections )
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( Active )
		return;
	
	struct sockaddr * SocketAddress;
	size_t AddressSize;
	
	switch ( Type )
	{
		
	case TCP :: kAddressType_IPV4:
	
		IPV4Address.sin_family = AF_INET;
		IPV4Address.sin_port = htons ( Port );
		IPV4Address.sin_addr.s_addr = htonl ( INADDR_ANY );
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV4Address );
		AddressSize = sizeof ( IPV4Address );
		
		break;
		
	case TCP :: kAddressType_IPV6:
	
		IPV6Address.sin6_family = AF_INET6;
		IPV6Address.sin6_port = htons ( Port );
		IPV6Address.sin6_addr = in6addr_any;
		
		SocketAddress = reinterpret_cast <struct sockaddr *> ( & IPV6Address );
		AddressSize = sizeof ( IPV6Address );
		
		break;
		
	}
	
	if ( bind ( ServerSocketFD, SocketAddress, AddressSize ) != 0 )
	{
		
		switch ( errno )
		{
			
		case EACCES:
			THROW_ERROR ( "Access error binding server socket!" );
			
		case EADDRINUSE:
			THROW_ERROR ( "The local server port and address were already in use!" );
			
		default:
			THROW_ERROR ( "Unspecified error binding server socket!" );
			
		}
		
	}
	
	if ( listen ( ServerSocketFD, PendableConnections ) != 0 )
		THROW_ERROR ( "Unspecified error listening for connections on server socket!" );
	
	Active = true;
	
};

TCPServerSocket * TCPServer :: Accept ()
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( ! Active )
		return NULL;
	
	TCPServerSocket * Socket = new TCPServerSocket ( Type, DefaultDisconnectionBehavior );
	
	struct sockaddr SocketAddress;
	socklen_t AddressSize;
	
	int NewSocketFD = accept ( ServerSocketFD, & SocketAddress, &AddressSize );
	
	if ( NewSocketFD < 0 )
	{
		
		switch ( errno )
		{
			
		case ECONNABORTED:
			THROW_ERROR ( "The accepted socket was aborted!" );
			
		case EINTR:
			THROW_ERROR ( "Accepting the socket was interrupted by a signal!" );
			
		case EMFILE:
		case ENFILE:
			THROW_ERROR ( "A file table was full while attempting to accept a socket!" );
			
		case ENOMEM:
			THROW_ERROR ( "Out of memory!" );
			
		default:
			THROW_ERROR ( "An unspecified error was encountered while accepting a socket!" );
			
		}
		
	}
	
	Socket -> SocketFD = NewSocketFD;
	
	switch ( Type )
	{
		
	case TCP :: kAddressType_IPV4:
		
		if ( AddressSize != sizeof ( struct sockaddr_in ) )
			THROW_ERROR ( "Size mismatch on address field in socket and returned address from accept!" );
		
		Socket -> IPV4Address = * reinterpret_cast <sockaddr_in *> ( & SocketAddress );
		
		break;
		
	case TCP :: kAddressType_IPV6:
		
		
		if ( AddressSize != sizeof ( struct sockaddr_in6 ) )
			THROW_ERROR ( "Size mismatch on address field in socket and returned address from accept!" );
		
		Socket -> IPV6Address = * reinterpret_cast <sockaddr_in6 *> ( & SocketAddress );
		
		break;
		
	}
	
	Socket -> Connected = true;
	
	return Socket;
	
};

void TCPServer :: Close ()
{
	
	Synchronized Sync ( & SocketSync );
	
	if ( ! Active )
		return;
	
	Active = false;
	
	if ( close ( ServerSocketFD ) == - 1 )
	{
		
		switch ( errno )
		{
			
		case EINTR:
			THROW_ERROR ( "The server closing was interrupted by a signal!" );
			
		case EIO:
			THROW_ERROR ( "An IO error occured closing the server socket!" );
			
		default:
			THROW_ERROR ( "An unspecified error occured closing the server socket!" );
			
		}
		
	}
	
	ServerSocketFD = - 1;
	
};
