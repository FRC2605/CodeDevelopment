#include "MessageQueue.h"

MessageQueue :: MessageQueue ( uint32_t MaxSlots ):
	QueueLength ( MaxSlots ),
	Offset ( 0 ),
	Length ( 0 ),
	Availible ( true ),
	Open ( true ),
	QueueSync ( true )
{
	
	Messages = reinterpret_cast <void **> ( malloc ( sizeof ( void * ) * MaxSlots ) );
	
	if ( Messages == NULL )
		THROW_ERROR ( "Failed to allocate message buffer!" );
	
};

MessageQueue :: ~MessageQueue ()
{
	
	free ( Messages );
	
};

void MessageQueue :: SendMessage ( void * Message, bool Preemt )
{
	
	QueueSync.Lock ();
	
	if ( Length == QueueLength )
	{
		
		QueueSync.Unlock ();
		
		Open.Wait ();
		
		QueueSync.Lock ();
		
		if ( Preemt )
		{
			
			for ( uint32_t i = 0; i < Length; i ++ )
				Messages [ ( Offset - Length - 1 + i ) % QueueLength ] = Messages [ ( Offset - Length + i ) % QueueLength ];
			
			Messages [ Offset ] = Message;
			
		}
		else
		{
			
			Messages [ ( Offset + Length ) % QueueLength ] = Message;
			Offset = ( Offset + 1 ) % QueueLength;
			
		}
		
		Length ++;
		
		QueueSync.Unlock ();
		
		Availible.Signal ();
		
	}
	else
	{
		
		if ( Preemt )
		{
			
			Offset = ( Offset - 1 ) % QueueLength;
			Messages [ Offset ] = Messages;
			
		}
		else
			Messages [ ( Offset - Length ) % QueueLength ] = Message;
		
		Length ++;
		
		QueueSync.Unlock ();
		
		Availible.Signal ();
		
	}
	
};

bool MessageQueue :: TrySendMessage ( void * Message, double Timeout, bool Preemt )
{
	
	QueueSync.Lock ();
	
	if ( Length == QueueLength )
	{
		
		QueueSync.Unlock ();
		
		if ( ! Open.TimedWait ( Timeout ) )
		{
			
			return false;
			
		}
		
		QueueSync.Lock ();
		
		if ( Preemt )
		{
			
			Offset = ( Offset - 1 ) % QueueLength;
			Messages [ Offset ] = Messages;
			
		}
		else
		{
			
			Messages [ ( Offset + Length ) % QueueLength ] = Message;
			Offset = ( Offset + 1 ) % QueueLength;
			
		}
		
		Length ++;
		
		QueueSync.Unlock ();
		
		Availible.Signal ();
		
	}
	else
	{
		
		if ( Preemt )
		{
			
			for ( uint32_t i = 0; i < Length; i ++ )
				Messages [ ( Offset - Length - 1 + i ) % QueueLength ] = Messages [ ( Offset - Length + i ) % QueueLength ];
			
			Messages [ Offset ] = Message;
			
		}
		else
			Messages [ ( Offset - Length ) % QueueLength ] = Message;
		
		Length ++;
		
		QueueSync.Unlock ();
		
		Availible.Signal ();
		
	}
	
	return true;
	
};

void MessageQueue :: ReceiveMessage ( void ** Message )
{
	
	QueueSync.Lock ();
	
	if ( Length == 0 )
	{
		
		QueueSync.Unlock ();
		
		Availible.LockWait ();
		
		QueueSync.Lock ();
		
		* Message = Messages [ Offset ];
		Offset = ( Offset + 1 ) % QueueLength;
		
	}
	else
	{
		
		* Message = Messages [ Offset ];
		Offset = ( Offset + 1 ) % QueueLength;
		
	}
	
	Length --;
	
	if ( Length == 0 )
		Availible.Reset ();
	
	QueueSync.Unlock ();
	
	Availible.Unlock ();
	
};

bool MessageQueue :: TryReceiveMessage ( void ** Message, double Timeout )
{
	
	QueueSync.Lock ();
	
	if ( Length == 0 )
	{
		
		QueueSync.Unlock ();
		
		if ( ! Availible.TimedLockWait ( Timeout ) )
		{
			
			Availible.Unlock ();
			
			return false;
			
		}
		
		QueueSync.Lock ();
		
		* Message = Messages [ Offset ];
		Offset = ( Offset + 1 ) % QueueLength;
		
		Length --;
		
		if ( Length == 0 )
			Availible.Reset ();
		
		Availible.Unlock ();
		
	}
	else
	{
		
		* Message = Messages [ Offset ];
		Offset = ( Offset + 1 ) % QueueLength;
		
		Length --;
		
		if ( Length == 0 )
			Availible.Reset ();
		
	}
	
	QueueSync.Unlock ();
	
	return true;
	
};
