#ifndef SMARTJOYSTICK_H_
#define SMARTJOYSTICK_H_

#include "WPILib.h"

class SmartJoystick : public Joystick
{

public:
	SmartJoystick ( int JoystickNumber,  double Deadzone = 0.0 );

	double GetXAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );
	double GetYAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );
	double GetZAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );
	bool GetButtonState ( uint32_t ButtonNumber );
private:
	double AxisDeadzone;
	void CalcDeadzone ( float & AxisIn, double & Deadzone );
};




#endif
