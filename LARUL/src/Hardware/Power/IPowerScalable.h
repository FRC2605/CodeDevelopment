#ifndef LARUL_POWERSCALABLE_H
#define LARUL_POWERSCALABLE_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB

#include "IPowerProfiled.h"

#include "PowerProfile.h"
#include "PowerUsageSpec.h"

class IPowerScalable : public IPowerProfiled
{
public:
	
	virtual ~IPowerScalable () {};
	
	virtual PowerUsageSpec * GetSpec () = 0;
	
	virtual void SetPowerScale ( double Scale ) = 0;
	
};

#endif

#endif
