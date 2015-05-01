#ifndef LARUL_IRGBSTRIP_H
#define LARUL_IRGBSTRIP_H

#include "../Color.h"

/* IRGBStrip: A generic interface for RGB strip indicators.
 * 
 * Methods:
 *
 *	virtual uint32_t GetLength ()
 *	----------------------------------------------------------------------------
 *	Gets the length of the strip in pixels.
 *
 *	virtual void SetPixel ( uint32_t Index, color_t Color )
 *	----------------------------------------------------------------------------
 *	Sets one pixel in the strip to a specific color. This method will not affect
 *	the state of the actual indicator until an Update () call is performed.
 *
 *	virtual void SetPixels ( uint32_t Start, color_t * Colors, uint32_t Length )
 *	----------------------------------------------------------------------------
 *	Sets multiple pixelsat once, starting with pixel number <Start>, and reading
 *	<Length> colors from the array <Colors> into each pixel sequentially
 *	afterward (inclusive). This method will not affect the state of the actual
 *	indicator until an Update () call is performed.
 *	
 *	virtual void Clear ( color_t ClearColor )
 *	----------------------------------------------------------------------------
 *	Sets every pixel in the strip to <ClearColor>. This method will not affect 
 *	the state of the actual indicator until an Update () call is performed.
 *	
 *	virtual void Update ()
 *	----------------------------------------------------------------------------
 *	Update the indicator with all previous changes. Call this method each time
 *	you want to change the colors on the indicator. Think of this like showing
 *	the next frame of a movie, or swapping buffers in OpenGL.
 *
*/

class IRGBStrip
{
public:
	
	virtual ~IRGBStrip () {};
	
	virtual uint32_t GetLength () = 0;
	
	virtual void SetPixel ( uint32_t Index, color_t Color ) = 0;
	virtual void SetPixels ( uint32_t Start, color_t * Colors, uint32_t Length ) = 0;
	
	virtual void Clear ( color_t ClearColor ) = 0;
	
	virtual void Update () = 0;
	
};


#endif
