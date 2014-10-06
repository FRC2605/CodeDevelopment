#include "Synchronized.h"

Synchronized :: Synchronized ( IMutex * SyncMutex ):
	SyncMutex ( SyncMutex )
{
	
	SyncMutex -> Lock ();
	
};

Synchronized :: ~Synchronized ()
{
	
	SyncMutex -> Unlock ();
	
};
