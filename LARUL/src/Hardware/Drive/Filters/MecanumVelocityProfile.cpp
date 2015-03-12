#include <math.h>
#include "MecanumVelocityProfile.h"

MecanumVelocityProfile :: MecanumVelocityProfile ( double Exponent ):
	Exponent ( Exponent ),
	Magnitude ( 0.0 ),
	Direction ( 0.0 )
{
};

MecanumVelocityProfile :: ~MecanumVelocityProfile ()
{
};

void MecanumVelocityProfile :: SetExponent ( double Exponent )
{

	this -> Exponent = Exponent;

};

void MecanumVelocityProfile :: Compute ( double Magnitude, double Direction )
{

	this -> Magnitude = powf ( Magnitude, Exponent );
	this -> Direction = Direction;

};

double MecanumVelocityProfile :: ReadA ()
{

	return Magnitude;

};

double MecanumVelocityProfile :: ReadB ()
{

	return Direction;

};

void MecanumVelocityProfile :: Reset ()
{

	this -> Magnitude = 0.0;

};
