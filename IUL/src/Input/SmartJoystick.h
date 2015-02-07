#ifndef IUL_SMARTJOYSTICK_H
#define IUL_SMARTJOYSTICK_H

#include <WPILib.h>
#include <cmath>

class SmartJoystick : public Joystick
{

public:

	SmartJoystick ( int ID, double DefaultDeadzone = 0.0 );

	double GetXAxis ();
	double GetXAxis ( double Deadzone );
	
	double GetYAxis ();
	double GetYAxis ( double Deadzone );
	
	double GetZAxis ();
	double GetZAxis ( double Deadzone );
	
	double GetSpecificAxis ( uint32_t Axis, double Deadzone );

	bool GetButtonState ( uint32_t ButtonID );

private:

	double CalcDeadzone ( double Value, double Deadzone );

	double DefaultDeadzone;

};




#endif
