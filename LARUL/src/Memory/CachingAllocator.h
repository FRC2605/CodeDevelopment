#ifndef LARUL_CACHINGALLOCATOR_H
#define LARUL_CACHINGALLOCATOR_H

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include "IAllocSpec.h"

#include "../Threading/Mutex.h"

#include "../Util/Error.h"

class CachingAllocator
{
public:
	
	CachingAllocator ( IAllocSpec * Spec, uint32_t CacheSize, uint32_t PreFill );
	~CachingAllocator ();
	
	void Alloc ( void ** Memory );
	void Free ( void ** Memory );
	
private:
	
	IAllocSpec * Spec;
	
	size_t AllocSize;
	size_t AllocAlign;
	
	Mutex CacheSync;
	
	void ** Cache;
	uint32_t CacheSize;
	uint32_t CacheUsed;
	
};

#endif
