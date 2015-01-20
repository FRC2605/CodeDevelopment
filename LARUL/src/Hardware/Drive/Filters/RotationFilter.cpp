#include "math.h"
#include "RotationFilter.h"

RotationFilter ::	RotationFilter (double Exponent):
	Exponent ( Exponent ),
	Magnitude ( 0.0 )
{
};

RotationFilter ::	~RotationFilter ()
{
};

void RotationFilter :: Compute ( double Magnitude )
{
	this -> Magnitude = powf ( Magnitude, Exponent );
};

double RotationFilter :: Read ()
{
	return Magnitude;
};

void RotationFilter :: Reset ()
{
};



