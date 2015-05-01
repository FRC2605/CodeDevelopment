#ifndef LARUL_JOYSTICKOUTPUTINDICATOR_H
#define LARUL_JOYSTICKOUTPUTINDICATOR_H

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "../Indication/IBooleanIndicator.h"

/* JoystickOutputIndicator: A wrapper for WPILib's Joystick class which exposes a joystick output as an IBooleanIndicator
 *
 * This class implements IBooleanIndicator, so see IBooleanIndicator for a functional description of any methods not
 * detailed below.
 *
 *	JoystickOutputIndicator ( Joystick * Stick, int32_t Channel, bool DefaultState (OPTIONAL, Defaults to false) )
 *	--------------------------------------------------------------------------------------------------------------
 *	Contructs a JoystickOutputIndicator instance, using channel <Channel> on the joystick <Joystick> as the
 *	output. Initially, it will be set to <DefaultState>.
 *
*/

class JoystickOutputIndicator : public IBooleanIndicator
{
public:
	
	JoystickOutputIndicator ( Joystick * Stick, int32_t Channel, bool DefaultState = false );
	~JoystickOutputIndicator ();
	
	void Set ( bool Indication );
	
private:
	
	Joystick * Stick;
	int32_t Channel;
	
};

#endif
#endif
