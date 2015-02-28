#include "LDP6803.h"

LDP6803 :: LDP6803 ( ISPIInterface * Bus, uint32_t NumPixels ):
	Bus ( Bus ),
	NumPixels ( NumPixels ),
	Dirty ( true )
{
	
	
	
};

LDP6803 :: ~LDP6803 ()
{
};

uint32_t LDP6803 :: GetLength ()
{
	
	return NumPixels;
	
};

void LDP6803 :: SetLEDs ( uint32_t Start, color_t * Colors, uint32_t Length )
{
	
	if ( Start + Length >= NumPixels )
		return;
	
	for ( uint32_t i = 0; i < Length; i ++ )
	{
		
		color_t Color = Colors [ i ];
		
	}
	
	Dirty = true;
	
};

void LDP6803 :: SetLED ( uint32_t Index, color_t Color )
{
	
	if ( Index >= NumPixels )
		return;
	
	Dirty = true;
	
};

void LDP6803 :: Clear ( color_t ClearColor )
{
	
	
	
	Dirty = true;
	
};

void LDP6803 :: MarkBufferDirty ()
{
	
	Dirty = true;
	
};
