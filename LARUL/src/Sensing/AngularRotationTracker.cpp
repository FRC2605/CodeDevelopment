#include "AngularRotationTracker.h"
#include <math.h>

AngularRotationTracker :: AngularRotationTracker ( IAngularInput * Input ):
	Input ( Input ),
	OutputUnit ( kUnit_Radians ),
	Last ( 0.0 ),
	Elapsed ( 0.0 )
{
	
	Last = Input -> GetAngle ();
	
};

AngularRotationTracker :: ~AngularRotationTracker ()
{
};

double AngularRotationTracker :: Get ()
{
	
	switch ( OutputUnit )
	{
	
	case kUnit_Rotations:
		
		return Elapsed / ( 2.0 * M_PI );
		
	case kUnit_Degrees:
		
		return 180.0 / M_PI * Elapsed;
		
	case kUnit_Radians:
	default:
		
		break;
		
	}
	
	return Elapsed;
	
};

void AngularRotationTracker :: Set ( double Value )
{
	
	Update ();
	
	Elapsed = Value;
	
};

void AngularRotationTracker :: SetOutputUnit ( AngularRotationTracker :: Unit OutputUnit )
{
	
	this -> OutputUnit = OutputUnit;
	
};

void AngularRotationTracker :: Update ()
{
	
	double CAngle = Input -> GetAngle ();
	
	if ( ( CAngle <= ( - M_PI / 2.0 ) ) && ( Last >= ( M_PI / 2.0 ) ) )
		CAngle += M_PI * 2.0;
	else if ( ( CAngle >= ( M_PI / 2.0 ) ) && ( Last <= ( - M_PI / 2.0 ) ) )
		Last += M_PI * 2.0;
	
	Elapsed += CAngle - Last;
	Last = CAngle;
	
};

void AngularRotationTracker :: SyncAngle ()
{
	
	Last = Input -> GetAngle ();
	
};
