#ifndef LARUL_RGBPATTERNSCROLLANIMATION_H
#define LARUL_RGBPATTERNSCROLLANIMATION_H

#include "../../Color.h"

#include "../IRGBStripAnimation.h"

#include <stddef.h>

/* RGBPatternScrollAnimation: An RGBStrip animation which scrolls a pattern.
 *
 * This class implements IRGBStripAnimation, so see IRGBStripAnimation for a functional description of all
 * methods not outlined below.
 *
 * Methods:
 *
 *	RGBPatternScrollAnimation ( color_t * Pattern, uint32_t Length, bool Smooth (OPTIONAL, Defaults to false) )
 *	-----------------------------------------------------------------------------------------------------------
 *	Constructs an instance of this animation, using the color array <Patter>, and it's lenth <Length>, to
 *	animate a scrolling animation of the pattern. If <Smooth> is true, this scrolling will be smooth and
 *	interpolated between animation points. Note that <Pattern> MUST point to a valid array of length <Length>
 *	or else undefined behavior may occur (such as a segfault).
 *
 *	void SetPattern ( color_t * Pattern, uint32_t Length )
 *	-----------------------------------------------------------------------------------------------------------
 *	Changes the pattern using the color array <Pattern> of length <Length>.Note that <Pattern> MUST point to a 
 *	valid array of length <Length> or else undefined behavior may occur (such as a segfault).
 *
 *	void SetSmooth ( bool Smooth )
 *	-----------------------------------------------------------------------------------------------------------
 *	Enables or disables smoothing dependant on <Smooth>
 *
*/

class RGBPatternScrollAnimation : public IRGBStripAnimation
{
public:
	
	RGBPatternScrollAnimation ( color_t * Pattern, uint32_t Length, bool Smooth = false );
	~RGBPatternScrollAnimation ();
	
	void SetPattern ( color_t * Pattern, uint32_t Length );
	void SetSmooth ( bool Smooth );
	
	void Draw ( color_t * Buffer, uint32_t Start, uint32_t Length, uint32_t Frame, double Time );
	
private:
	
	color_t * Pattern;
	uint32_t Length;
	
	bool Smooth;
	
};

#endif
