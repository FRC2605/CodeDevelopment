#ifndef LARUL_SYNCHRONIZED_H
#define LARUL_SYNCHRONIZED_H

#include "IMutex.h"

class Synchronized
{
public:

	Synchronized ( IMutex * SyncMutex );	
	~Synchronized ();
	
private:
	
	IMutex * SyncMutex;
	
};

#endif
