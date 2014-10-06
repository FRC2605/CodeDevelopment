#include "Timer.h"

Timer :: Timer ( TimeMode Mode ):
	Time ( 0 ),
	Offset ( 0 ),
	Running ( false ),
	Mode ( Mode ),
	SyncMutex ( true )
{
};

Timer :: ~Timer ()
{
};

void Timer :: Start ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	if ( Running )
		return;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Offset = GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Offset = GetTimeSystemMS ();
		
		break;
		
	}
	
	Running = true;
	
};

void Timer :: Stop ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = GetTimeSystemMS ();
		
		break;
		
	}
	
	if ( ! Running )
		return;
	
	Offset = Current - Offset;
	Time += Offset;
	
	Running = false;
	
};

void Timer :: Reset ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	Running = false;
	Time = 0;
	
};

void Timer :: Restart ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	Running = false;
	Time = 0;
	
	Start ();
	
};


double Timer :: GetTimeMS ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	return (double) Current;
	
};

double Timer :: GetTimeS ()
{
	
	Synchronized Sync ( & SyncMutex );
	
	uint64_t Current;
	
	switch ( Mode )
	{
		
	case kTimeMode_Monotonic:
	
		Current = GetTimeMonotonicMS ();
		
		break;
	
	case kTimeMode_System:
	
		Current = GetTimeSystemMS ();
		
		break;
		
	}
	
	Current = Current - Offset;
	Current += Time;
	
	return ( (double) Current ) / 1000.0;
	
};

void Timer :: SetTimeMode ( TimeMode Mode )
{
	
	Synchronized Sync ( & SyncMutex );
	
	bool Resume = Running;
	
	Stop ();
	
	this -> Mode = Mode;
	
	if ( Resume )
		Start ();
	
};

uint64_t Timer :: GetTimeMonotonicMS ()
{
	
	uint64_t TimeMS;
	
#ifdef _POSIX_TIMERS
	
	struct timespec Time;
	clock_getttime ( CLOCK_MONOTONIC, & Time );
	
	struct tm * TimeInfo;
	tm = localtime ( & Time );
	
	TimeMS = Time.tv_nsec / 1000;
	TimeMS += TimeInfo.tm_sec * 1000;
	TimeMS += TimeInfo.tm_min * 60000;
	TimeMS += TimeInfo.tm_hour * 3600000;
	TimeMS += TimeInfo.tm_mday * 86400000;
	
#else
	
	/* Note: This solution is vounerable to NTP jumps and should probably be fixed at some point.
	* On any real target of LARUL, posix timers are expected to be implemented, but we have this
	* here for development purposes. This is not monotonic.
	*/
	
	// TODO: test for and implement platform specific monotoinc clocks.
	
	struct timeval TimeV;
	
	if ( gettimeofday ( & TimeV, NULL ) == -1 )
		THROW_ERROR ( "Unspecified error getting time!" );
	
	TimeMS = TimeV.tv_usec / 1000;
	TimeMS += TimeV.tv_sec * 1000;
	
#endif
	
	return TimeMS;
	
};

uint64_t Timer :: GetTimeSystemMS ()
{
	
	uint64_t TimeMS;
	
#ifdef _POSIX_TIMERS
	
	struct timespec Time;
	clock_getttime ( CLOCK_REALTIME, & Time );
	
	struct tm * TimeInfo;
	tm = localtime ( & Time );
	
	TimeMS = Time.tv_nsec / 1000;
	TimeMS += TimeInfo.tm_sec * 1000;
	TimeMS += TimeInfo.tm_min * 60000;
	TimeMS += TimeInfo.tm_hour * 3600000;
	TimeMS += TimeInfo.tm_mday * 86400000;
	
#else
	
	struct timeval TimeV;
	
	if ( gettimeofday ( & TimeV, NULL ) == -1 )
		THROW_ERROR ( "Unspecified error getting time!" );
	
	TimeMS = TimeV.tv_usec / 1000;
	TimeMS += TimeV.tv_sec * 1000;
	
#endif
	
	return TimeMS;
	
};
