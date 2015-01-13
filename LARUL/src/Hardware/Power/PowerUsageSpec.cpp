#ifndef HARDWARE_POWER_POWERUSAGESPEC_CPP_
#define HARDWARE_POWER_POWERUSAGESPEC_CPP_

#include "PowerUsageSpec.h"

PowerUsageSpec :: PowerUsageSpec ( double MaxDraw, double MinDraw, double ExpectedAverage, uint64_t TimeoutMS ):
	MaxDraw ( MaxDraw ),
	MinDraw ( MinDraw ), 
	ExpectedAverage ( ExpectedAverage ),
	TimeoutMS ( TimeoutMS )
{	
};

double PowerUsageSpec :: GetMaxDraw ()
{
	
	return MaxDraw;
	
};

double PowerUsageSpec :: GetMinDraw ()
{
	
	return MinDraw;
	
}

double PowerUsageSpec :: GetExpectedAverage ()
{
	
	return ExpectedAverage;
	
};

uint64_t PowerUsageSpec :: GetTimeoutMS ()
{
	
	return TimeoutMS;
	
};

#endif
