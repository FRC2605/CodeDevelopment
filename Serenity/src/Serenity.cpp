#include "Serenity.h"

Serenity :: Serenity ():
	Config ( "/RobotConfig/Config.json" ),
	WheelFL ( 1 ),
	WheelFR ( 2 ),
	WheelRL ( 3 ),
	WheelRR ( 4 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	TriggerMotor ( 5 ),
	FlyWheel ( 6 ),
	FlyWheelEncoder ( 1, 2 ),
	TriggerSwitch ( 3 ),
	AngleInput ( 2 ),
	FlyWheelController ( 0.015, 0.002, 0.001, & FlyWheelEncoder, & FlyWheel, 0.016 ),
	TriggerController ( & TriggerMotor, & TriggerSwitch ),
	WinchController ( & AngleInput, & WinchMotor ),
	WinchMotor ( 7 ),
	JoyStrafe ( 1 ),
	JoyRotate ( 2 ),
	FlyWheelSpeed ( & JoyRotate, 9, 8 ),
	FlyWheelToggle ( & JoyRotate, 2 ),
	Trigger ( & JoyRotate, 1 ),
	FlyWheelEnabled ( false )
{
	
	Drive.SetInverted ( true, false, true, false );
	
	FlyWheelSpeed.SetRange ( 20, 50 );
	FlyWheelSpeed.SetStep ( 5 );
	
	LCD = DriverStationLCD :: GetInstance ();
	
	FlyWheelEncoder.SetPIDSourceParameter ( PIDSource :: kRate );
	FlyWheelEncoder.SetDistancePerPulse ( 1.0 / 256.0 );
	
	Config.Init ();
	
};

Serenity :: ~Serenity ()
{
	
	
	
};

void Serenity :: TeleopInit ()
{
	
	Drive.Enable ();
	
	FlyWheelSpeed.Set ( 20 );
	
	FlyWheelEnabled = false;
	
	FlyWheelEncoder.Reset ();
	FlyWheelEncoder.Start ();
	
	FlyWheelController.Enable ();
	TriggerController.Enable ();
	WinchController.Enable ();
	
};

void Serenity :: TeleopPeriodic ()
{
	
	FlyWheelSpeed.Update ();
	
	Drive.SetTranslation ( JoyStrafe.GetX (), JoyStrafe.GetY () );
	Drive.SetRotation ( - JoyRotate.GetX () );
	Drive.PushTransform ();
	
	if ( FlyWheelEnabled && Trigger.Update () )
		TriggerController.Trigger ();
	
	if ( FlyWheelToggle.Update () )
		FlyWheelEnabled = ! FlyWheelEnabled;
	
	if ( FlyWheelEnabled )
		FlyWheelController.SetSetpoint ( FlyWheelSpeed.Get () );
	else
		FlyWheelController.SetSetpoint ( 0 );
	
	TriggerController.Update ();
	
	if ( JoyRotate.GetRawButton ( 3 ) )
		WinchController.SetDrive ( JoyRotate.GetY (), false );
	else
		WinchController.SetDrive ( 0 );
	
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
	TriggerController.Disable ();
	WinchController.Disable ();
	
};

START_ROBOT_CLASS ( Serenity );
