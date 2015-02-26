#ifndef LARUL_WPISPI_H
#define LARUL_WPISPI_H

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "ISPIInterface.h"

class WPISPI : public ISPIInterface
{
public:
	
	WPISPI ( SPI * Port );
	~WPISPI ();
	
	void SetClockRate ( double RateHZ );
	void SetBitOrder ( BitOrder Order );
	void SetSampleTrigger ( SampleTrigger Trigger );
	
	void SetClockActiveHigh ( bool High );
	void SetChipSelectActiveHigh ( bool High );
	
	int32_t Read ( uint8_t * Buffer, uint8_t Max );
	int32_t Write ( uint8_t * Buffer, uint8_t Length );
	
private:
	
	SPI * Port;
	
};


#endif
#endif
