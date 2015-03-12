#ifndef LARUL_IRGBSTRIPANIMATION_H
#define LARUL_IRGBSTRIPANIMATION_H

#include <stdint.h>

#include "../Color.h"

class IRGBStripAnimation
{
public:
	
	virtual ~IRGBStripAnimation () {};
	
	virtual void Draw ( color_t * Buffer, uint32_t Start, uint32_t Length, uint32_t Frame, double Time ) = 0;
	
};

#endif
