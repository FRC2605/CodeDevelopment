#ifndef LARUL_CONDITION_H
#define LARUL_CONDITION_H

#include <stdint.h>
#include <pthread.h>

#include "../Util/LError.h"

#include "Mutex.h"

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
	
	Mutex LockingMutex;
	Mutex PreLockedSync;
	
	bool PreLocked;
	bool Set;
	uint32_t Waiters;
	
};

#endif
