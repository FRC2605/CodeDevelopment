#include "Mutex.h"

Mutex :: Mutex ( bool ErrorChecking, bool Robust ):
	MutexOptions (),
	Robust ( Robust )
{
	
	int ErrorCode = pthread_mutexattr_init ( & MutexOptions );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case ENOMEM:
		THROW_ERROR ( "Insufficient memory to create recursive mutex!" );
		
	default:
		THROW_ERROR ( "Unspecified mutex attribute init error encountered!" );
		
	}
	
#ifdef PTHREAD_MUTEX_ERRORCHECK
	if ( ErrorChecking )
		pthread_mutexattr_settype ( & MutexOptions, PTHREAD_MUTEX_ERRORCHECK );
	else
		pthread_mutexattr_settype ( & MutexOptions, PTHREAD_MUTEX_NORMAL );
#endif	

#ifdef PTHREAD_MUTEX_ROBUST
	
	if ( Robust )
		pthread_mutexattr_setrobust ( & MutexOptions, PTHREAD_MUTEX_ROBUST );
	else
		pthread_mutexattr_setrobust ( & MutexOptions, PTHREAD_MUTEX_STALLED );
	
#endif
	
	ErrorCode = pthread_mutex_init ( & MutexHandle, & MutexOptions );
	
	switch ( ErrorCode )
	{
	case 0:
		break;
		
	case EAGAIN:
		THROW_ERROR ( "Insufficient system resources to create recursive mutex!" );
		
	case ENOMEM:
		THROW_ERROR ( "Insufficient memory to create recursive mutex!" );
		
	case EPERM:
		THROW_ERROR ( "Insufficient priveleges to create recursive mutex!" );
		
	case EBUSY:
		THROW_ERROR ( "Attempt to re-create active recursive mutex!" );
		
	default:
		THROW_ERROR ( "Unspecified mutex lock error encountered!" );
		
	}
	
};

Mutex :: ~Mutex ()
{
	
	pthread_mutex_destroy ( & MutexHandle );
	
	pthread_mutexattr_destroy ( & MutexOptions );
	
};

void Mutex :: Lock ()
{
	
	int ErrorCode = pthread_mutex_lock ( & MutexHandle );
	
	switch ( ErrorCode )
	{
		
	case 0:
		return;
		
	case EDEADLK:
		THROW_ERROR ( "Deadlock condition encountered!" );

#ifdef EOWNERDEAD
	case EOWNERDEAD:

#ifdef PTHREAD_MUTEX_ROBUST

		if ( Robust )
		{
			
			ErrorCode = pthread_mutex_consistent ( & MutexHandle );
			
			if ( ErrorCode == 0 )
				return;
			
		}
		
#else
		
		Unlock ();
		ErrorCode = pthread_mutex_lock ( & MutexHandle );
		
		if ( ErrorCode != 0 )
			THROW_ERROR ( "Thread holding mutex terminated and the mutex could not be recovered!" );
		
		break;
		
#endif
#endif
		
	}
	
	THROW_ERROR ( "Unspecified mutex lock error encountered!" );
	
};

void Mutex :: Unlock ()
{
	
	int ErrorCode = pthread_mutex_unlock ( & MutexHandle );
	
	if ( ErrorCode == 0 )
		return;
	
	if ( ErrorCode == EPERM )
		THROW_ERROR ( "The thread unlocking the mutex did not own it." );
	
	THROW_ERROR ( "Unspecified mutex error encountered!" );
	
};

bool Mutex :: TryLock ()
{
	
	int ErrorCode = pthread_mutex_trylock ( & MutexHandle );
	
	if ( ErrorCode == 0 )
		return true;
	
	if ( ErrorCode == EBUSY )
		return false;
	
	if ( ErrorCode == EDEADLK && Robust )
		return true;
	
	THROW_ERROR ( "Unspecified mutex trylock error encountered!" );
	
	return false;
	
};
