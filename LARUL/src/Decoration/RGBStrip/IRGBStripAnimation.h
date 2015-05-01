#ifndef LARUL_IRGBSTRIPANIMATION_H
#define LARUL_IRGBSTRIPANIMATION_H

#include <stdint.h>

#include "../Color.h"

/* IRGBStripAnimation: A generic interface for animations on an RGB Strip.
 *
 * Methods:
 *
 *	virtual void Draw ( color_t * Buffer, uint32_t Start, uint32_t Length, uint32_t Frame, double Time )
 *	----------------------------------------------------------------------------------------------------
 *	Requests that the animation draws <Length> pixels into the color buffer <Buffer>, given that the
 *	current frame is <Frame> and that the current animation time is <Time> seconds. Note that any class
 *	which implements this method should never write to a color value beyond <Start> + <Length> (non -
 *	inclusive ) because this may be an invalid region in memory, and cause the program to segfault or
 *	create undefined behavior.
 *
*/

class IRGBStripAnimation
{
public:
	
	virtual ~IRGBStripAnimation () {};
	
	virtual void Draw ( color_t * Buffer, uint32_t Start, uint32_t Length, uint32_t Frame, double Time ) = 0;
	
};

#endif
