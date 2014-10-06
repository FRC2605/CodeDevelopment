#ifndef LARUL_MUTEX_H
#define LARUL_MUTEX_H

#include <stdint.h>
#include <pthread.h>
#include <errno.h>

#include "../Util/Error.h"

#include "IMutex.h"
#include "Condition.h"

#ifndef PTHREAD_MUTEX_ROBUST
	#ifdef PTHREAD_MUTEX_ROBUST_NP
		#define PTHREAD_MUTEX_ROBUST PTHREAD_MUTEX_ROBUST_NP
	#endif
#endif

class Mutex : public IMutex
{
public:
	
	Mutex ( bool ErrorChecking = false, bool Robust = false );
	~Mutex ();
	
	void Lock ();
	void Unlock ();
	bool TryLock ();
	
private:
	
	pthread_mutex_t MutexHandle;
	pthread_mutexattr_t MutexOptions;
	
	bool Robust;
	
};

#endif
