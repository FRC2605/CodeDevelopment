#ifndef LARUL_LDP6803_H
#define LARUL_LDP6803_H

#include "IRGBLEDStrip.h"

#include "../../COM/ISPIInterface.h"

class LDP6803
{
public:
	
	LDP6803 ( ISPIInterface * Bus, uint32_t NumPixels );
	~LDP6803 ();
	
	uint32_t GetLength ();
	
	void SetLED ( uint32_t Index, color_t Color );
	void SetLEDs ( uint32_t Start, color_t * Colors, uint32_t Length );
	void Clear ( color_t ClearColor );
	
	void MarkBufferDirty ();
	
	void Update ();
	
private:
	
	ISPIInterface * Bus;
	
	uint32_t NumPixels;
	
	bool Dirty;
	
};

#endif
