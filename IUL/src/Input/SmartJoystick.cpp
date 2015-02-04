#include "SmartJoystick.h"
#include <cmath>

SmartJoystick :: SmartJoystick ( int JoystickNumber, double Deadzone):
	Joystick ( JoystickNumber ),
	AxisDeadzone ( Deadzone )
{
};

double SmartJoystick :: GetXAxis ( bool WithDeadzone, double Deadzone)
{
	float X;
	X = this -> GetX ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( X , Deadzone);
	}
	return X;
};

double SmartJoystick :: GetYAxis ( bool WithDeadzone, double Deadzone)
{
	float Y;
	Y = this -> GetY ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( Y , Deadzone);
	}
	return Y;
};

double SmartJoystick :: GetZAxis ( bool WithDeadzone, double Deadzone)
{
	float Z;
	Z = this -> GetZ ();

	if ( WithDeadzone )
	{
		if ( Deadzone == 0.0 )
			Deadzone = AxisDeadzone;
		CalcDeadzone ( Z , Deadzone);
	}
	return Z;
};

bool SmartJoystick :: GetButtonState ( uint32_t ButtonNumber )
{
	double State;
	State = this -> GetRawButton ( ButtonNumber );

	if ( State == 0 )
		return true;
	else
		return false;
};

void SmartJoystick :: CalcDeadzone ( float & AxisIn, double & Deadzone )
{
	if ( abs ( AxisIn ) <= ( Deadzone / 100 ) )
		AxisIn = 0;
};
