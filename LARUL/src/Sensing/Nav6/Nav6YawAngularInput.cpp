#include "Nav6YawAngularInput.h"

#include <math.h>

Nav6YawAngularInput :: Nav6YawAngularInput ( Nav6 * Nav ):
	Nav ( Nav )
{
};

Nav6YawAngularInput :: ~Nav6YawAngularInput ()
{
};

double Nav6YawAngularInput :: GetAngle ()
{
	
	return Nav -> GetYaw ();
	
};
