#include "ClosedLoopMain.h"

ClosedLoopMain :: ClosedLoopMain ():
	MotorRate ( 1, 2 ),
	MotorOut ( 7 ),
	MotorController ( 0.015, 0.002, 0.001, & MotorRate, & MotorOut, 0.016 ),
	Joy ( 1 ),
	Step ( & Joy, 9, 8 ),
	Counter ( 0 )
{
	
	LCD = DriverStationLCD :: GetInstance ();
	
	MotorRate.SetPIDSourceParameter ( PIDSource :: kRate );
	MotorRate.SetDistancePerPulse ( 1.0 / 256.0 );
	
	Step.SetRange ( - 100, 100 );
	Step.SetStep ( 5 );
	
};

ClosedLoopMain :: ~ClosedLoopMain ()
{
	
	
	
};

void ClosedLoopMain :: TeleopInit ()
{
	
	MotorRate.Reset ();
	MotorRate.Start ();
	
	MotorController.Enable ();
	
	Counter = 0;
	
};

void ClosedLoopMain :: TeleopPeriodic ()
{
	
	Step.Update ();
	
	if ( ( Counter & 0x07 ) == 0 )
	{
		
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line1, "Position: %f", static_cast <double> ( MotorRate.Get () ) / 256 );
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line2, "Speed: %f", MotorRate.GetRate () );
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line3, "Setpoint: %f", Joy.GetY () * 40 );
		LCD -> UpdateLCD ();
		
	}
	
	MotorController.SetSetpoint ( Joy.GetY () * 40 );
	
};
	
void ClosedLoopMain :: DisabledInit ()
{
	
	MotorController.Disable ();
	
	MotorRate.Stop ();
	
};

START_ROBOT_CLASS ( ClosedLoopMain );
