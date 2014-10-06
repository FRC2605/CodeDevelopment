#ifndef LARUL_TCPSOCKET_H
#define LARUL_TCPSOCKET_H

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

/* TCPSocket: Just a plain old TCP socket implemented using berkley sockets.
*/

class TCPSocket
{
public:
	
	typedef enum
	{
		
		kAddressType_IPV4 = 1,
		kAddressType_IPV6 = 2
		
	} AddressType;
	
	typedef enum
	{
		
		kDisconnectBehavior_SilentError,
		kDisconnectBehavior_FailureCallback,
		kDisconnectBehavior_ThrowError,
		kDisconnectBehavior_SpinReconnect
		
	} DisconnectBehavior;
	
	TCPSocket ( AddressType Type, DisconnectBehavior Disconnection );
	TCPSocket ( AddressType Type, DisconnectBehavior Disconnection, uint16_t Port );
	~TCPSocket ();
	
	void SetDisconnectionCallback ( IDelegate1 <void, TCPSocket *> * Callback );
	
	void Connect ( const char * Address, uint16_t Port );
	void Disconnect ( bool Callback = false );
	
	bool IsConnected ();
	
	uint32_t GetWriteCount ();
	uint32_t GetReadCount ();
	
	void Write ( const void * Buffer, size_t Length, bool DontBlock = false );
	void Read ( void * Buffer, size_t Length, bool Fill = true, size_t * Received = NULL, bool * Closed = NULL );
	
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
	
	AddressType Type;
	DisconnectBehavior Disconnection;
	
	IDelegate1 <void, TCPSocket *> * DisconnectCallback;
	
	bool Connected;
	
	Mutex SyncMutex;
	
};

#endif
