#ifndef LARUL_ISERIALINTERFACE_H
#define LARUL_ISERIALINTERFACE_H

#include <stdint.h>

class ISerialInterface
{
public:
	
	virtual ~ISerialInterface () = 0;
	
	virtual bool IsOpen () = 0;
	
	virtual void Open () = 0;
	virtual void Close () = 0;
	
	virtual void Write ( uint8_t * Buffer, uint32_t Length ) = 0;
	virtual int32_t Read ( uint8_t * Buffer, uint32_t Max, int32_t Length = - 1 ) = 0;
	virtual void Flush () = 0;
	
	virtual uint32_t AvailableByteCount () = 0;
	
};

#endif
