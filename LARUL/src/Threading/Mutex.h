#ifndef LARUL_MUTEX_H
#define LARUL_MUTEX_H

#include <stdint.h>
#include <pthread.h>
#include <errno.h>

#include "../Util/LError.h"

#include "IMutex.h"

#ifndef PTHREAD_MUTEX_ROBUST
	#ifdef PTHREAD_MUTEX_ROBUST_NP
		#define PTHREAD_MUTEX_ROBUST PTHREAD_MUTEX_ROBUST_NP
	#endif
#endif

class Condition;

class Mutex : public IMutex
{
public:
	
	explicit Mutex ( bool ErrorChecking = false, bool Robust = false );
	virtual ~Mutex ();
	
	void Lock ();
	void Unlock ();
	bool TryLock ();
	
private:
	
	pthread_mutex_t MutexHandle;
	pthread_mutexattr_t MutexOptions;
	
	bool Robust;
	
	friend class Condition;
	
};

#endif
