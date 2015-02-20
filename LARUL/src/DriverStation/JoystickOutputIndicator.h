#ifndef LARUL_JOYSTICKOUTPUTINDICATOR_H
#define LARUL_JOYSTICKOUTPUTINDICATOR_H

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "../Indication/IBooleanIndicator.h"

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
