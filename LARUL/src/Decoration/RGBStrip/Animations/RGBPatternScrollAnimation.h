#ifndef LARUL_RGBPATTERNSCROLLANIMATION_H
#define LARUL_RGBPATTERNSCROLLANIMATION_H

#include "../../Color.h"

#include "../IRGBStripAnimation.h"

#include <stddef.h>

class RGBPatternScrollAnimation : public IRGBStripAnimation
{
public:
	
	RGBPatternScrollAnimation ( color_t * Pattern = NULL, uint32_t Length = 0, bool Smooth = false );
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
