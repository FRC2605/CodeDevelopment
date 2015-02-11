#ifndef LARUL_JOYSTICKBUTTONINPUT_H
#define LARUL_JOYSTICKBUTTONINPUT_H

#include <WPILib.h>

#include "../Sensing/IBooleanInput.h"

class JoystickButtonInput : public IBooleanInput
{
public:
	
	JoystickButtonInput ( Joystick * Stick, uint32_t Button );
	virtual ~JoystickButtonInput ();
	
	bool GetBoolean ();
	
private:
	
	Joystick * Stick;
	uint32_t Button;
	
};

#endif
