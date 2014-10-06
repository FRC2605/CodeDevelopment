#include "Thread.h"

__thread Thread * CurrentThread = NULL;

Thread * Thread :: GetCurrentThread ()
{
	
	if ( CurrentThread == NULL )
		CurrentThread = new Thread ();
	
	return CurrentThread;
	
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

void * ThreadStub ( void * Instance );
void CleanupStub ( void * Instance );

Thread :: Thread ( IDelegate1 <void, Thread *> * Function, bool Joinable ):
	Function ( Function ),
	State ( kThreadState_Stopped ),
	Joinable ( Joinable ),
	Destruction ( kDestructorBehavior_LeaveRunning ),
	Status ( NULL ),
	ThreadMutex ()
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
		THROW_ERROR ( "Unspecified error setting detatch state of thread attribute object!" );
	
};

Thread :: Thread ():
	Function ( NULL ),
	State ( kThreadState_Running ),
	Joinable ( true ),
	Destruction ( kDestructorBehavior_LeaveRunning ),
	Status ( NULL ),
	ThreadMutex ()
{
	
	ThreadHandle = pthread_self ();
	
};

void Thread :: SetDestructorBehavior ( DestructorBehavior Destruction )
{
	
	ThreadMutex.Lock ();
	
	this -> Destruction = Destruction;
	
	ThreadMutex.Unlock ();
	
};

Thread :: ~Thread ()
{
	
	ThreadMutex.Lock ();
	
	if ( State == kThreadState_Running )
	{
		
		switch ( Destruction )
		{
		
		case kDestructorBehavior_LeaveRunning:
			break;
			
		case kDestructorBehavior_Join:
			
			if ( CurrentThread != this )
				Join ();
			
			break;
			
		case kDestructorBehavior_Cancel:
		
			if ( CurrentThread != this )
				Cancel ();
			
			break;
			
		}
		
	}
	
	State = kThreadState_Destructing;
	
	ThreadMutex.Unlock ();
	
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
	
	CurrentThread = this;
	
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
	catch ( Error E )
	{
		
		Logger :: GetInstance () -> ForcedLog ( "Thread terminated!\n==> %s", E.GetErrorString ().c_str () );
		
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

void * ThreadStub ( void * Instance )
{
	
	return reinterpret_cast <Thread *> ( Instance ) -> Entry ();
	
};

void CleanupStub ( void * Instance )
{
	
	return reinterpret_cast <Thread *> ( Instance ) -> Cleanup ();
	
};
