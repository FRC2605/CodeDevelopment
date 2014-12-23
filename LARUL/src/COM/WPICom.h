#ifndef LARUL_WPICOM_H
#define LARUL_WPICOM_H

#include "ISerialInterface.h"

class WPICom
{
public:
	
	WPICom ( SerialPort * Port );
	~WPICom ();
	
	bool IsOpen ();
	
	void Open ();
	void Close ();
	
	void Write ( uint8_t * Buffer, uint32_t Length );
	int32_t Read ( uint8_t * Buffer, uint32_t Max, int32_t Length = - 1 );
	void Flush ();
	
	uint32_t AvailableByteCount ();
	
private:
	
	SerialPort * Port;
	
};

#endif
