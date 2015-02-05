#ifndef IUL_SMARTJOYSTICK_H
#define IUL_SMARTJOYSTICK_H

#include <WPILib.h>
#include <cmath>

class SmartJoystick : public Joystick
{

public:

	SmartJoystick ( int JoystickID,  double Deadzone = 0.0 );

	double GetXAxis ( bool DeadzoneEnabled = true, double Deadzone = 0.0 );
	double GetYAxis ( bool DeadzoneEnabled = true, double Deadzone = 0.0 );
	double GetZAxis ( bool DeadzoneEnabled = true, double Deadzone = 0.0 );

	bool GetButtonState ( uint32_t ButtonID );

private:

	double AxisDeadzone;
	void CalcDeadzone ( float & Value, double & Deadzone );

};




#endif
