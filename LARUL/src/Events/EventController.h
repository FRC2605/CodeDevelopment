#ifndef LARUL_EVENTCONTROLLER_H
#define LARUL_EVENTCONTROLLER_H

#include "../Threading/Mutex.h"
#include "../Threading/Condition.h"
#include "../Threading/MessageQueue.h"

#include "../Timing/Timer.h"

#include "../Util/Vector.h"

#include "IEvent.h"

class EventController
{
public:
	
	typedef enum
	{
		
		kControllerState_Running,
		kControllerState_Paused,
		kControllerState_Dead
		
	} ControllerState;
	
	EventController ();
	~EventController ();
	
	void RunLoop ();
	
	void KillRunLoop ();
	void PauseRunLoop ( bool DiscardSchedule = true );
	void ResumeRunLoop ();
	
	ControllerState GetState ();
	
	void AddEvent ( IEvent * Event );
	void RemoveEvent ( IEvent * Event );
	
	void ScheduleEvent ( const char * Type, uint64_t Time );
	
private:
	
	static volatile const int AREF_PAUSE;
	static volatile const int AREF_PAUSE_AND_DISCARD;
	static volatile const int AREF_RESUME;
	static volatile const int AREF_KILL;
	
	typedef struct
	{
		
		const char * Type;
		uint64_t TimeMS;
		bool DeallocTypeString;
		
	} ScheduleRecord;
	
	IEvent * FindEvent ( const char * Type );
	
	Mutex EventSync;
	Mutex StateSync;
	MessageQueue InsertionQueue;
	Condition StateChange;
	
	SingleAllocSpec <ScheduleRecord> MessageAllocSpec;
	CachingAllocator MessageAlloc;
	
	uint64_t NextEventMS;
	IEvent * NextEvent;
	
	Vector <ScheduleRecord> ScheduleList;
	
	Vector.<IEvent> Events;
	
	ControllerState State;
	
	bool * RunningPointer;
	
	Thread * RunLoopThread;
	
};

#endif
