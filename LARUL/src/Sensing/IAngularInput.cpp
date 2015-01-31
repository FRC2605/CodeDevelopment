#include <math.h>
#include "IAngularInput.h"

IAngularInput :: ~IAngularInput ()
{
};

double IAngularInput :: GetScalar ()
{
	
	return GetAngle ();
	
};

IScalarInput :: ScalarLimit IAngularInput :: GetScalarLimitType ()
{
	
	return IScalarInput :: kScalarLimit_Range;
	
};

double IAngularInput :: GetLimitParam ( ScalarLimitParam Param )
{
	
	switch ( Param )
	{
	case IScalarInput :: kScalarLimitParam_HighLimit:
		return M_PI;
		
	case IScalarInput :: kScalarLimitParam_LowLimit:
		return - M_PI;
		
	default:
		break;
		
	}
	
	return NAN;
	
};


