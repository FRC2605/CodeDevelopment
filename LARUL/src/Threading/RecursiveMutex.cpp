#include "RecursiveMutex.h"

RecursiveMutex :: RecursiveMutex ( bool Robust )
{
	
	pthread_mutexattr_init ( & MutexOptions );
	pthread_mutexattr_settype ( & MutexOptions, PTHREAD_MUTEX_RECURSIVE );
	
#ifdef PTHREAD_MUTEX_ROBUST
	
	if ( Robust )
		pthread_mutexattr_setrobust ( & MutexOptions, PTHREAD_MUTEXATTR_ROBUST );
	else
		pthread_mutexattr_setrobust ( & MutexOptions, PTHREAD_MUTEXATTR_STALLED );
	
#endif
	
	int ErrorCodeCode = pthread_mutex_init ( & MutexHandle, & MutexOptions );
	
	switch ( ErrorCodeCode )
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

void RecursiveMutex :: Lock ()
{
	
	int ErrorCode = pthread_mutex_lock ( & MutexHandle );
	
	switch ( ErrorCode )
	{
		
	case 0:
		return;
		
	case EAGAIN:
		THROW_ERROR ( "The recursive mutex lock count has encountered a maximum!" );
		
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
			THROW_ERROR ( "Mutex holding thread terminated and the mutex could not be recovered!" );
		
		break;
		
#endif
		
	default:
		THROW_ERROR ( "Unspecified mutex lock error encountered!" );
		
	}
	
};

bool RecursiveMutex :: TryLock ()
{
	
	int ErrorCode = pthread_mutex_trylock ( & MutexHandle );
	
	switch ( ErrorCode )
	{
	
	case 0:
		return true;
		
	case EBUSY:
		return false;
		
	case EAGAIN:
		THROW_ERROR ( "The recursive mutex lock count has encountered a maximum!" );
		
	}
	
	THROW_ERROR ( "Unspecified mutex trylock error encountered!" );
	
};

void RecursiveMutex :: Unlock ()
{
	
	int ErrorCode = pthread_mutex_unlock ( & MutexHandle );
	
	if ( ErrorCode == 0 )
		return;
	
	if ( ErrorCode == EPERM )
		THROW_ERROR ( "The thread unlocking the mutex did not own it." );
	
	THROW_ERROR ( "Unspecified mutex error encountered!" );
	
};

RecursiveMutex :: ~RecursiveMutex ()
{
	
	pthread_mutexattr_destroy ( & MutexOptions );
	
	pthread_mutex_destroy ( & MutexHandle );
	
};
