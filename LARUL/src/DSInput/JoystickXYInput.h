#ifndef LARUL_JOYSTICKXYINPUT_H
#define LATUL_JOYSTICKXYINPUT_H

#include "../Sensing/IXYInput.h"

#include <WPILib.h>

class JoystickXYInput : public IXYInput
{
public:
	
	JoystickXYInput ( Joystick * Stick );
	~JoystickXYInput ();
	
	void SetRawAxies ( int32_t XAxis = Joystick :: kDefaultXAxis, int32_t YAxis = Joystick :: kDefaultYAxis );
	
	void SetDeadband ( double Deadband );
	
	void SetInversion ( bool X, bool Y );
	
	double GetX ();
	double GetY ();
	
	double GetScale ();
	
private:
	
	Joystick * Stick;
	
	double Deadband;
	
	int32_t XAxis;
	int32_t YAxis;
	
	bool InvertX;
	bool InvertY;
	
};

#endif
