#ifndef LARUL_THREAD_H
#define LARUL_THREAD_H

#include <stdint.h>
#include <pthread.h>
#include <errno.h>

#include "../Util/Delegate.h"
#include "../Util/Error.h"

#include "../Logging/Logger.h"

#include "RecursiveMutex.h"

/*
* Thread is the class used for managing and creating an application thread. It is based on POSIX threads, with some optional extensions.
* Note that unlike the WPILib Task, a thread doesn't have a specific way to be stopped by default. The Cancel () method will tell pthreads
* that we want to cancel the thread at the next opertunisitc point. ( See POSIX spec for a list of cancelable functions. ) This will not
* gaurentee immediate halt nor clean up the memory or other resources allocated by a thread.
*/

class Thread
{
public:
	
	// Different possible states of a thread.
	typedef enum
	{
		
		kThreadState_Running,		// Currently, the thread is executing.
		kThreadState_Stopped,		// The thread is not currently executing.
		kThreadState_Error,			// The thread object has encountered some kind of error or the thread was terminated prematureley. 
		kThreadState_Destructing
		
	} ThreadState;
	
	
	typedef enum
	{
		
		kDestructorBehavior_LeaveRunning,
		kDestructorBehavior_Join,
		kDestructorBehavior_Cancel
		
	} DestructorBehavior;
	
	typedef enum
	{
		
		kSchedulingPolicy_Other,
		kSchedulingPolicy_Idle,
		kSchedulingPolicy_RoundRobin,
		kSchedulingPolicy_FIFO,
		kSchedulingPolicy_Batch
		
	} SchedulingPolicy;
	
	
	static const int kThreadPriority_RealTime = 31;
	static const int kThreadPriority_Critical = 27;
	static const int kThreadPriority_Important = 24;
	static const int kThreadPriority_General = 19;
	static const int kThreadPriority_BackgroundImportant = 15;
	static const int kThreadPriority_Background = 7;
	static const int kThreadPriority_Least = 0;
	
	Thread ( IDelegate1 <void, Thread *> * Function, bool Joinable = true, int ThreadPriority = kThreadPriority_General );
	~Thread ();
	
	void ClearError ();
	
	void SetDestructorBehavior ( DestructorBehavior Destruction );
	
	void Start ();
	void Join ();
	void Cancel ();
	
	void SetName ( const char * Name );
	
	Thread :: ThreadState GetState ();
	
	static Thread * GetCurrentThread ();
	static void Terminate ( void * Status = NULL );
	static void SetCancelable ( bool Cancelable );
	
private:
	
	Thread ();
	
	void * Entry ();
	void Cleanup ();
	
	IDelegate1 <void, Thread *> * Function;
	
	pthread_t ThreadHandle;
	pthread_attr_t ThreadAttributes;
	
	ThreadState State;
	
	bool Joinable;
	int Priority;
	SchedulingPolicy Policy;
	
	DestructorBehavior Destruction;
	
	void * Status;
	
	RecursiveMutex ThreadMutex;
	
	friend void * ThreadStub ( void * Instance );
	friend void CleanupStub ( void * Instance );
	
	const char * Name;
	
};

#endif
