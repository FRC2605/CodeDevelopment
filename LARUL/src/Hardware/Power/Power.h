#ifndef LARUL_POWER_H
#define LARUL_POWER_H

#include <WPILib.h>

class Power
{
public:
	
	static void Init ( PowerDistributionPanel * PDP );
	static PowerDistributionPanel * GetPDP ();
	
private:
	
	Power ();
	~Power ();
	
	static PowerDistributionPanel * PDP;
	
};

#endif
