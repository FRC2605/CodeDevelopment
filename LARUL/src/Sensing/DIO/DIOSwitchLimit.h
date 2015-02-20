#ifndef LARUL_DIOSWITCHLIMIT_H
#define LARUL_DIOSWITCHLIMIT_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "../IMotionLimit.h"

class DIOSwitchLimit : public IMotionLimit
{
public:
	
	DIOSwitchLimit ( DigitalInput * LowLimit = NULL, DigitalInput * HighLimit = NULL );
	~DIOSwitchLimit ();
	
	void SetInversion ( bool Low, bool High );
	
	LimitBounding GetBounding ();
	
	bool GetHighLimit ();
	bool GetLowLimit ();
	
private:
	
	 DigitalInput * LowLimit;
	 DigitalInput * HighLimit;
	 
	 bool InvertedL;
	 bool InvertedH;
	 
	 LimitBounding Bounding;
		
};

#endif
#endif
