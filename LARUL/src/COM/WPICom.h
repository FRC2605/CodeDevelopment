#ifndef LARUL_WPICOM_H
#define LARUL_WPICOM_H

#include "ISerialInterface.h"

#include <WPILib.h>

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
	
	virtual void SetTimeoutMS ( uint64_t TimeoutMS );
	virtual bool TimeoutAvailible ();
	
	uint32_t AvailableByteCount ();
	
private:
	
	SerialPort * Port;
	
	bool PortOpen;
	
};

#endif