#ifndef LARUL_IRGBLEDSTRIP_H
#define LARUL_IRGBLEDSTRIP_H

#include "../Color.h"

class IRGBLEDStrip
{
public:
	
	virtual ~IRGBLEDStrip () {};
	
	virtual uint32_t GetLength () = 0;
	
	virtual void SetLED ( uint32_t Index, color_t Color ) = 0;
	virtual void Clear ( color_t ClearColor ) = 0;
	
	virtual void Update () = 0;
	
};


#endif
