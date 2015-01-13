#ifndef LARUL_POWERSCALABLE_H
#define LARUL_POWERSCALABLE_H

#include "PowerProfile.h"
#include "PowerUsageSpec.h"

class IPowerScalable
{
	
	virtual ~IPowerScalable () {};
	
	virtual PowerProfile * GetProfile ();
	virtual PowerUsageSpec * GetSpec ();
	
	virtual void SetPowerScale ( double Scale );
	
};

#endif
