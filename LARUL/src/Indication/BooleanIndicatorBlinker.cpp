#include "BooleanIndicatorBlinker.h"

#include <math.h>

BooleanIndicatorBlinker :: BooleanIndicatorBlinker ( double Frequencey, IBooleanIndicator * Indicator, BooleanIndicatorBlinker :: Mode InitialMode ):
	Indicator ( Indicator ),
	Timer (),
	Period ( 1000 / Frequencey ),
	IMode ( InitialMode )
{
	
	Timer.Start ();
	
};

BooleanIndicatorBlinker :: ~BooleanIndicatorBlinker ()
{
};

void BooleanIndicatorBlinker :: Update ()
{
	
	if ( Indicator != NULL )
	{
		
		switch ( IMode )
		{
		
		case BooleanIndicatorBlinker :: kMode_Off:
			
			Indicator -> Set ( false );
			
			break;
		
		case BooleanIndicatorBlinker :: kMode_On:
			
			Indicator -> Set ( true );
			
			break;
		
		case BooleanIndicatorBlinker :: kMode_Blinking:
			
			double Time = Timer.GetTimeMS ();
			Indicator -> Set ( fmod ( Time, Period ) > Period / 2 );
			
			break;
		
		}
		
	}
	
};

void BooleanIndicatorBlinker :: SetMode ( BooleanIndicatorBlinker :: Mode IMode )
{
	
	this -> IMode = IMode;
	
};

void BooleanIndicatorBlinker :: SetFrequencey ( double Frequencey )
{
	
	Period = 1000 / Frequencey;
	
};

void BooleanIndicatorBlinker :: SetIndicator ( IBooleanIndicator * Indicator, bool OldEndState )
{
	
	if ( this -> Indicator != NULL )
		this -> Indicator -> Set ( OldEndState );
		
	this -> Indicator = Indicator;
	
};
