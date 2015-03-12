#include "RGBPatternScrollAnimation.h"

#include <math.h>

#include "../../Color.h"

RGBPatternScrollAnimation :: RGBPatternScrollAnimation ( color_t * Pattern, uint32_t Length, bool Smooth ):
	Pattern ( Pattern ),
	Length ( Length ),
	Smooth ( Smooth )
{
};

RGBPatternScrollAnimation :: ~RGBPatternScrollAnimation ()
{	
};

void RGBPatternScrollAnimation :: SetPattern ( color_t * Pattern, uint32_t Length )
{
	
	this -> Pattern = Pattern;
	this -> Length = Length;
	
};

void RGBPatternScrollAnimation :: SetSmooth ( bool Smooth )
{
	
	this -> Smooth = Smooth;
	
};

void RGBPatternScrollAnimation :: Draw ( color_t * Buffer, uint32_t Start, uint32_t Length, uint32_t Frame, double Time )
{
	
	if ( Pattern == NULL || this -> Length == 0 )
		return;
	
	for ( uint32_t i = 0; i < Length; i ++ )
	{
		
		uint32_t LowerIDX = floor ( Time * 10.0 );
		uint32_t UpperIDX = ceil ( Time * 10.0 );
		
		double Mix = Time - static_cast <double> ( LowerIDX );
		
		LowerIDX %= this -> Length;
		UpperIDX %= this -> Length;
		
		Buffer [ i ] = LerpColor ( Pattern [ LowerIDX ], Pattern [ UpperIDX ], Mix );
		
	}
	
};
