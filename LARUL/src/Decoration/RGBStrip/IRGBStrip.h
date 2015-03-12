#ifndef LARUL_IRGBSTRIP_H
#define LARUL_IRGBSTRIP_H

#include "../Color.h"

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
