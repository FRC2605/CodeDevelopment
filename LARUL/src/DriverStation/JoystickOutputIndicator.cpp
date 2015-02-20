#include "JoystickOutputIndicator.h"

#ifndef NO_WPILIB

JoystickOutputIndicator :: JoystickOutputIndicator ( Joystick * Stick, int32_t Channel, bool DefaultState ):
	Stick ( Stick ),
	Channel ( Channel )
{
	
	Stick -> SetOutput ( Channel, DefaultState );
	
};

JoystickOutputIndicator :: ~JoystickOutputIndicator ()
{
};

void JoystickOutputIndicator :: Set ( bool Indication )
{
	
	Stick -> SetOutput ( Channel, Indication );
	
};

#endif
