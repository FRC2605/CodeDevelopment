#include "Condition.h"

Condition :: Condition ( bool Persistant, bool ProcessShared ):
	LockingMutex (),
	Persistant ( Persistant ),
	Set ( false )
{
	
	int ErrorCode = pthread_condattr_init ( & ConditionAttributes );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case ENOMEM:
		THROW_ERROR ( "Insufficient memory to create condition attribute object!" );
	
	default:
		THROW_ERROR ( "Unspecified error creating condition attribute object!" );
	
	}
	
	if ( pthread_condattr_setpshared ( & ConditionAttributes, ProcessShared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE ) != 0 )
		THROW_ERROR ( "Unspecified error setting process shared attribute of condition attribute object!" );
	
	ErrorCode = pthread_cond_init ( & ConditionHandle, & ConditionAttributes );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case EAGAIN:
		THROW_ERROR ( "Insufficient system resources to initialize condition object!" );
		
	case ENOMEM:
		THROW_ERROR ( "Insufficient memory to initialize condition object!" );
		
	default:
		THROW_ERROR ( "Unspecified error initializing condition object!" );
		
	};
	
};

Condition :: ~Condition ()
{
	
	int ErrorCode = pthread_condattr_destroy ( & ConditionAttributes );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	default:
		THROW_ERROR ( "Unspecified error destroying condition attribute object!" );
		
	}
	
	ErrorCode = pthread_cond_destroy ( & ConditionHandle );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case EBUSY:
		THROW_ERROR ( "Attempt to destroy condition while it was being waited on!" );
		
	default:
		THROW_ERROR ( "Unspecified error destroying condition object!" );
		
	}
	
};

void Condition :: Lock ()
{
	
	LockingMutex.Lock ();
	
};

void Condition :: Unlock ()
{
	
	LockingMutex.Unlock ();
	
};

void Condition :: Signal ()
{
	
	LockingMutex.Lock ();
	
	if ( pthread_cond_signal ( & ConditionHandle ) != 0 )
		THROW_ERROR ( "Unspecified error locking condition!" );
	
	Set = true;
	
	LockingMutex.Unlock ();
	
};

void Condition :: Broadcast ()
{
	
	LockingMutex.Lock ();
	
	if ( pthread_cond_broadcast ( & ConditionHandle ) != 0 )
		THROW_ERROR ( "Unspecified error locking condition!" );
	
	Set = true;
	
	LockingMutex.Unlock ();
	
};

void Condition :: Reset ()
{
	
	LockingMutex.Lock ();
	
	Set = false;
	
	LockingMutex.Unlock ();
	
};

void Condition :: Wait ()
{
	
	LockingMutex.Lock ();
	
	if ( Set && Persistant )
		return;
	
	int ErrorCode = pthread_cond_wait ( & ConditionHandle, & LockingMutex.MutexHandle );
	
	switch ( ErrorCode )
	{
		
	case 0:	
		break;
		
	default:
		THROW_ERROR ( "Unspecified error waiting on condition!" );
		
	};
	
	LockingMutex.Unlock ();
	
};

bool Condition :: TimedWait ( double Seconds )
{
	
	LockingMutex.Lock ();
	
	if ( Set && Persistant )
		return true;
	
	struct timespec Time;
	int ErrorCode;
	
#if _POSIX_TIMERS > 0
	
	clockid_t Clock;
	
	ErrorCode = pthread_getcpuclockid ( pthread_self (), & Clock );
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified error getting thread clock ID for condition timed wait!" );
	
	ErrorCode = clock_getttime ( Clock, & Time );
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified error getting time for condition timed wait!" );

#else
	
	/* Note: This solution is vounerable to NTP jumps and should probably be fixed at some point.
	* On any real target of LARUL, posix timers are expected to be implemented, but we have this
	* here for development purposes.
	*/
	
	struct timeval TimeV;
	
	if ( gettimeofday ( & TimeV, NULL ) == -1 )
		THROW_ERROR ( "Unspecified error getting time for condition timed wait!" );
	
	Time.tv_nsec = TimeV.tv_usec * 1000;
	Time.tv_sec = TimeV.tv_sec;
	
#endif
	
	Time.tv_sec += Seconds;
	Seconds -= (uint64_t) Seconds;
	
	Time.tv_nsec = Seconds * 1000000000L;
	
	ErrorCode = pthread_cond_timedwait ( & ConditionHandle, & LockingMutex.MutexHandle, & Time );
	
	switch ( ErrorCode )
	{
		
	case 0:	
		break;
		
	case ETIMEDOUT:
		return false;
		
	case EINVAL:
		THROW_ERROR ( "Invalid time specified to condition timed wait!" );
		
	default:
		THROW_ERROR ( "Unspecified error waiting on condition!" );
		
	};
	
	LockingMutex.Unlock ();
	
	return true;
	
};
