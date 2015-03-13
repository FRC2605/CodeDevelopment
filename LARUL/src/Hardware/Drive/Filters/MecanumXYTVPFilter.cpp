#include "MecanumXYTVPFilter.h"

#include <math.h>

MecanumXYTVPFilter :: MecanumXYTVPFilter ( double VRamp ):
	CX ( 0.0 ),
	CY ( 0.0 ),
	X ( 0.0 ),
	Y ( 0.0 ),
	VRamp ( VRamp ),
	Delta ()
{

	Delta.Start ();

};

MecanumXYTVPFilter :: ~MecanumXYTVPFilter ()
{
};

void MecanumXYTVPFilter :: SetVRamp ( double VRamp )
{

	this -> VRamp = VRamp;

};

void MecanumXYTVPFilter :: Compute ( double FeedA, double FeedB )
{

	X = FeedA;
	Y = FeedB;

	double Delt = Delta.GetTimeS ();
	Delta.Restart ();

	double XDiff = X - CX;
	double YDiff = Y - CY;

	if ( ( fabs ( XDiff ) < Delt * VRamp ) || ( VRamp == 0.0 ) )
		CX = X;
	else
		CX += ( ( XDiff > 0 ) ? VRamp : - VRamp ) * Delt;

	if ( ( fabs ( YDiff ) < Delt * VRamp ) || ( VRamp == 0.0 ) )
		CY = Y;
	else
		CY += ( ( YDiff > 0 ) ? VRamp : - VRamp ) * Delt;

};

double MecanumXYTVPFilter :: ReadA ()
{

	return CX;

};

double MecanumXYTVPFilter :: ReadB ()
{

	return CY;

};

void MecanumXYTVPFilter :: Reset ()
{

	Delta.Restart ();

};

