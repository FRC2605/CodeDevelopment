#ifndef LARUL_ASYNCALLOCATOR_H
#define LARUL_ASYNCALLOCATOR_H

#include <stdlib.h>
#include <stddef.h>

#include "IAllocSpec.h"

#include "../Threading/Mutex.h"
#include "../Threading/Thread.h"
#include "../Threading/Condition.h"

#include "../Util/MethodClosure.h"

// NOT DONE!!!!

class AsyncAllocator
{
public:
	
	typedef enum
	{
		
		kAllocationMode_AsyncCaching,
		kAllocationMode_AsyncNoCache,
		kAllocationMode_SyncCaching,
		kAllocationMode_SyncNoCache
		
	} AllocationMode;
	
	AsyncAllocator ( IAllocSpec Spec, uint32_t MinimumBatch, uint32_t MaximumBatch );
	~AsyncAllocator ();
	
	void SetMode ( AllocationMode Mode );
	
	void Start ();
	void Stop ();
	
	void Free ( void * Memory, bool DontCache = false );
	void Alloc ( void ** Memory );
	
private:
	
	void AllocationTask ();
	
	AllocationMode Mode;
	
	IAllocSpec Spec;
	
	uint32_t Minimum;
	uint32_t Maximum;
	
	MethodClosure TaskClosure;
	Thread AllocationThread;
	Condition AllocSignal;
	Mutex GeneralSync;
	Mutex TimeSync;
	Mutex ModeSync;
	
	void ** AllocationSlots;
	uint32_t CurrentSlots;
	
	bool Running;
	
};

#endif
