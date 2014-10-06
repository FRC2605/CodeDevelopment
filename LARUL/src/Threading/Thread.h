#ifndef LARUL_THREAD_H
#define LARUL_THREAD_H

#include <stdint.h>
#include <pthread.h>
#include <errno.h>

#include "../Util/Delegate.h"
#include "../Util/Error.h"

#include "../Logging/Logger.h"

#include "RecursiveMutex.h"

class Thread
{
public:
	
	typedef enum
	{
		
		kThreadState_Running,
		kThreadState_Stopped,
		kThreadState_Error,
		kThreadState_Destructing
		
	} ThreadState;
	
	
	typedef enum
	{
		
		kDestructorBehavior_LeaveRunning,
		kDestructorBehavior_Join,
		kDestructorBehavior_Cancel
		
	} DestructorBehavior;
	
	Thread ( IDelegate1 <void, Thread *> * Function, bool Joinable = true );
	~Thread ();
	
	void ClearError ();
	
	void SetDestructorBehavior ( DestructorBehavior Destruction );
	
	void Start ();
	void Join ();
	void Cancel ();
	
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
	
	DestructorBehavior Destruction;
	
	void * Status;
	
	RecursiveMutex ThreadMutex;
	
	friend void * ThreadStub ( void * Instance );
	friend void CleanupStub ( void * Instance );
	
};

#endif
