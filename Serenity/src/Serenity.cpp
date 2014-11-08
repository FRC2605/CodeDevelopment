#include "Serenity.h"

Serenity :: Serenity ():
	WheelFL ( 1 ),
	WheelFR ( 2 ),
	WheelRL ( 3 ),
	WheelRR ( 4 ),
	Flywheel ( 5 ),
	Trigger ( 6 ),
	WinchMotor ( 7 ),
	WinchAngle ( 1 ),
	TriggerSwitch ( 1 ),
	JoyStrafe ( 1 ),
	JoyRotate ( 2 ),
	ShooterSpeed ( & JoyRotate, 8, 9 ),
	TriggerMonitor ( & JoyRotate, 1 ),
	ToggleMonitor ( & JoyRotate, 2 ),
	Drive ( & WheelFL, & WheelFR, & WheelRL, & WheelRR ),
	ShooterWinch ( & WinchAngle, & WinchMotor ),
	DiscShooter ( & Flywheel, & Trigger, & TriggerSwitch ),
	Config (),
	WinchConfiguration ( & ShooterWinch )
{
	
	ShooterSpeed.SetRange ( 0, 10 );
	
	Config.Init ();
	
	Config.AddConfigSection ( & WinchConfiguration );
	WinchConfiguration.LoadConfig ();
	
	Drive.SetSineInversion ( true );
	
	DiscShooter.SetFlywheelScale ( 1 );
	
};

Serenity :: ~Serenity ()
{
	
	
	
};

void Serenity :: TeleopInit ()
{
	
	Drive.Enable ();
	//ShooterWinch.Enable ();
	DiscShooter.SetEnabled ( false );
	
};

void Serenity :: TeleopPeriodic ()
{
	
	ShooterSpeed.Update ();
	
	Drive.SetTranslation ( JoyStrafe.GetX (), JoyStrafe.GetY () );
	Drive.SetRotation ( - JoyRotate.GetX () );
	
	/*if ( JoyRotate.GetRawButton ( 2 ) )
		ShooterWinch.SetDrive ( JoyRotate.GetY (), true );
	else
		ShooterWinch.SetDrive ( 0.0 );*/
	
	if ( TriggerMonitor.Update () )
		DiscShooter.Trigger ();
	
	if ( ToggleMonitor.Update () )
		DiscShooter.SetEnabled ( ! DiscShooter.GetEnabled () );
	
	DiscShooter.SetFlywheelSpeed ( (double) ShooterSpeed.Get () / 10 );
	
	DiscShooter.Update ();
	Drive.PushTransform ();
	
};

void Serenity :: TestInit ()
{
	
	ShooterWinch.Enable ();
	
};

void Serenity :: TestPeriodic ()
{
	
	ShooterSpeed.Update ();
	
	//ShooterWinch.SetDrive ( JoyRotate.GetY () / 5, false );
	
	if ( JoyRotate.GetRawButton ( 11 ) )
	{
		
		ShooterWinch.CalibrateHighAngle ();
		WinchConfiguration.WriteConfig ();
		
	}
	
	else if ( JoyRotate.GetRawButton ( 6 ) )
	{
		
		ShooterWinch.CalibrateLowAngle ();
		WinchConfiguration.WriteConfig ();
		
	}
	
	//if ( ToggleMonitor.Update () )
	//	Config.Write ();
	
};

void Serenity :: DisabledInit ()
{
	
	Drive.Disable ();
	ShooterWinch.Disable ();
	DiscShooter.SetEnabled ( false );
	
};

START_ROBOT_CLASS ( Serenity );
