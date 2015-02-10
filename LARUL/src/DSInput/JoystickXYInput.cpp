#include "JoystickXYInput.h"

JoystickXYInput :: JoystickXYInput ( Joystick * Stick ):
	Stick ( Stick ),
	Deadband ( 0.0 ),
	XAxis ( Joystick :: kDefaultXAxis ),
	YAxis ( Joystick :: kDefaultYAxis ),
	InvertX ( false ),
	InvertY ( false )
{
};

JoystickXYInput :: ~JoystickXYInput ()
{
};

void JoystickXYInput :: SetDeadband ( double Deadband )
{
	
	this -> Deadband = Deadband;
	
};

void JoystickXYInput :: SetInversion ( bool X, bool Y )
{
	
	InvertX = X;
	InvertY = Y;
	
};

void JoystickXYInput :: SetRawAxies ( int32_t XAxis, int32_t YAxis )
{
	
	this -> XAxis = XAxis;
	this -> YAxis = YAxis;
	
};

double JoystickXYInput :: GetX ()
{
	
	double RawX = Stick -> GetRawAxis ( XAxis );
	
	if ( abs ( RawX ) - Deadband < 0 )
		RawX = 0.0;
	
	if ( InvertX )
		RawX = - RawX;
	
	return RawX;
	
};

double JoystickXYInput :: GetY ()
{
	
	double RawY = Stick -> GetRawAxis ( YAxis );
	
	if ( abs ( RawY ) - Deadband < 0 )
		RawY = 0.0;
	
	if ( InvertY )
			RawY = - RawY;
	
	return RawY;
	
};

double JoystickXYInput :: GetScale ()
{
	
	return 1.0;
	
};
