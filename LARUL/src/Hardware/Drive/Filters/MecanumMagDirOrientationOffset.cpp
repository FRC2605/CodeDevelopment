#include "MecanumMagDirOrientationOffset.h"

MecanumMagDirOrientationOffset :: MecanumMagDirOrientationOffset ( IAngularInput * Angle ):
	Angle ( Angle ),
	Offset ( 0.0 ),
	Magnitude ( 0.0 ),
	Direction ( 0.0 ),
	Enabled ( true )
{
};

MecanumMagDirOrientationOffset :: ~MecanumMagDirOrientationOffset ()
{
};

void MecanumMagDirOrientationOffset :: CalibrateZero ()
{
	
	Offset = Angle -> GetAngle ();
	
};

void MecanumMagDirOrientationOffset :: Compute ( double Magnitude, double Direction )
{
	
	this -> Magnitude = Magnitude;
	
	if ( Enabled )
		Direction -= ( Angle -> GetAngle () - Offset );
	
	this -> Direction = Direction;
	
};

void MecanumMagDirOrientationOffset :: SetEnabled ( bool Enabled )
{
	
	this -> Enabled = Enabled;
	
}

double MecanumMagDirOrientationOffset :: ReadA ()
{
	
	return Magnitude;
	
};

double MecanumMagDirOrientationOffset :: ReadB ()
{
	
	return Direction;
	
};

void MecanumMagDirOrientationOffset :: Reset ()
{
};
