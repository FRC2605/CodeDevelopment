#include <DriverStation/NumericStepper.h>

#ifndef NO_WPILIB

NumericStepper :: NumericStepper ( GenericHID * Device, uint32_t UpButton, uint32_t DownButton ):
	Device ( Device ),
	UpButton ( UpButton ),
	DownButton ( DownButton ),
	Value ( 0 ),
	Max ( INT32_MAX ),
	Min ( INT32_MIN ),
	Step ( 1 ),
	UpButtonState ( false ),
	DownButtonState ( false )
{	
};

NumericStepper :: ~NumericStepper ()
{
};

void NumericStepper :: SetRange ( int32_t Min, int32_t Max )
{

	this -> Min = Min;
	this -> Max = Max;

};

void NumericStepper :: SetStep ( int32_t Step )
{

	this -> Step = Step;

};

int32_t NumericStepper :: Get ()
{

	return Value;

};

void NumericStepper :: Set ( int32_t Value )
{

	if ( Value > Max )
		Value = Max;

	if ( Value < Min )
		Value = Min;

	this -> Value = Value;

};

void NumericStepper :: Update ()
{

	bool NewUpButtonState = Device -> GetRawButton ( UpButton );
	bool NewDownButtonState = Device -> GetRawButton ( DownButton );

	if ( ! UpButtonState && NewUpButtonState )
		Value += Step;

	if ( ! DownButtonState && NewDownButtonState )
		Value -= Step;

	if ( Value > Max )
		Value = Max;

	if ( Value < Min )
		Value = Min;

	UpButtonState = NewUpButtonState;
	DownButtonState = NewDownButtonState;

};

#endif
