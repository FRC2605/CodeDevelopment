#ifndef LARUL_WPICOM_H
#define LARUL_WPICOM_H

#include "ISerialInterface.h"

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

/* WPICom: A wrapper for the WPILib SerialPort class which implemens ISerialInterface.
 * See ISerialInterface for a functional description of each method.
*/
 
class WPICom : public ISerialInterface
{
public:
	
	WPICom ( SerialPort * Port );
	~WPICom ();
	
	bool IsOpen ();
	
	void Open ();
	void Close ();
	
	int32_t Write ( uint8_t * Buffer, uint32_t Length, bool Timeout = false );
	int32_t Read ( uint8_t * Buffer, uint32_t Max, int32_t Length = - 1, bool Timeout = true );
	
	void Flush ();
	void Reset ();
	
	void SetTimeoutMS ( uint64_t TimeoutMS );
	bool TimeoutAvailible ();
	
	uint32_t AvailableByteCount ();
	
private:
	
	SerialPort * Port;
	
	bool PortOpen;
	
};

#endif

#endif
