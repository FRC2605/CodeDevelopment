#include "PowerProfile.h"

#ifndef NO_WPILIB

PowerProfile :: PowerProfile ( const char * Name ):
	Channels (),
	SubProfiles (),
	Name ( Name )
{
};

PowerProfile :: PowerProfile ( const std :: string Name ):
	Channels (),
	SubProfiles (),
	Name ( Name )
{
};

PowerProfile :: ~PowerProfile ()
{
}

void PowerProfile :: AddChannel ( uint8_t PDPChannel )
{
	
	if ( Channels.IndexOf ( PDPChannel ) != - 1 )
		return;
	
	Channels.Push ( PDPChannel );
	
};

void PowerProfile :: RemoveChannel ( uint8_t PDPChannel )
{
	
	int32_t Index = Channels.IndexOf ( PDPChannel );
	
	if ( Index == - 1 )
		return;
	
	Channels.Remove ( Index, 1 );
	
};

void PowerProfile :: RemoveSubProfile ( PowerProfile * Profile )
{
	
	int32_t Index = SubProfiles.IndexOf ( Profile );
	
	if ( Index == - 1 )
		return;
	
	SubProfiles.Remove ( Index, 1 );
	
};

void PowerProfile :: AddSubProfile ( PowerProfile * Profile )
{
	
	if ( SubProfiles.IndexOf ( Profile ) != - 1 )
		return;
	
	SubProfiles.Push ( Profile );
	
}

const std :: string PowerProfile :: GetName ()
{
	
	return Name;
	
};

double PowerProfile :: GetCurrent ()
{
	
	double Current = 0.0;
	
	uint32_t i;
	
	for ( i = 0; i < Channels.Length (); i ++ )
		Current += Power :: GetPDP () -> GetCurrent ( Channels [ i ] );
	
	for ( i = 0; i < SubProfiles.Length (); i ++ )
		Current += SubProfiles [ i ] -> GetCurrent ();
	
	return Current;
	
};

double PowerProfile :: GetCurrentPortion ()
{
	
	return GetCurrent () / Power :: GetPDP () -> GetTotalCurrent ();
	
};

uint8_t PowerProfile :: GetHighestDemandChannel ()
{
	
	uint8_t HighestIndex = 255;
	
	double MCurrent = 0.0;
	
	uint32_t i;
	
	for ( i = 0; i < Channels.Length (); i ++ )
	{
		
		double Current = Power :: GetPDP () -> GetCurrent ( Channels [ i ] );
		
		if ( Current > MCurrent )
		{
			
			MCurrent = Current;
			HighestIndex = i;
			
		}
		
	}
	
	for ( i = 0; i < SubProfiles.Length (); i ++ )
	{
		
		uint8_t HighestSubChannel = SubProfiles [ i ] -> GetHighestDemandChannel ();
		double Current = Power :: GetPDP () -> GetCurrent ( Channels [ HighestSubChannel ] );
		
		if ( Current > MCurrent )
		{
			
			MCurrent = Current;
			HighestIndex = HighestSubChannel;
			
		}
		
	}
	
	return HighestIndex;
	
};

#endif
