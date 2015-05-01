#ifndef LARUL_ISPIINTERFACE_H
#define LARUL_ISPIINTERFACE_H

#include <stdint.h>

/* ISPIInterface: A generic SPI bus interface.
 *
 * Methods:
 *
 *	virtual void SetClockRate ( double RateHZ )
 *	----------------------------------------------------------
 *	Sets the bus clock rate in Hz
 *
 *	virtual void SetBitOrder ( BitOrder Order )
 *	----------------------------------------------------------
 *	Sets the bit order of the bus
 *
 *	virtual void SetSampleTrigger ( SampleTrigger Trigger )
 *	----------------------------------------------------------
 *	Sets the sampling trigger mode.
 *	
 *	virtual void SetClockActiveHigh ( bool High )
 *	----------------------------------------------------------
 *	Sets whether the clock line is active high or active
 *	low.
 *
 *	virtual void SetChipSelectActiveHigh ( bool High )
 * 	----------------------------------------------------------
 *	Sets whether the chip select line for this port's chip
 *	is active high or active low.
 *
 *	virtual int32_t Read ( uint8_t * Buffer, uint8_t Max )
 *	----------------------------------------------------------
 *	Reads availible bytes from the bus, up to <Max> bytes.
 *	The number of bytes read is returned or -1 if the read
 *	failed.
 *
 *	virtual int32_t Write ( uint8_t * Buffer, uint8_t Length )
 *	----------------------------------------------------------
 *	Writes <Length> bytes from <Buffer> to the bus. Returns
 *	the number of bytes written, or -1 on failure.
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
