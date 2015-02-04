#include "SmartJoystick.h"

/*
* Copyright (C) 2015 Ian Roth
* WheelFRC Team Sehome Semonsters 2605
*/

SmartJoystick :: SmartJoystick ( int JoystickID, double Deadzone):
	Joystick ( JoystickID ),
	AxisDeadzone ( Deadzone )
{
};

double SmartJoystick :: GetXAxis ( bool WithDeadzone, double Deadzone)
{
	float X;
	X = this -> GetX ();

	if ( WithDeadzone )
	{
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
		CalcDeadzone ( Z , Deadzone);
	}
	return Z;
};

bool SmartJoystick :: GetButtonState ( uint32_t ButtonID )
{
	double State;
	State = this -> GetRawButton ( ButtonID );

	if ( State == 0 )

		return true;

	else

		return false;
};

void SmartJoystick :: CalcDeadzone ( float & Value, double & Deadzone )
{
	if ( Deadzone == 0.0 )
		Deadzone = AxisDeadzone;
	if ( abs ( Value ) <= ( Deadzone / 100 ) )
		Value = 0;
};
