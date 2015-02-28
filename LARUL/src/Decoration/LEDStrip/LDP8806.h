#ifndef LARUL_LDP8806_H
#define LARUL_LDP8806_H

#include "IRGBLEDStrip.h"

#include "../../COM/ISPIInterface.h"

class LDP8806
{
public:
	
	LDP8806 ( ISPIInterface * Bus, uint32_t NumPixels );
	~LDP8806 ();
	
	uint32_t GetLength ();
	
	void SetLED ( uint32_t Index, color_t Color );
	void SetLEDs ( uint32_t Start, color_t * Colors, uint32_t Length );
	void Clear ( color_t ClearColor );
	
	void MarkBufferDirty ();
	
	void Update ();
	
private:
	
	ISPIInterface * Bus;
	
	uint32_t NumPixels;
	
	uint8_t * ColorBuffer;
	uint8_t * ZeroBuffer;
	
	bool Dirty;
	
};

#endif
