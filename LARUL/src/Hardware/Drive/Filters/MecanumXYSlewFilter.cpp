#include "MecanumXYSlewFilter.h"

#include <math.h>

MecanumXYSlewFilter :: MecanumXYSlewFilter ( double MaxSlew, double MaxDelta ):
	MaxSlew ( MaxSlew ),
	MaxDelta ( MaxDelta ),
	LX ( 0.0 ),
	LY ( 0.0 ),
	DeltaTimer ()
{
	
	DeltaTimer.Start ();
	
};

MecanumXYSlewFilter :: ~MecanumXYSlewFilter ()
{
};

void MecanumXYSlewFilter :: Compute ( double FeedA, double FeedB )
{
	
	double DeltaX = FeedA - LX;
	double DeltaY = FeedB - LY;
	
	if ( MaxSlew != 0.0 )
	{
		
		double PortionalSlew = MaxSlew / fmin ( DeltaTimer.GetTimeS (), MaxDelta );
		DeltaTimer.Restart ();
		
		if ( abs ( DeltaX ) > PortionalSlew )
			DeltaX = ( DeltaX > 0 ) ? PortionalSlew : - PortionalSlew;
		
		if ( abs ( DeltaY ) > PortionalSlew )
			DeltaY = ( DeltaY > 0 ) ? PortionalSlew : - PortionalSlew; 
		
	}
	
	LX += DeltaX;
	LY += DeltaY;
	
};

double MecanumXYSlewFilter :: ReadA ()
{
	
	return LX;
	
};

double MecanumXYSlewFilter :: ReadB ()
{
	
	return LY;
	
};

void MecanumXYSlewFilter :: Reset ()
{
	
	LX = 0;
	LY = 0;
	
	DeltaTimer.Restart ();
	
};
