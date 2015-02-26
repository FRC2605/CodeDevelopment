#include "WPISPI.h"

#ifndef NO_WPILIB

WPISPI :: WPISPI ( SPI * Port ):
	Port ( Port )
{
};

WPISPI :: ~WPISPI ()
{
};

void WPISPI :: SetClockRate ( double RateHZ )
{
	
	Port -> SetClockRate ( RateHZ );
	
}

void WPISPI :: SetBitOrder ( BitOrder Order )
{
	
	switch ( Order )
	{
	
	case kBitOrder_MSBFirst:
		
		Port -> SetMSBFirst ();
		
		break;
		
	case kBitOrder_LSBFirst:
		
		Port -> SetLSBFirst ();
		
		break;
	
	}
	
};

void WPISPI :: SetSampleTrigger ( SampleTrigger Trigger )
{
	
	switch ( Trigger )
	{
	
	case kSampleTrigger_RisingEdge:
		
		Port -> SetSampleDataOnRising ();
		
		break;
		
	case kSampleTrigger_FallingEdge:
		
		Port -> SetSampleDataOnFalling ();			
		
		break;	
		
	}
	
};

void WPISPI :: SetClockActiveHigh ( bool High )
{
	
	if ( High )
		Port -> SetClockActiveHigh ();
	else
		Port -> SetClockActiveLow ();
	
};

void WPISPI :: SetChipSelectActiveHigh ( bool High )
{
	
	if ( High )
		Port -> SetChipSelectActiveHigh ();
	else
		Port -> SetChipSelectActiveLow ();
	
};

int32_t WPISPI :: Read ( uint8_t * Buffer, uint8_t Max )
{
	
	return Port -> Read ( false, Buffer, Max );
	
};

int32_t WPISPI :: Write ( uint8_t * Buffer, uint8_t Length )
{
	
	return Port -> Write ( Buffer, Length );
	
};


#endif
