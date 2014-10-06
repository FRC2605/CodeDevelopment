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
	
	Condition ( bool Persistant = true, bool ProcessShared = false );
	~Condition ();
	
	void Lock ();
	void Unlock ();
	void Signal ();
	void Reset ();
	void Broadcast ();
	void Wait ();
	bool TimedWait ( double Seconds );
	
private:
	
	pthread_cond_t ConditionHandle;
	pthread_condattr_t ConditionAttributes;
	
	RecursiveMutex LockingMutex;
	
	bool Persistant;
	bool Set;
	
};

#endif
