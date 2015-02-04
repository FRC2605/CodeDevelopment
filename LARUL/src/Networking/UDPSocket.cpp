#include "UDPSocket.h"

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
	
};

UDPSocket :: ~UDPSocket ()
{
	
	
	
};

void UDPSocket :: Target ( const char * Address, uint16_t Port )
{
	
	
	
};

uint32_t UDPSocket :: GetWriteCount ()
{
	
	return 0;
	
};

uint32_t UDPSocket :: GetReadCount ()
{
	
	return 0;
	
};

void UDPSocket :: Write ( const void * Buffer, size_t Length, bool DontBlock )
{
	
	
	
};

void UDPSocket :: Read ( void * Buffer, size_t Length, bool Fill, size_t * Received )
{
	
	
	
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
