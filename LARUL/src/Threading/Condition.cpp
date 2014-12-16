#include "Condition.h"

#include <sys/types.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>

#ifdef __VXWORKS__
	#include <timers.h>
#else
	#include <sys/time.h>
#endif

Condition :: Condition ( bool InitiallySet, bool ProcessShared ):
	LockingMutex (),
	PreLockedSync (),
	PreLocked ( false ),
	Set ( InitiallySet ),
	Waiters ( 0 )
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
	
#ifdef  PTHREAD_PROCESS_SHARED
	if ( pthread_condattr_setpshared ( & ConditionAttributes, ProcessShared ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE ) != 0 )
		THROW_ERROR ( "Unspecified error setting process shared attribute of condition attribute object!" );
#endif
	
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

void Condition :: Unlock ()
{
	
	LockingMutex.Unlock ();
	
};

void Condition :: PreLock ()
{
	
	LockingMutex.Lock ();
	
	PreLocked = true;
	
};

void Condition :: Signal ()
{
	
	LockingMutex.Lock ();
	
	Set = true;
	
	if ( Waiters == 0 )
	{
		
		LockingMutex.Unlock ();
		
		return;
		
	}
	
	LockingMutex.Unlock ();
	
	if ( pthread_cond_signal ( & ConditionHandle ) != 0 )
		THROW_ERROR ( "Unspecified error locking condition!" );
	
};

void Condition :: Broadcast ()
{
	
	LockingMutex.Lock ();
	
	Set = true;
	
	if ( Waiters == 0 )
	{
		
		LockingMutex.Unlock ();
		
		return;
		
	}
	
	LockingMutex.Unlock ();
	
	if ( pthread_cond_broadcast ( & ConditionHandle ) != 0 )
		THROW_ERROR ( "Unspecified error locking condition!" );
	
};

void Condition :: Reset ()
{
	
	Set = false;
	
};

void Condition :: Wait ()
{
	
	if ( ! PreLocked )
		LockingMutex.Lock ();
	
	Waiters ++;
	
	while ( ! Set )
	{
		
		int ErrorCode = pthread_cond_wait ( & ConditionHandle, & LockingMutex.MutexHandle );
		
		switch ( ErrorCode )
		{
			
		case 0:	
			break;
			
		default:
		
			LockingMutex.Unlock ();
			
			Waiters --;
			
			THROW_ERROR ( "Unspecified error waiting on condition!" );
			
		};
		
	}
	
	Waiters --;
	
};

bool Condition :: TimedWait ( double Seconds )
{
	
	if ( ! PreLocked )
		LockingMutex.Lock ();
	
	if ( Set )
	{
		
		LockingMutex.Unlock ();
		
		return true;
		
	}
	
	Waiters ++;
	
	struct timespec Time;
	int ErrorCode;
	
#if _POSIX_TIMERS > 0
	
	clockid_t Clock;
	
#ifndef __VXWORKS__
	ErrorCode = pthread_getcpuclockid ( pthread_self (), & Clock );
#else
	Clock = CLOCK_MONOTONIC;
#endif
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified error getting thread clock ID for condition timed wait!" );
	
	ErrorCode = clock_gettime ( Clock, & Time );
	
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
	
	Time.tv_sec += static_cast <uint64_t> ( Seconds );
	Seconds -= (uint64_t) Seconds;
	
	Time.tv_nsec = static_cast <uint64_t > ( Seconds * 1000000000.0 );
	
	while ( ! Set )
	{
		
		ErrorCode = pthread_cond_timedwait ( & ConditionHandle, & LockingMutex.MutexHandle, & Time );
		
		switch ( ErrorCode )
		{
			
		case 0:	
			break;
			
		case ETIMEDOUT:
		
			Waiters --;
			
			LockingMutex.Unlock ();
			
			return false;
			
		case EINVAL:
		
			Waiters --;
		
			THROW_ERROR ( "Invalid time specified to condition timed wait!" );
			
		default:
		
			Waiters --;
			
			THROW_ERROR ( "Unspecified error waiting on condition!" );
			
		}
			
	};
	
	Waiters --;
	
	LockingMutex.Unlock ();
	
	return true;
	
};

void Condition :: LockWait ()
{
	
	if ( ! PreLocked )
		LockingMutex.Lock ();
	
	Waiters ++;
	
	while ( ! Set )
	{
		
		int ErrorCode = pthread_cond_wait ( & ConditionHandle, & LockingMutex.MutexHandle );
		
		switch ( ErrorCode )
		{
			
		case 0:	
			break;
			
		default:
		
			Waiters --;
		
			THROW_ERROR ( "Unspecified error waiting on condition!" );
			
		};
		
	}
	
	Waiters --;
	
};

bool Condition :: TimedLockWait ( double Seconds )
{
	
	if ( ! PreLocked )
		LockingMutex.Lock ();
	
	if ( Set )
		return true;
	
	Waiters ++;
	
	struct timespec Time;
	int ErrorCode;
	
#if _POSIX_TIMERS > 0
	
	clockid_t Clock;
	
#ifndef __VXWORKS__
	ErrorCode = pthread_getcpuclockid ( pthread_self (), & Clock );
#else
	Clock = CLOCK_MONOTONIC;
#endif
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified error getting thread clock ID for condition timed wait!" );
	
	ErrorCode = clock_gettime ( Clock, & Time );
	
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
	
	Time.tv_sec += static_cast <uint64_t> ( Seconds );
	Seconds -= (uint64_t) Seconds;
	
	Time.tv_nsec = static_cast <uint64_t> ( Seconds * 1000000000.0 );
	
	while ( ! Set )
	{
		
		ErrorCode = pthread_cond_timedwait ( & ConditionHandle, & LockingMutex.MutexHandle, & Time );
		
		switch ( ErrorCode )
		{
			
		case 0:	
			break;
			
		case ETIMEDOUT:
			
			Waiters --;
			
			return false;
			
		case EINVAL:
			
			Waiters --;
			
			THROW_ERROR ( "Invalid time specified to condition timed wait!" );
			
		default:
			
			Waiters --;
			
			THROW_ERROR ( "Unspecified error waiting on condition!" );
			
		}
			
	};
	
	Waiters --;
	
	return true;
	
};
