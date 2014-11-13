#include "Winch.h"

Winch :: Winch ( AnalogChannel * Angle, SpeedController * WinchMotor ):
	Angle ( Angle ),
	WinchMotor ( WinchMotor ),
	DriveScale ( 1.0 ),
	Inverted ( false ),
	Enabled ( false ),
	HighLimit ( 1.0 ),
	LowLimit ( 0.0 ),
	Scale ( 1.25 ),
	Offset ( 0.1 )
{	
};

Winch :: ~Winch ()
{
	
	
	
};

void Winch :: SetInverted ( bool Inverted )
{
	
	this -> Inverted = Inverted;
	
};

void Winch :: SetAngleScale ( double Scale )
{
	
	this -> Scale = Scale;
	
};

double Winch :: GetAngleScale ()
{
	
	return Scale;
	
};

void Winch :: SetAngleOffset ( double Offset )
{
	
	this -> Offset = Offset;
	
};

double Winch :: GetAngleOffset ()
{
	
	return Offset;
	
};

void Winch :: CalibrateLowAngle ()
{
	
	LowLimit = ( ( ( Angle -> GetAverageVoltage () + 10 ) / 20 ) - Offset ) * Scale;
	
};

void Winch :: CalibrateHighAngle ()
{
	
	HighLimit = ( ( ( Angle -> GetAverageVoltage () + 10 ) / 20 ) - Offset ) * Scale;
	
};

void Winch :: SetDriveScale ( double DriveScale )
{
	
	this -> DriveScale = DriveScale;
	
};

void Winch :: SetDrive ( double Drive, bool Limit )
{
	
	if ( ! Enabled )
	{
		
		WinchMotor -> Set ( 0 );
		
		return;
		
	}
	
	if ( Limit )
	{
		
		double SHAngle = ( ( ( Angle -> GetAverageVoltage () + 10 ) / 20 ) - Offset ) * Scale;
		
		if ( ( SHAngle > HighLimit && Drive * DriveScale * ( Inverted ? - 1.0 : 1.0 ) > 0.0 ) || ( SHAngle < LowLimit && Drive * DriveScale * ( Inverted ? - 1.0 : 1.0 ) < 0.0 ) )
		{
			
			WinchMotor -> Set ( 0 );
			
			return;
			
		}
		
	}
	
	WinchMotor -> Set ( Drive * DriveScale * ( Inverted ? - 1.0 : 1.0 ) );
	
};

void Winch :: Enable ()
{
	
	Enabled = true;
	
};

void Winch :: Disable ()
{
	
	WinchMotor -> Disable ();
	
	Enabled = true;
	
};
