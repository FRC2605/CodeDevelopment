#include "Hardware/Drive/Filters/MecanumMagDirOrientationOffset.h"

MecanumMagDirOrientationOffset :: MecanumMagDirOrientationOffset ( IAngularInput * Angle ):
	Angle ( Angle ),
	Offset ( 0.0 ),
	Magnitude ( 0.0 ),
	Direction ( 0.0 )
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
	
	Direction -= Angle -> GetAngle ();
	Direction -= Offset;
	
	this -> Direction = Direction;
	
};

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
