#include "Nav6YawAngle.h"

#include <math.h>

Nav6YawAngle :: Nav6YawAngle ( IMU * Nav6 ):
	Nav6 ( Nav6 )
{
};

Nav6YawAngle :: ~Nav6YawAngle ()
{
};

double Nav6YawAngle :: GetAngle ()
{
	
	return ( Nav6 -> GetYaw () / 180.0 ) * M_PI;
	
};


