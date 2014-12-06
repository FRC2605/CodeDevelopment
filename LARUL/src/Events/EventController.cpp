#include "EventController.h"

volatile const int EventController :: AREF_PAUSE = 0x01;
volatile const int EventController :: AREF_PAUSE_AND_DISCARD = 0x02;
volatile const int EventController :: AREF_RESUME = 0x03;
volatile const int EventController :: AREF_KILL = 0x04;

EventController :: EventController ():
	EventSync (),
	StateSync (),
	InsertionQueue ( 64 ),
	StateChange (),
	MessageAllocSpec (),
	MessageAlloc ( & MessageAllocSpec, 64, 64 ),
	NextEventMS ( 0 ),
	NextEvent ( NULL ),
	ScheduleList (),
	State ( kControllerState_Dead ),
	RunningPointer ( NULL ),
	RunLoopThread ( NULL )
{
};

EventController :: ~EventController ()
{
	
	if ( State != kControllerState_Dead )
		InsertionQueue.SendMessage ( static_cast <void *> ( const_cast <int *> ( & AREF_KILL ) ), true );
	
};

void EventController :: RunLoop ()
{
	
	bool Running = true;
	bool EventWait;
	void * Message;
	
	RunLoopThread = Thread :: GetCurrentThread ();
	RunningPointer = & Running;
	
	StateSync.Lock ();
	State = kControllerState_Running;
	StateSync.Unlock ();
	
	InsertionQueue.ReceiveMessage ( & Message );
	
	do
	{
		
		if ( Message == reinterpret_cast <void *> ( const_cast <int *> ( & AREF_KILL ) ) )
		{
			
			Running = false;
			EventWait = false;
			
			StateSync.Lock ();
			State = kControllerState_Dead;
			StateSync.Unlock ();
			
			StateChange.Signal ();
			
		}
		else if ( reinterpret_cast <void *> ( const_cast <int *> ( & AREF_PAUSE ) ) )
		{
			
			StateSync.Lock ();
			State = kControllerState_Paused;
			StateSync.Unlock ();
			
			StateChange.Signal ();
			
			InsertionQueue.ReceiveMessage ( & Message );
			EventWait = false;
			
		}
		else if ( Message == reinterpret_cast <void *> ( const_cast <int *> ( & AREF_PAUSE_AND_DISCARD ) ) )
		{
			
			StateSync.Lock ();
			State = kControllerState_Paused;
			StateSync.Unlock ();
			
			StateChange.Signal ();
			
			ScheduleList.Clear ();
			
			InsertionQueue.ReceiveMessage ( & Message );
			EventWait = false;
			
		}
		else if ( Message == reinterpret_cast <void *> ( const_cast <int *> ( & AREF_RESUME ) ) )
		{
			
			StateSync.Lock ();
			State = kControllerState_Running;
			StateSync.Unlock ();
			
			StateChange.Signal ();
		
			if ( ScheduleList.Length () != 0 )
			{
				
				bool WaitReceive = false;
				
				while ( ! WaitReceive && ScheduleList.Length () != 0 )
				{
					
					ScheduleRecord Record = ScheduleList [ 0 ];
				
					uint64_t CurrentTime = Clock :: GetTimeMonotonicMS ();
					
					if ( Record.TimeMS <= CurrentTime )
					{
						
						NextEvent = FindEvent ( Record.Type );
						
						if ( NextEvent != NULL )
						{
							
							NextEvent -> Trigger ();
							NextEvent = NULL;
							
						}
						
						if ( ScheduleList [ 0 ].DeallocTypeString )
							free ( ScheduleList [ 0 ].Type );
						
						ScheduleList.Shift ();
						
					}
					else
					{
					
						NextEventMS = Record.TimeMS;
						NextEvent = FindEvent ( Record.Type );
						
						if ( NextEvent != NULL )
							WaitReceive = true;
						
					}
					
				}
				
				if ( NextEvent != NULL )
					EventWait = true;
				else
				{
					
					InsertionQueue.ReceiveMessage ( & Message );
					
					EventWait = false;
					
				}
				
			}
			else
			{
				
				InsertionQueue.ReceiveMessage ( & Message );
				
				EventWait = false;
				
			}
			
		}
		else
		{
			
			ScheduleRecord Temporary;
			
			Temporary.TimeMS = reinterpret_cast <ScheduleRecord *> ( Message ) -> TimeMS;
			Temporary.Type = reinterpret_cast <ScheduleRecord *> ( Message ) -> Type;
			Temporary.DeallocTypeString = reinterpret_cast <ScheduleRecord *> ( Message ) -> DeallocTypeString;
			
		}
		
		if ( EventWait )
		{
			
			uint64_t CurrentTime = Clock :: GetTimeMonotonicMS ();
			uint64_t Delta = NextEventMS - CurrentTime;
			
			if ( NextEventMS < CurrentTime )
				Delta = 0;
			
			while ( ! InsertionQueue.TryReceiveMessage ( & Message, static_cast <double> ( Delta ) / 1000 ) )
			{
				
				if ( ScheduleList [ 0 ].DeallocTypeString )
					free ( ScheduleList [ 0 ].Type );
				
				ScheduleList.Shift ();
				
				NextEvent -> Trigger ();
				NextEvent = NULL;
				
				if ( ScheduleList.Length () != 0 )
				{
					
					NextEvent = FindEvent ( ScheduleList [ 0 ].Type );
					NextEventMS = ScheduleList [ 0 ].TimeMS;
					
					CurrentTime = Clock :: GetTimeMonotonicMS ();
					Delta = NextEventMS - CurrentTime;
					
				}
				else
					break;
				
			}
			
		}
		
	}
	while ( Running );
	
	while ( ScheduleList.Length () != 0 )
	{
		
		ScheduleRecord Record = ScheduleList.Shift ();
		
		if ( Record.DeallocTypeString )
			free ( Record.Type );
		
	}
	
};

void EventController :: KillRunLoop ()
{
	
	if ( Thread :: GetCurrentThread () == RunLoopThread )
	{
		
		* RunningPointer = false;
		
		return;
		
	}
	
	InsertionQueue.SendMessage ( static_cast <void *> ( const_cast <int *> ( & AREF_KILL ) ), true );
	
	StateChange.LockWait ();
	StateChange.Reset ();
	StateChange.Unlock ();
	
};

void EventController :: PauseRunLoop ( bool DiscardSchedule )
{
	
	if ( DiscardSchedule )
		InsertionQueue.SendMessage ( static_cast <void *> ( const_cast <int *> ( & AREF_PAUSE_AND_DISCARD ) ), true );
	else
		InsertionQueue.SendMessage ( static_cast <void *> ( const_cast <int *> ( & AREF_PAUSE ) ), true );
	
	StateChange.LockWait ();
	StateChange.Reset ();
	StateChange.Unlock ();
	
};

void EventController :: ResumeRunLoop ()
{
	
	InsertionQueue.SendMessage ( static_cast <void *> ( const_cast <int *> ( & AREF_RESUME ) ) );
	
	StateChange.LockWait ();
	StateChange.Reset ();
	StateChange.Unlock ();
	
};

EventController :: ControllerState EventController :: GetState ()
{
	
	StateSync.Lock ();
	ControllerState LocalState = State;
	StateSync.Unlock ();
	
	return LocalState;
	
};

void EventController :: AddEvent ( IEvent * Event )
{
	
	EventSync.Lock ();
	
	Events.Push ( Event );
	
	EventSync.Unlock ();
	
};

void EventController :: RemoveEvent ( IEvent * Event )
{
	
	EventSync.Lock ();
	
	int32_t Index = Events.IndexOf ( Event );
	
	if ( Index != -1 )
		Events.Remove ( Index, 1 );
		
	EventSync.Unlock ();
	
};

void EventController :: ScheduleEvent ( const char * Type, uint64_t Time )
{
	
	
	
};
