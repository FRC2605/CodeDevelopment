#ifndef LARUL_POWER_H
#define LARUL_POWER_H

#include <WPILib.h>

class Power
{
public:
	
	~Power ();
	
	static void Init ( PowerDistributionPanel * PDP );
	static PowerDistributionPanel * GetPDP ();
	
private:
	
	Power ();
	
	static PowerDistributionPanel * PDP;
	
};

#endif
