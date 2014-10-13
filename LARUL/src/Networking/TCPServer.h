#ifndef LARUL_TCPSERVER_H
#define LARUL_TCPSERVER_H

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

#include "TCPServerSocket.h"

#include "TCP.h"

class TCPServer
{
public:
	
	TCPServer ( TCP :: AddressType Type, uint16_t Port );
	~TCPServer ();
	
	TCPServerSocket * Accept ();
	
	void Open ( int PendableConnections = 1024 );
	void Close ();
	
private:
	
	int ServerSocketFD;
	
	struct sockaddr_in IPV4Address;
	struct sockaddr_in6 IPV6Address;
	
	TCP :: AddressType Type;
	
	TCPServerSocket :: DisconnectBehavior DefaultDisconnectionBehavior;
	
	uint16_t Port;
	
	Mutex SocketSync;
	
	bool Active;
	
};

#endif
