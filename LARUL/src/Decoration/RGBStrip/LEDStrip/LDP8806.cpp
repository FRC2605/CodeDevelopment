#include "LDP8806.h"

LDP8806 :: LDP8806 ( ISPIInterface * Bus, uint32_t NumPixels ):
	Bus ( Bus ),
	NumPixels ( NumPixels ),
	Dirty ( true )
{
	
	ColorBuffer = new uint8_t [ NumPixels * 3 ];
	ZeroBuffer = new uint8_t [ ( NumPixels + 31 ) / 32 ];
	
	uint32_t i;
	
	for ( i = 0; i < NumPixels * 3; i ++ )
		ColorBuffer [ NumPixels ] = 0x80;
	
	for ( i = 0; i < ( ( NumPixels + 31 ) / 32 ); i ++ )
		ZeroBuffer [ i ] = 0;
	
	Bus -> Write ( ZeroBuffer, ( NumPixels + 31 ) / 32 );
	
};

LDP8806 :: ~LDP8806 ()
{
};

uint32_t LDP8806 :: GetLength ()
{
	
	return NumPixels;
	
};

void LDP8806 :: SetPixels ( uint32_t Start, color_t * Colors, uint32_t Length )
{
	
	if ( Start + Length >= NumPixels )
		return;
	
	for ( uint32_t i = 0; i < Length; i ++ )
	{
		
		color_t Color = Colors [ i ];
		
		ColorBuffer [ ( Start + i ) * 3 ] = ( GreenFromColor ( Color ) >> 1 ) | 0x80;
		ColorBuffer [ ( Start + i ) * 3 + 1 ] = ( RedFromColor ( Color ) >> 1 ) | 0x80;
		ColorBuffer [ ( Start + i ) * 3 + 2 ] = ( BlueFromColor ( Color ) >> 1 ) | 0x80;
		
	}
	
	Dirty = true;
	
};

void LDP8806 :: SetPixel ( uint32_t Index, color_t Color )
{
	
	if ( Index >= NumPixels )
		return;
	
	ColorBuffer [ Index * 3 ] = ( GreenFromColor ( Color ) >> 1 ) | 0x80;
	ColorBuffer [ Index * 3 + 1 ] = ( RedFromColor ( Color ) >> 1 ) | 0x80;
	ColorBuffer [ Index * 3 + 2 ] = ( BlueFromColor ( Color ) >> 1 ) | 0x80;
	
	Dirty = true;
	
};

void LDP8806 :: Clear ( color_t ClearColor )
{
	
	uint8_t G = ( GreenFromColor ( ClearColor ) >> 1 ) | 0x80;
	uint8_t R = ( RedFromColor ( ClearColor ) >> 1 ) | 0x80;
	uint8_t B = ( BlueFromColor ( ClearColor ) >> 1 ) | 0x80;
	
	for ( uint32_t i = 0; i < NumPixels; i ++ )
	{
		
		ColorBuffer [ i * 3 ] = G;
		ColorBuffer [ i * 3 + 1 ] = R;
		ColorBuffer [ i * 3 + 2 ] = B;
		
	}
	
	Dirty = true;
	
};

void LDP8806 :: MarkBufferDirty ()
{
	
	Dirty = true;
	
};

void LDP8806 :: Update ()
{
	
	if ( ! Dirty )
		return;
	
	for ( uint32_t i = 0; i < NumPixels; i ++ )
	{
		
		Bus -> Write ( ColorBuffer, NumPixels * 3 );
		Bus -> Write ( ZeroBuffer, ( NumPixels + 31 ) / 32 );
		
	}
	
	Dirty = false;
	
};
