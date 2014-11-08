#include "BusyBoxMain.h"

BusyBoxMain :: BusyBoxMain ():
	Motor1 ( 1 ),
	Motor2 ( 2 ),
	Motor3 ( 3 ),
	Motor4 ( 4 ),
	Motor5 ( 5 ),
	Motor6 ( 6 ),
	Motor7 ( 7 ),
	Motor8 ( 8 ),
	Motor9 ( 9 ),
	Motor10 ( 10 ),
	Servo1 ( 2, 1 ),
	Servo2 ( 2, 2 ),
	JoystickA ( 1 ),
	JoystickB ( 2 ),
	Step1 ( & JoystickA, 9, 8 ),
	Step2 ( & JoystickB, 9, 8 ),
	LCD ( NULL ),
	Counter ( 0 ),
	Rotation ( 1, 2 )
{
	
	printf ( "Hello world!" );
	
	Step1.SetRange ( - 5, 5 );
	Step2.SetRange ( - 5, 5 );
	
	LCD = DriverStationLCD :: GetInstance ();
	
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line1, "2605 Busybox V. 1.0" );
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line2, "DISABLED!" );
	LCD -> UpdateLCD ();
	
};

BusyBoxMain :: ~BusyBoxMain ()
{	
};

void BusyBoxMain :: TeleopInit ()
{
	
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line2, "ENABLED!" );
	LCD -> UpdateLCD ();
	
	Step1.Set ( 0 );
	Step2.Set ( 0 );
	
	Rotation.Start ();
	
};

void BusyBoxMain :: TeleopPeriodic ()
{
	
	Step1.Update ();
	Step2.Update ();
	
	if ( Counter % 4 == 0 )
	{
		
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line3, "CIM 3: %d \%", Step1.Get () * 20 );
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line4, "CIM 8: %d \%", Step2.Get () * 20 );
		LCD -> PrintfLine ( DriverStationLCD :: kUser_Line5, "Encoder: %d", Rotation.Get () );
		LCD -> UpdateLCD ();
		
	}
	
	if ( JoystickA.GetRawButton ( 6 ) )
		Motor1.Set ( 1 );
	else if ( JoystickA.GetRawButton ( 7 ) )
		Motor1.Set ( - 1 );
	else
		Motor1.Set ( 0 );
	
	if ( JoystickA.GetRawButton ( 10 ) )
		Motor2.Set ( 1 );
	else if ( JoystickA.GetRawButton ( 11 ) )
		Motor2.Set ( - 1 );
	else
		Motor2.Set ( 0 );
	
	if ( JoystickB.GetRawButton ( 6 ) )
		Motor6.Set ( 1 );
	else if ( JoystickB.GetRawButton ( 7 ) )
		Motor6.Set ( - 1 );
	else
		Motor1.Set ( 0 );
	
	if ( JoystickB.GetRawButton ( 10 ) )
		Motor7.Set ( 1 );
	else if ( JoystickB.GetRawButton ( 11 ) )
		Motor7.Set ( - 1 );
	else
		Motor1.Set ( 0 );
	
	Motor4.Set ( JoystickA.GetX () );
	Motor5.Set ( JoystickA.GetY () );
	
	Motor9.Set ( JoystickB.GetX () );
	Motor10.Set ( JoystickB.GetY () );
	
	Motor3.Set ( static_cast <double> ( Step1.Get () ) / 5 );
	Motor8.Set ( static_cast <double> ( Step2.Get () ) / 5 );
	
	Counter ++;
	
};

void BusyBoxMain :: DisabledInit ()
{
	
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line2, "DISABLED!" );
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line3, "" );
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line4, "" );
	LCD -> PrintfLine ( DriverStationLCD :: kUser_Line5, "" );
	LCD -> UpdateLCD ();
	
	Motor1.Set ( 0 );
	Motor2.Set ( 0 );
	Motor3.Set ( 0 );
	Motor4.Set ( 0 );
	Motor5.Set ( 0 );
	Motor6.Set ( 0 );
	Motor7.Set ( 0 );
	Motor8.Set ( 0 );
	Motor9.Set ( 0 );
	Motor10.Set ( 0 );
	
	Servo1.Set ( 0 );
	Servo2.Set ( 0 );
	
	Rotation.Stop ();
	
};

START_ROBOT_CLASS ( BusyBoxMain );
