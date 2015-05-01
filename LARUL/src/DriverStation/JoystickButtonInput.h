#ifndef LARUL_JOYSTICKBUTTONINPUT_H
#define LARUL_JOYSTICKBUTTONINPUT_H

#include "../Sensing/IBooleanInput.h"

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

/* JoystickButtonInput: A wrapper for WPILib's Joystick class which exposes an individual button as an IBooleanInput.
 *
 * This class implements IBooleanInput, so for any method not detailed below, see IBooleanInput for a functional
 * description.
 *
 * Methods:
 *
 *	JoystickButtonInput ( Joystick * Stick, uint32_t Button )
 *	---------------------------------------------------------
 *	Constructs the JoystickButtonInput to use the joystick
 *	<Stick> and reference it's button by the index <Button>.
 *
*/

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

#endif
