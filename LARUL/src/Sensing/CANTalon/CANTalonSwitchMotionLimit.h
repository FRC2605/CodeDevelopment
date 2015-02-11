#ifndef LARUL_CANTALONSWITCHMOTIONLIMIT_H
#define LARUL_CANTALONSWITCHMOTIONLIMIT_H

#include <WPILib.h>

#include "../IMotionLimit.h"

class CANTalonSwitchMotionLimit : public IMotionLimit
{
public:
	
	CANTalonSwitchMotionLimit ( CANTalon * Controller, LimitBounding Bounding );
	~CANTalonSwitchMotionLimit ();
	
	LimitBounding GetBounding ();
	
	bool GetHighLimit ();
	bool GetLowLimit ();
	
private:
	
	CANTalon * Controller;
	
	LimitBounding Bounding;
	
};

#endif
