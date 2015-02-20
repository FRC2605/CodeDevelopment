#include "JoystickButtonInput.h"

#ifndef NO_WPILIB

JoystickButtonInput :: JoystickButtonInput ( Joystick * Stick, uint32_t Button ):
	Stick ( Stick ),
	Button ( Button )
{
};

JoystickButtonInput :: ~JoystickButtonInput ()
{
};

bool JoystickButtonInput :: GetBoolean ()
{
	
	return Stick -> GetRawButton ( Button );
	
};

#endif
