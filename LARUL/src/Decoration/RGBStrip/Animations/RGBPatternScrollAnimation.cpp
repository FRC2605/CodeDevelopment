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
		
		double Lower = fmod ( Time * static_cast <double> ( this -> Length ), static_cast <double> ( this -> Length ) );
		uint32_t LIDX = floor ( Lower );

		double Mix = Lower - static_cast <double> ( LIDX );
		
		if ( Smooth )
			Buffer [ i ] = LerpColor ( Pattern [ ( LIDX + i ) % this -> Length ], Pattern [ ( LIDX + i + 1 ) % this -> Length ], Mix );
		else
			Buffer [ i ] = Pattern [ ( LIDX + i ) % this -> Length ];
		
	}
	
};
