#ifndef LARUL_RECURSIVEMUTEX_H
#define LARUL_RECURSIVEMUTEX_H

#include <stdint.h>
#include <pthread.h>
#include <errno.h>

#include "../Util/Error.h"

#include "IMutex.h"

class Condition;

class RecursiveMutex : public IMutex
{
public:
	
	RecursiveMutex ( bool Robust = false );
	~RecursiveMutex ();
	
	void Lock ();
	bool TryLock ();
	void Unlock ();
	
private:
	
	pthread_mutexattr_t MutexOptions;
	pthread_mutex_t MutexHandle;
	
	friend class Condition;
	
};

#endif
