#ifndef HARDWARE_POWER_POWERUSAGESPEC_H_
#define HARDWARE_POWER_POWERUSAGESPEC_H_

#include <stdint.h>

class PowerUsageSpec
{
public:
	
	PowerUsageSpec ( double MaxDraw, double MinDraw, double ExpectedAverage, uint64_t TimeoutMS );
	~PowerUsageSpec ();
	
	double GetMaxDraw ();
	double GetMinDraw ();
	
	double GetExpectedAverage ();
	
	uint64_t GetTimeoutMS ();
	
private:
	
	double MaxDraw;
	double MinDraw;
	double ExpectedAverage;
	uint64_t TimeoutMS;
	
};

#endif
