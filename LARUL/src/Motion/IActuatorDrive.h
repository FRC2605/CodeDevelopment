#ifndef LARUL_IACTUATORDRIVE_H
#define LARUL_IACTUATORDRIVE_H

#include "../CPP/Virtual.h"

class IActuatorDrive
{
public:
	
	VIRTUAL_CLASS ( IActuatorDrive );
	
	virtual void Enable ();
	virtual void Disable ();
	
};

#endif
