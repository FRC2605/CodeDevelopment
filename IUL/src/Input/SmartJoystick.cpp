#include "SmartJoystick.h"

/*
* Copyright (C) 2015 Ian Roth
* WheelFRC Team Sehome Semonsters 2605
*/

SmartJoystick :: SmartJoystick ( int ID, double DefaultDeadzone ):
	Joystick ( ID ),
	DefaultDeadzone ( DefaultDeadzone )
{
};

double SmartJoystick :: GetXAxis ()
{
	
	return CalcDeadzone ( GetX (), DefaultDeadzone );
	
};

double SmartJoystick :: GetXAxis ( double Deadzone )
{
	
	return CalcDeadzone ( GetX (),  Deadzone );
	
};

double SmartJoystick :: GetYAxis ()
{
	
	return CalcDeadzone ( GetY (), DefaultDeadzone );
	
}

double SmartJoystick :: GetYAxis ( double Deadzone )
{
	
	return CalcDeadzone ( GetY (), Deadzone );
	
};

double SmartJoystick :: GetZAxis ()
{
	
	return CalcDeadzone ( GetZ (), DefaultDeadzone );
	
}

double SmartJoystick :: GetZAxis ( double Deadzone )
{
	
	return CalcDeadzone ( GetZ (), Deadzone );
	
};

double SmartJoystick :: GetSpecificAxis ( uint32_t Axis, double Deadzone )
{
	
	return CalcDeadzone ( GetRawAxis ( Axis ), Deadzone );
	
};

double SmartJoystick :: GetSpecificAxis ( uint32_t Axis )
{
	
	return CalcDeadzone ( GetRawAxis ( Axis ), DefaultDeadzone );
	
};

bool SmartJoystick :: GetButtonState ( uint32_t ButtonID )
{
	
	return static_cast <bool> ( GetRawButton ( ButtonID ) );
	
};

double SmartJoystick :: CalcDeadzone ( double Value, double Deadzone )
{
	
	if ( abs ( Value ) <= Deadzone )
		return 0;
	
	return Value;
	
};
