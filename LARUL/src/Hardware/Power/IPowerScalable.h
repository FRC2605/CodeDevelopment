#ifndef LARUL_POWERSCALABLE_H
#define LARUL_POWERSCALABLE_H

#include "PowerProfile.h"
#include "PowerUsageSpec.h"

class IPowerScalable
{
public:
	
	virtual ~IPowerScalable () {};
	
	virtual PowerProfile * GetProfile () = 0;
	virtual PowerUsageSpec * GetSpec () = 0;
	
	virtual void SetPowerScale ( double Scale ) = 0;
	
};

#endif
