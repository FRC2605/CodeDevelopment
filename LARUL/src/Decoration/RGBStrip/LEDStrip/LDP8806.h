#ifndef LARUL_LDP8806_H
#define LARUL_LDP8806_H

#include "../IRGBStrip.h"

#include "../../../COM/ISPIInterface.h"

/* LDP8806: A class to represent and control an RGB LED Strip using the LDP8806 controller.
 *
 * This class implements the IRGBStrip interface, so see IRGBStrip for a functional
 * description of all methods not outlined below.
 *
 * Unique methods:
 *
 *	LDP8806 ( ISPIInterface * Bus, uint32_t NumPixels )
 *	---------------------------------------------------
 *	Construct a new LDP8806 object. This constructor
 *	takes an SPI bus, on which the LDP8806's should be
 *	connected, and a count of the number of pixels in
 *	the strip. It is alright to pass a wrong number in
 *	NumPixels, however the strip will not display what
 *	you request it to properly.
 *
 *	void MarkBufferDirty ()
 *	---------------------------------------------------
 *	Marks the internal pixel buffer dirty, forcing a
 *	hardware update on the Update call, even if no
 *	calls have been made to SetPixel, SetPixels, or
 *	Clear.
 *
*/

class LDP8806 : public IRGBStrip
{
public:
	
	LDP8806 ( ISPIInterface * Bus, uint32_t NumPixels );
	~LDP8806 ();
	
	uint32_t GetLength ();
	
	void SetPixel ( uint32_t Index, color_t Color );
	void SetPixels ( uint32_t Start, color_t * Colors, uint32_t Length );
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
