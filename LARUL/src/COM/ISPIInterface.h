#ifndef LARUL_ISPIINTERFACE_H
#define LARUL_ISPIINTERFACE_H

#include <stdint.h>

/* ISPIInterface: A generic SPI bus interface.
*/

class ISPIInterface
{
public:
	
	typedef enum
	{
		
		kBitOrder_MSBFirst,
		kBitOrder_LSBFirst
		
	} BitOrder;
	
	typedef enum
	{
		
		kSampleTrigger_FallingEdge,
		kSampleTrigger_RisingEdge
		
	} SampleTrigger;
	
	virtual ~ISPIInterface () {};
	
	virtual void SetClockRate ( double RateHZ ) = 0;
	virtual void SetBitOrder ( BitOrder Order ) = 0;
	virtual void SetSampleTrigger ( SampleTrigger Trigger ) = 0;
	
	virtual void SetClockActiveHigh ( bool High ) = 0;
	virtual void SetChipSelectActiveHigh ( bool High ) = 0;
	
	virtual int32_t Read ( uint8_t * Buffer, uint8_t Max ) = 0;
	virtual int32_t Write ( uint8_t * Buffer, uint8_t Length ) = 0;
	
};

#endif
