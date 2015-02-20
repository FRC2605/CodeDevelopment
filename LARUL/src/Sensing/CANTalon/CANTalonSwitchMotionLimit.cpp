#include "CANTalonSwitchMotionLimit.h"

#ifndef NO_WPILIB

CANTalonSwitchMotionLimit :: CANTalonSwitchMotionLimit ( CANTalon * Controller, LimitBounding Bounding ):
	Controller ( Controller ),
	Bounding ( Bounding )
{
};

CANTalonSwitchMotionLimit :: ~CANTalonSwitchMotionLimit ()
{
};

IMotionLimit :: LimitBounding CANTalonSwitchMotionLimit :: GetBounding ()
{
	
	return Bounding;
	
};

bool CANTalonSwitchMotionLimit :: GetHighLimit ()
{
	
	return ! Controller -> GetForwardLimitOK ();
	
};

bool CANTalonSwitchMotionLimit :: GetLowLimit ()
{
	
	return ! Controller -> GetReverseLimitOK ();
	
};

#endif
