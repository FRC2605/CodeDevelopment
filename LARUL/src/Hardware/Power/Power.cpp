#include "Power.h"

Power :: Power () 
{
};

Power :: ~Power () 
{
};

void Power :: Init ( PowerDistributionPanel * Panel )
{
	
	Power :: PDP = Panel;
	
};

PowerDistributionPanel * Power :: GetPDP ()
{
	
	return Power :: PDP;
	
};
