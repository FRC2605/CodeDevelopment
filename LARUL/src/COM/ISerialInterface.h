#ifndef LARUL_ISERIALINTERFACE_H
#define LARUL_ISERIALINTERFACE_H

#include <stdint.h>

class ISerialInterface
{
public:
	
	virtual ~ISerialInterface () {};
	
	virtual bool IsOpen () = 0;
	
	virtual void Open () = 0;
	virtual void Close () = 0;
	
	virtual int32_t Write ( uint8_t * Buffer, uint32_t Length, bool Timeout = false ) = 0;
	virtual int32_t Read ( uint8_t * Buffer, uint32_t Max, int32_t Length = - 1, bool Timeout = false ) = 0;
	virtual void Flush () = 0;
	
	virtual void SetTimeoutMS ( uint64_t TimeoutMS ) = 0;
	virtual bool TimeoutAvailible () = 0;
	
	virtual uint32_t AvailableByteCount () = 0;
	
};

#endif
