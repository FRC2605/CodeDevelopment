#ifndef LARUL_MESSAGEQUEUE_H
#define LARUL_MESSAGEQUEUE_H

#include <stdint.h>
#include <stdlib.h>

#include "Condition.h"
#include "Mutex.h"

#include "../Util/Error.h"

class MessageQueue
{
public:
	
	explicit MessageQueue ( uint32_t MaxSlots );
	~MessageQueue ();
	
	void SendMessage ( void * Message, bool Preemt = false );
	bool TrySendMessage ( void * Message, double Timeout, bool Preemt = false );
	
	void ReceiveMessage ( void ** Message );
	bool TryReceiveMessage ( void ** Message, double Timeout );
	
	void PeekMessage ( void ** Message );
	bool TryPeekMessage ( void ** Message, double Timeout );
	
private:
	
	uint32_t QueueLength;
	
	uint32_t Offset;
	uint32_t Length;
	
	void ** Messages;
	
	Condition Availible;
	Condition Open;
	Mutex QueueSync;
	
};

#endif
