#ifndef LARUL_MSCLOCK_H
#define LARUL_MSCLOCK_H

#include <stdint.h>

class Clock
{
public:
	
	static uint64_t GetTimeMonotonicMS ();
	static uint64_t GetTimeSystemMS ();
	
};

#endif
