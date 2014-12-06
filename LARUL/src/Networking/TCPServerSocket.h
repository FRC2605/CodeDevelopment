#ifndef LARUL_TCPSERVERSOCKET_H
#define LARUL_TCPSERVERSOCKET_H

#include <arpa/inet.h>

#ifdef __VXWORKS__
	#include <inetLib.h>
#endif

#include "../Util/LError.h"
#include "../Util/Delegate.h"

#include "../Threading/Mutex.h"

#include "TCP.h"

class TCPServer;

class TCPServerSocket
{
public:
	
	typedef enum
	{
		
		kDisconnectBehavior_SilentError,
		kDisconnectBehavior_FailureCallback,
		kDisconnectBehavior_ThrowError
		
	} DisconnectBehavior;
	
	~TCPServerSocket ();
	
	void SetDisconnectionCallback ( IDelegate1 <void, TCPServerSocket *> * Callback );
	
	void Disconnect ( bool Callback );
	
	void Write ( const void * Buffer, size_t Length, bool DontBlock = false );
	void Read ( void * Buffer, size_t Length, bool Fill = true, size_t * Received = NULL, bool * Closed = NULL );
	
	void SetUserData ( void * UserData );
	void * GetUserData ();
	
private:
	
	TCPServerSocket ( TCP :: AddressType Type, DisconnectBehavior Behavior );
	
	TCP :: AddressType Type;
	DisconnectBehavior Disconnection;
	
	IDelegate1 <void, TCPServerSocket *> * DisconnectCallback;
	
	Mutex UserDataSync;
	void * UserData;
	
	int32_t SendCounter;
	int32_t ReceiveCounter;
	
	int SocketFD;
	
	struct sockaddr_in IPV4Address;
	struct sockaddr_in6 IPV6Address;
	
	Mutex SocketSync;
	
	bool Connected;
	
	friend class TCPServer;
	
};

#endif
