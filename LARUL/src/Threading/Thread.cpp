#include "Thread.h"

#include <time.h>
#include <sys/types.h>

#include <math.h>

#include "../Util/LError.h"

#ifndef __VXWORKS__
	#include <sys/time.h>
#else
	#include <timers.h>
#endif

pthread_key_t CurrentThreadKey;
Thread * __MainThread = Thread :: __ConstructMainThread ();

Thread * Thread :: __ConstructMainThread ()
{
	
	return new Thread ();
	
};

Thread * Thread :: GetCurrentThread ()
{
		
	return reinterpret_cast <Thread *> ( pthread_getspecific ( CurrentThreadKey ) );
	
};

void Thread :: Terminate ( void * Status )
{
	
	pthread_exit ( Status );
	
};

void Thread :: SetCancelable ( bool Cancelable )
{
	
	Thread * Current = GetCurrentThread ();
	
	Current -> ThreadMutex.Lock ();
	
	int OldState;
	int ErrorCode = pthread_setcancelstate ( Cancelable ? PTHREAD_CANCEL_ENABLE : PTHREAD_CANCEL_DISABLE, & OldState );
	
	Current -> ThreadMutex.Unlock ();
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified error setting cancelation state!" );
	
};

void Thread :: TestCancelation ()
{
	
	pthread_testcancel ();
	
};

void * ThreadStub ( void * Instance );
void CleanupStub ( void * Instance );

Thread :: Thread ( IDelegate1 <void, Thread *> * Function, bool Joinable, int ThreadPriority, SchedulingPolicy Policy ):
	Function ( Function ),
	ThreadHandle (),
	State ( kThreadState_Stopped ),
	Joinable ( Joinable ),
	Priority ( ThreadPriority ),
	Policy ( Policy ),
	Destruction ( kDestructorBehavior_LeaveRunning ),
	Status ( NULL ),
	ThreadMutex (),
	Name ( "Anonymous" )
{
	
	int ErrorCode = pthread_attr_init ( & ThreadAttributes );
	
	switch ( ErrorCode )
	{
		
	case 0:
		break;
		
	case ENOMEM:
		THROW_ERROR ( "Insufficient memory to create Thread object!" );
		
	default:
		THROW_ERROR ( "Unspecified error creating thread attribute object for thread!" );
		
	}
	
	if ( pthread_attr_setdetachstate ( & ThreadAttributes, Joinable ? PTHREAD_CREATE_JOINABLE : 0 ) != 0 )
		THROW_ERROR ( "Unspecified error setting detach state of thread attribute object!" );
	
};

Thread :: Thread ():
	Function ( NULL ),
	State ( kThreadState_Running ),
	Joinable ( true ),
	Priority ( - 1 ),
	Destruction ( kDestructorBehavior_LeaveRunning ),
	Status ( NULL ),
	ThreadMutex (),
	Name ( "Main" )
{
	
	ThreadHandle = pthread_self ();
	
	pthread_key_create ( & CurrentThreadKey, NULL );
	pthread_setspecific ( CurrentThreadKey, reinterpret_cast <const void *> ( this ) );
	
	int Policy;
	struct sched_param Param;
	
	if ( pthread_getschedparam ( ThreadHandle, & Policy, & Param ) != 0 )
		THROW_ERROR ( "Failed to get the scheduling policy of the main thread!" );
	
	switch ( Policy )
	{
		
	case SCHED_RR:
		this -> Policy = kSchedulingPolicy_RoundRobin;
		break;
		
	#ifdef SCHED_IDLE
	
	case SCHED_IDLE:
		this -> Policy = kSchedulingPolicy_Idle;
		break;
	
	#endif
		
	case SCHED_OTHER:
		this -> Policy = kSchedulingPolicy_Other;
		break;
		
	case SCHED_FIFO:
		this -> Policy = kSchedulingPolicy_FIFO;
		break;
	
	#ifdef SCHED_BATCH
		
	case SCHED_BATCH:
		this -> Policy = kSchedulingPolicy_Batch;
		break;
		
	#endif
		
	default:
		THROW_ERROR ( "Unrecognized thread scheduling policy!" );
		
	};
	
};

void Thread :: SetDestructorBehavior ( DestructorBehavior Destruction )
{
	
	ThreadMutex.Lock ();
	
	this -> Destruction = Destruction;
	
	ThreadMutex.Unlock ();
	
};

Thread :: ~Thread ()
{
	
	if ( State == kThreadState_Running )
	{
		
		switch ( Destruction )
		{
		
		case kDestructorBehavior_LeaveRunning:
			break;
			
		case kDestructorBehavior_Join:
			
			if ( GetCurrentThread () != this )
				Join ();
			
			break;
			
		case kDestructorBehavior_Cancel:
		
			if ( GetCurrentThread () != this )
				Cancel ();
			
			break;
			
		}
		
	}
	
};

void Thread :: Cancel ()
{
	
	ThreadMutex.Lock ();
	
	if ( State != kThreadState_Running )
	{
		
		ThreadMutex.Unlock ();
		return;
		
	}
	
	int ErrorCode = pthread_cancel ( ThreadHandle );
	
	if ( ErrorCode != 0 )
		THROW_ERROR ( "Unspecified cancel error!" );
	
	ThreadMutex.Unlock ();
	
};

void Thread :: Start ()
{
	
	ThreadMutex.Lock ();
	
	if ( State != kThreadState_Stopped )
	{
		
		ThreadMutex.Unlock ();
		
		THROW_ERROR ( "Attempt to double-run thread!" );
		
	}
	
	int ReturnCode = pthread_create ( & ThreadHandle, & ThreadAttributes, & ThreadStub, (void *) this );
	
	State = kThreadState_Running;
	
	ThreadMutex.Unlock ();
	
	switch ( ReturnCode )
	{
	
	case 0:
		break;
	
	case EAGAIN:
		State = kThreadState_Error;
		THROW_ERROR ( "Insufficient system resources to start thread, or a system limit was encountered!" );
	
	case EINVAL:
		State = kThreadState_Error;
		THROW_ERROR ( "Invalid thread settings!" );
	
	case EPERM:
		State = kThreadState_Error;
		THROW_ERROR ( "Insufficient permissions to set the scheduling policy and parameters!" );
	
	default:
		State = kThreadState_Error;
		THROW_ERROR ( "Unspecified error!" );
	
	}
	
};

void Thread :: Join ()
{
	
	ThreadMutex.Lock ();
	
	if ( ! Joinable )
		THROW_ERROR ( "Attempt to join a non-joinable thread!" );
	
	if ( State != kThreadState_Running )
	{
		
		ThreadMutex.Unlock ();
		return;
		
	}
	
	ThreadMutex.Unlock ();
	
	int ErrorCode = pthread_join ( ThreadHandle, & Status );
	
	switch ( ErrorCode )
	{
	
	case 0:
		return;
		
	case EDEADLK:
		THROW_ERROR ( "Deadlock condition encountered joining thread!" );
		
	default:
		THROW_ERROR ( "Unspecified error joining thread!" );
		
	}
	
};

Thread :: ThreadState Thread :: GetState ()
{
	
	ThreadMutex.Lock ();
	ThreadState ThisState = State;
	ThreadMutex.Unlock ();
	
	return ThisState;
	
};

void Thread :: ClearError ()
{
	
	ThreadMutex.Lock ();
	
	if ( State == kThreadState_Error )
		State = kThreadState_Stopped;
		
	ThreadMutex.Unlock ();
	
};

void * Thread :: Entry ()
{
	
	ThreadMutex.Lock ();
	
	pthread_setspecific ( CurrentThreadKey, reinterpret_cast <const void *> ( this ) );
	
	int OldStateType;
	
	pthread_setcancelstate ( PTHREAD_CANCEL_DISABLE, & OldStateType );
	pthread_setcanceltype ( PTHREAD_CANCEL_DEFERRED, & OldStateType );
	
	State = kThreadState_Running;
	
	ThreadMutex.Unlock ();
	
	pthread_cleanup_push ( & CleanupStub, (void *) this );
	
	try
	{
		
		Function -> Call ( this );
		
	}
	catch ( LError & E )
	{
		
		State = kThreadState_Error;
		
		if ( Name == NULL )
			Logger :: GetInstance () -> ForcedLog ( "\n\n****** Thread Terminated! ****** \n==> %s", E.GetErrorString ().c_str () );
		else
			Logger :: GetInstance () -> ForcedLog ( "\n\n****** Thread [ %s ] Terminated! ****** \n==> %s", Name, E.GetErrorString ().c_str () );
		
	}
	catch ( ... )
	{
		
		State = kThreadState_Error;
		
		if ( Name == NULL )
			Logger :: GetInstance () -> ForcedLog ( "\n\n****** Thread Terminated! ****** \n==> The error thrown could not be caught by LARUL.\n" );
		else
			Logger :: GetInstance () -> ForcedLog ( "\n\n****** Thread [ %s ] Terminated! ****** \n==> The error thrown could not be caught by LARUL.\n" );
		
	}
	
	pthread_cleanup_pop ( 1 );
	
	return NULL;
	
};

void Thread :: Cleanup ()
{
	
	ThreadMutex.Lock ();
	
	State = kThreadState_Stopped;
	Status = NULL;

	ThreadMutex.Unlock ();
	
};

void Thread :: SetName ( const char * Name )
{
	
	ThreadMutex.Lock ();
	
	this -> Name = Name;

	ThreadMutex.Unlock ();
	
};

void Thread :: WaitS ( double Seconds )
{
	
	struct timespec WaitTime;
	
	WaitTime.tv_sec = static_cast <time_t> ( trunc ( Seconds ) );
	WaitTime.tv_nsec = static_cast <long> ( fmod ( Seconds, 1.0 ) * 1000000000.0 );
	
	nanosleep ( & WaitTime, NULL );
	
};

void Thread :: WaitMS ( uint64_t MS )
{
	
	struct timespec WaitTime;
	
	WaitTime.tv_sec = MS / 1000;
	WaitTime.tv_nsec = ( MS % 1000 ) * 1000000;
	
	nanosleep ( & WaitTime, NULL );
	
};

void * ThreadStub ( void * Instance )
{
	
	return reinterpret_cast <Thread *> ( Instance ) -> Entry ();
	
};

void CleanupStub ( void * Instance )
{
	
	return reinterpret_cast <Thread *> ( Instance ) -> Cleanup ();
	
};
