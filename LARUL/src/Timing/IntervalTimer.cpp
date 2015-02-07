#include "IntervalTimer.h"

IntervalTimer :: IntervalTimer ( TimeMode Mode ):
	Time ( 0 ),
	Offset ( 0 ),
	Running ( false ),
	Mode ( Mode ),
	SyncMutex ( true )
{
};

IntervalTimer :: ~IntervalTimer ()
{
};

void IntervalTimer :: Start ()
{
	
	SyncMutex.Lock ();
	
	if ( Running )
		return;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Offset = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Offset = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Running = true;
	
	SyncMutex.Unlock ();
	
};

void IntervalTimer :: Stop ()
{
	
	SyncMutex.Lock ();
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	if ( ! Running )
		return;
	
	Offset = Current - Offset;
	Time += Offset;
	
	Running = false;
	
	SyncMutex.Unlock ();
	
};

void IntervalTimer :: Reset ()
{
	
	SyncMutex.Lock ();
	
	Running = false;
	Time = 0;
	
	SyncMutex.Unlock ();
	
};

void IntervalTimer :: Restart ()
{
	
	SyncMutex.Lock ();
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Time = 0.0;
	Running = true;
	
};

double IntervalTimer :: GetTimeMS ()
{
	
	SyncMutex.Lock ();
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	SyncMutex.Unlock ();
	
	return (double) Current;
	
};

double IntervalTimer :: GetTimeS ()
{
	
	SyncMutex.Lock ();
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	SyncMutex.Unlock ();
	
	return ( (double) Current ) / 1000.0;
	
};

void IntervalTimer :: SetTimeMode ( TimeMode Mode )
{
	
	SyncMutex.Lock ();
	
	bool Resume = Running;
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = Clock :: GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = Clock :: GetTimeSystemMS ();
		
		break;
		
	}
	
	if ( ! Running )
		return;
	
	Offset = Current - Offset;
	Time += Offset;
	
	Running = false;
	
	this -> Mode = Mode;
	
	if ( Resume )
	{
		
		switch ( Mode )
		{
			
		case kTimeMode_Monotonic:
		
			Offset = Clock :: GetTimeMonotonicMS ();
			
			break;
		
		case kTimeMode_System:
		
			Offset = Clock :: GetTimeSystemMS ();
			
			break;
			
		}
		
		Running = true;
	
	}
	
	SyncMutex.Unlock ();
	
};
