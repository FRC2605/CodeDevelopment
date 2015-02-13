#include "Power.h"

#ifndef NO_WPILIB

PowerDistributionPanel * Power :: PDP = NULL;

Power :: Power ()
{
};

Power :: ~Power ()
{
};

void Power :: Init ( PowerDistributionPanel * PDP )
{
	
	Power :: PDP = PDP;
	
};

PowerDistributionPanel * Power :: GetPDP ()
{
	
	return PDP;
	
};

#endif
