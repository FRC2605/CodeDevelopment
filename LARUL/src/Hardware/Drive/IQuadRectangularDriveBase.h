#ifndef LARUL_IQUADRECTANGULARDRIVEBASE_H
#define LARUL_IQUADRECTANGULARDRIVEBASE_H

#include "IDriveBase.h"

class IQuadRectangularDriveBase : public virtual IDriveBase
{
public:
	
	typedef enum
	{
		
		kMotorPosition_FL = 0,
		kMotorPosition_FR = 1,
		kMotorPosition_RL = 2,
		kMotorPosition_RR = 3
		
	} MotorPosition;
	
	virtual ~IQuadRectangularDriveBase () {};
	
	virtual void SetMotor ( MotorPosition Motor, double Value ) = 0;
	
};

#endif
