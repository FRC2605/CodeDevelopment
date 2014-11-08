#include "MessageQueue.h"

MessageQueue :: MessageQueue ( uint32_t MaxSlots ):
	QueueLength ( MaxSlots ),
	Offset ( 0 ),
	Length ( 0 ),
	Availible (),
	Open ( true ),
	QueueSync ( true )
{
	
	Messages = reinterpret_cast <void **> ( malloc ( sizeof ( void * ) * static_cast <size_t> ( MaxSlots ) ) );
	
	if ( Messages == NULL )
		THROW_ERROR ( "Failed to allocate message buffer!" );
	
};

MessageQueue :: ~MessageQueue ()
{
	
	free ( Messages );
	
};

void MessageQueue :: SendMessage ( void * Message, bool Preemt )
{
	
	// Make sure that there's a slot for the message
	Open.LockWait ();
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	if ( Preemt )
	{
		
		if ( Offset == 0 )
			Offset = QueueLength;
		
		Offset --;
		
		Messages [ Offset ] = Message;
		
	}
	else
	{
		
		Messages [ ( Offset + Length ) % QueueLength ] = Message;
		
	}
	
	// Signal that messages are available
	if ( Length == 0 )
		Availible.Broadcast ();
	
	Length ++;
	
	// Reset Open if there are no empty spaces
	if ( Length == QueueLength )
		Open.Reset ();
	
	// Allow others to send
	Open.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
};

bool MessageQueue :: TrySendMessage ( void * Message, double Timeout, bool Preemt )
{
	
	// Try to find an open slot for the message. If nothing's open by the timeout, return a failure.
	if ( ! Open.TimedLockWait ( Timeout ) )
	{
		
		Open.Unlock ();
		
		return false;
		
	}
	
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	if ( Preemt )
	{
		
		if ( Offset == 0 )
			Offset = QueueLength;
		
		Offset --;
		
		Messages [ Offset ] = Message;
		
	}
	else
	{
		
		Messages [ ( Offset + Length ) % QueueLength ] = Message;
		
	}
	
	// Signal that messages are available
	if ( Length == 0 )
		Availible.Broadcast ();
	
	Length ++;
	
	// Reset Open if there are no empty spaces
	if ( Length == QueueLength )
		Open.Reset ();
	
	// Allow others to send
	Open.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
	return true;
	
};

void MessageQueue :: ReceiveMessage ( void ** Message )
{
	
	// Make sure there's at least one message
	Availible.LockWait ();
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	// Get the message.
	* Message = Messages [ Offset ];
	Offset ++;
	
	if ( Offset == QueueLength )
		Offset = 0;
	
	// If the queue was previousley not open, open it up
	if ( Length == QueueLength )
		Open.Broadcast ();
	
	Length --;
	
	// Reset availible if there are no longer any messages
	if ( Length == 0 )
		Availible.Reset ();
	
	//  Allow others to receive
	Availible.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
};

bool MessageQueue :: TryReceiveMessage ( void ** Message, double Timeout )
{
	
	// Attempt to receive a message. If nothing's availible by the timeout, return a failure.
	if ( ! Availible.TimedLockWait ( Timeout ) )
	{
		
		Availible.Unlock ();
		
		return false;
		
	}
	
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	// Get the message.
	* Message = Messages [ Offset ];
	Offset ++;
	
	if ( Offset == QueueLength )
		Offset = 0;
	
	// If the queue was previousley not open, open it up
	if ( Length == QueueLength )
		Open.Broadcast ();
	
	Length --;
	
	// Reset availible if there are no longer any messages
	if ( Length == 0 )
		Availible.Reset ();
	
	//  Allow others to receive
	Availible.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
	return true;
	
};

void MessageQueue :: PeekMessage ( void ** Message )
{
	
	// Make sure there's at least one message
	Availible.LockWait ();
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	// Get the message.
	* Message = Messages [ Offset ];
	
	//  Allow others to receive
	Availible.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
};

bool MessageQueue :: TryPeekMessage ( void ** Message, double Timeout )
{
	
	// Attempt to see a message. If nothing's availible by the timeout, return a failure.
	if ( ! Availible.TimedLockWait ( Timeout ) )
	{
		
		Availible.Unlock ();
		
		return false;
		
	}
	
	// Make sure we're the only ones touching the queue
	QueueSync.Lock ();
	
	// Get the message.
	* Message = Messages [ Offset ];
	
	//  Allow others to receive
	Availible.Unlock ();
	// Allow further queue operation
	QueueSync.Unlock ();
	
	return true;
	
};
