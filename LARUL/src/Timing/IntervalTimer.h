#ifndef LARUL_TIMER_H
#define LARUL_TIMER_H

#include <stdint.h>

#include "../Util/LError.h"

#include "../Threading/Mutex.h"

#include "Clock.h"

#include "../Sensing/IScalarInput.h"

class IntervalTimer : public IScalarInput
{
public:
	
	typedef enum
	{
		
		kTimeMode_Monotonic,
		kTimeMode_System
		
	} TimeMode;
	
	typedef enum
	{
		
		kScalarInputUnit_Seconds,
		kScalarInputUnit_Milliseconds
		
	} ScalarInputUnit;
	
	IntervalTimer ( TimeMode Mode = kTimeMode_Monotonic );
	~IntervalTimer ();
	
	void Start ();
	void Stop ();
	void Reset ();
	void Restart ();
	
	double GetTimeMS ();
	double GetTimeS ();
	
	void SetTimeMode ( TimeMode Mode );
	
	void SetScalarInputUnits ( ScalarInputUnit Unit );
	
	double GetScalar ();
	
	ScalarLimit GetScalarLimitType ();
	double GetLimitParam ( ScalarLimitParam Param );

private:
	
	uint64_t Time;
	uint64_t Offset;
	
	bool Running;
	
	TimeMode Mode;
	
	ScalarInputUnit SIUnit;
	
};

#endif
