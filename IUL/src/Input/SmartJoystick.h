#ifndef IUL_SMARTJOYSTICK_H_
#define IUL_SMARTJOYSTICK_H_

#include <WPILib.h>
#include <cmath>

class SmartJoystick : public Joystick
{

public:

	SmartJoystick ( int JoystickID,  double Deadzone = 0.0 );

	double GetXAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );
	double GetYAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );
	double GetZAxis ( bool WithDeadzone = true, double Deadzone = 0.0 );

	bool GetButtonState ( uint32_t ButtonID );

private:

	double AxisDeadzone;
	void CalcDeadzone ( float & Value, double & Deadzone );

};




#endif
