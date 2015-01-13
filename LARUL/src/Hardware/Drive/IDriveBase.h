#ifndef LARUL_DRIVEBASE_H
#define LARUL_DRIVEBASE_H

#include "../HWSystem.h"
#include "../Power/IPowerScalable.h"

class IDriveBase : public HWSystem, public IPowerScalable
{
public:
	
	virtual ~IDriveBase () {};
	
};

#endif
