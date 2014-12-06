#ifndef LARUL_UDPSOCKET_H
#define LARUL_UDPSOCKET_H

#include "../Util/Error.h"
#include "../Util/Delegate.h"

#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <unistd.h>

#include "../Threading/Mutex.h"
#include "../Threading/Synchronized.h"

#include "UDP.h"

class UDPSocket
{
public:
	
	UDPSocket ( UDP :: AddressType Type );
	UDPSocket ( UDP :: AddressType Type, uint16_t Port );
	~UDPSocket ();
	
	void Target ( const char * Address, uint16_t Port );
	
	uint32_t GetWriteCount ();
	uint32_t GetReadCount ();
	
	void Write ( const void * Buffer, size_t Length, bool DontBlock = false );
	void Read ( void * Buffer, size_t Length, bool Fill = true, size_t * Received = NULL );
	
	void SetUserData ( void * UserData );
	void * GetUserData ();
	
private:
	
	int SocketFD;
	
	int32_t SendCounter;
	int32_t ReceiveCounter;
	
	struct sockaddr_in IPV4Address;
	struct sockaddr_in6 IPV6Address;
	
	const char * Address;
	uint16_t Port;
	
	bool Bound;
	uint16_t BoundPort;
	
	UDP :: AddressType Type;
	
	Mutex SocketSync;
	Mutex UserDataSync;
	
	void * UserData;
	
};

#endif
