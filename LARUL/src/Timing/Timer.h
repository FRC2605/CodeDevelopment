#ifndef LARUL_TIMER_H
#define LARUL_TIMER_H

#include <stdint.h>
#include <time.h>
#include <sys/types.h>

#if _POSIX_TIMERS == 0
	#include <sys/time.h>
#endif

#include "../Util/Error.h"

#include "../Threading/Mutex.h"
#include "../Threading/Synchronized.h"

class Timer
{
public:
	
	typedef enum
	{
		
		kTimeMode_Monotonic,
		kTimeMode_System
		
	} TimeMode;
	
	Timer ( TimeMode Mode = kTimeMode_Monotonic );
	~Timer ();
	
	void Start ();
	void Stop ();
	void Reset ();
	void Restart ();
	
	double GetTimeMS ();
	double GetTimeS ();
	
	void SetTimeMode ( TimeMode Mode );
	
	static uint64_t GetTimeMonotonicMS ();
	static uint64_t GetTimeSystemMS ();

private:
	
	uint64_t Time;
	uint64_t Offset;
	
	bool Running;
	
	TimeMode Mode;
	
	Mutex SyncMutex;
	
};

#endif
