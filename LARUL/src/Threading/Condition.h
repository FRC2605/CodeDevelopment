#ifndef LARUL_CONDITION_H
#define LARUL_CONDITION_H

#include <stdint.h>
#include <pthread.h>
#include <time.h>
#include <sys/types.h>
#include <errno.h>

#if _POSIX_TIMERS == 0
	#include <sys/time.h>
#endif

#include "../Util/Error.h"

#include "RecursiveMutex.h"

class Condition
{
public:
	
	explicit Condition ( bool InitiallySet = false, bool ProcessShared = false );
	~Condition ();
	
	void Signal ();
	void Broadcast ();
	
	void PreLock ();
	
	void Wait ();
	bool TimedWait ( double Seconds );
	
	void LockWait ();
	bool TimedLockWait ( double Seconds );
	void Unlock ();
	
	void Reset ();
	
private:
	
	pthread_cond_t ConditionHandle;
	pthread_condattr_t ConditionAttributes;
	
	RecursiveMutex LockingMutex;
	
	bool PreLocked;
	bool Set;
	uint32_t Waiters;
	
};

#endif
