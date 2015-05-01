#ifndef LARUL_ISERIALINTERFACE_H
#define LARUL_ISERIALINTERFACE_H

#include <stdint.h>

/* ISerialInterface: A generic serial IO interface.
 *
 * It is assumed that the implementation will be properly set up for communication, and therefor settings such as bitcount, parity,
 * and transmission control are not part of this interface.
 * 
 * Methods:
 *	
 *	virtual bool IsOpen ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Returns whether or not the serial port is open.
 *
 *	virtual void Open ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Opens the serial port.
 * 
 *	virtual void Close ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Closes the serial port.
 *	
 *	virtual int32_t Write ( uint8_t * Buffer, uint32_t Length, bool Timeout (OPTIONAL, Defaults to false) )
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Writes to the serial port <Length> bytes from <Buffer>, with the option to time out after the configured timeout. Returns number
 *	of bytes written, or -1 if the write failed completely.
 *
 *	virtual int32_t Read ( uint8_t * Buffer, uint32_t Max, int32_t Length = (OPTIONAL), bool Timeout = (OPTIONAL, Defaults to false) )
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Reads from the serial port at most <Max> bytes into <Buffer>. If length is specified and != -1, only Length bytes should be read,
 *	although this behavior is implementation dependant. If Timeout is enabled, the operation will timeout after the configured time if
 *	it fails to complete within it.
 *
 *	virtual void Flush ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Flushes internal (and implementation dependant) write buffers
 *
 *	virtual void Reset ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Does an (implementation dependant) reset of the serial port, into aknown state.
 *
 *	virtual void SetTimeoutMS ( uint64_t TimeoutMS )
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Configures the timeout of the serial port in milliseconds if supported by the implementation.
 *
 *	virtual bool TimeoutAvailible ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Returns true if the implementation has the ability to timeout.
 *	
 *	virtual uint32_t AvailibleByteCount ()
 *	----------------------------------------------------------------------------------------------------------------------------------
 *	Returns the availible number of bytes in the read buffer. (Implementation dependant)
*/

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
	virtual void Reset () = 0;
	
	virtual void SetTimeoutMS ( uint64_t TimeoutMS ) = 0;
	virtual bool TimeoutAvailible () = 0;
	
	virtual uint32_t AvailableByteCount () = 0;
	
};

#endif
