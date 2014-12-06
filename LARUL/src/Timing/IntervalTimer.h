#ifndef LARUL_TIMER_H
#define LARUL_TIMER_H

#include <stdint.h>

#include "../Util/LError.h"

#include "../Threading/Mutex.h"

#include "Clock.h"

class IntervalTimer
{
public:
	
	typedef enum
	{
		
		kTimeMode_Monotonic,
		kTimeMode_System
		
	} TimeMode;
	
	IntervalTimer ( TimeMode Mode = kTimeMode_Monotonic );
	~IntervalTimer ();
	
	void Start ();
	void Stop ();
	void Reset ();
	void Restart ();
	
	double GetTimeMS ();
	double GetTimeS ();
	
	void SetTimeMode ( TimeMode Mode );

private:
	
	uint64_t Time;
	uint64_t Offset;
	
	bool Running;
	
	TimeMode Mode;
	
	Mutex SyncMutex;
	
};

#endif
