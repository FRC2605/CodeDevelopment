#include "Serenity.h"

Serenity :: Serenity ():
	WheelFL ( 1 ),
	WheelFR ( 2 ),
	WheelRL ( 3 ),
	WheelRR ( 4 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	TriggerMotor ( 5 ),
	FlyWheel ( 6 ),
	FlyWheelEncoder ( 1, 2 ),
	FlyWheelController ( 0.015, 0.002, 0.001, & FlyWheelEncoder, & FlyWheel, 0.016 ),
	WinchMotor ( 7 ),
	JoyStrafe ( 1 ),
	JoyRotate ( 2 ),
	FlyWheelSpeed ( & JoyRotate, 9, 8 ),
	FlyWheelToggle ( & JoyRotate, 2 ),
	FlyWheelEnabled ( false )
{
	
	Drive.SetInverted ( true, false, true, false );
	
	FlyWheelSpeed.SetRange ( 0, 40 );
	FlyWheelSpeed.SetStep ( 5 );
	
	LCD = DriverStationLCD :: GetInstance ();
	
	FlyWheelEncoder.SetPIDSourceParameter ( PIDSource :: kRate );
	FlyWheelEncoder.SetDistancePerPulse ( 1.0 / 256.0 );
	
};

Serenity :: ~Serenity ()
{
	
	
	
};

void Serenity :: TeleopInit ()
{
	
	Drive.Enable ();
	
	FlyWheelSpeed.Set ( 0 );
	
	FlyWheelEncoder.Reset ();
	FlyWheelEncoder.Start ();
	
	FlyWheelController.Enable ();
	
};

void Serenity :: TeleopPeriodic ()
{
	
	FlyWheelSpeed.Update ();
	
	Drive.SetTranslation ( JoyStrafe.GetX (), JoyStrafe.GetY () );
	Drive.SetRotation ( JoyRotate.GetX () );
	Drive.PushTransform ();
	
	if ( FlyWheelToggle.Update () )
		FlyWheelEnabled = ! FlyWheelEnabled;
	
	if ( FlyWheelEnabled )
		FlyWheelController.SetSetpoint ( FlyWheelSpeed.Get () );
	else
		FlyWheelController.SetSetpoint ( 0 );
	
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line1, "E: %s S: %i\n", FlyWheelEnabled ? "Y" : "N", FlyWheelSpeed.Get () );
	LCD -> UpdateLCD ();
	
	
};

void Serenity :: TestInit ()
{
	
	
	
};

void Serenity :: TestPeriodic ()
{
	
	
	
	
	
};

void Serenity :: DisabledInit ()
{
	
	Drive.Disable ();
	
	FlyWheelEncoder.Stop ();
	
	FlyWheelController.Disable ();
	
};

START_ROBOT_CLASS ( Serenity );
