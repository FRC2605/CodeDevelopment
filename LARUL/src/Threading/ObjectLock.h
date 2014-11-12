#ifndef LARUL_OBJECTLOCK_H
#define LARUL_OBJECTLOCK_H

#include "Thread.h"
#include "Condition.h"
#include "Mutex.h"

#include "../Util/Vector.h"

class ObjectLock
{
public:
	
	static void Lock ( void * Object );
	static bool TryLock ( void * Object );
	static void Unlock ( void * Object, bool ClearCondition = false );
	
private:
	
	typedef struct
	{
		
		void * Object;
		Thread * Owner;
		
		uint32_t Count;
		
		Condition * WaitCond;
		
	} LockRecord;
	
	static Vector <LockRecord> ActiveLocks;
	static Mutex ListSync;
	
};

#endif
