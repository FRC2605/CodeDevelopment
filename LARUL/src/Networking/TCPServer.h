#ifndef LARUL_TCPSERVER_H
#define LARUL_TCPSERVER_H

#include <arpa/inet.h>

#ifdef __VXWORKS__
	#include <inetLib.h>
#endif

#include "../Util/LError.h"
#include "../Util/Delegate.h"

#include "../Threading/Mutex.h"

#include "TCPServerSocket.h"

#include "TCP.h"

/*
* TCPServer is a server socket that listens for connections TCP. it is implemented with POSIX sockets.
*/

class TCPServer
{
public:
	
	// Address type of the server and server port
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
