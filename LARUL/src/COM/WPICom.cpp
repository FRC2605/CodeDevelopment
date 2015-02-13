#include "WPICom.h"

#ifndef NO_WPILIB

WPICom :: WPICom ( SerialPort * Port ):
	Port ( Port ),
	PortOpen ( false )
{
	
	Port -> DisableTermination ();
	Port -> SetWriteBufferMode ( SerialPort :: kFlushOnAccess );
	
};

WPICom :: ~WPICom ()
{

	Close ();

};

bool WPICom :: IsOpen ()
{
	
	return PortOpen;
	
};

void WPICom :: Open ()
{
	
	Port -> Reset ();
	
	PortOpen = true;
	
};

void WPICom :: Reset ()
{
	
	Port -> Reset ();
	
};

void WPICom :: Close ()
{
	
	Flush ();

	PortOpen = false;
	
};

void WPICom :: SetTimeoutMS ( uint64_t TimeoutMS )
{
	
	Port -> SetTimeout ( static_cast <double> ( TimeoutMS ) / 1000 );
	
};

bool WPICom :: TimeoutAvailible ()
{
	
	return true;
	
};

int32_t WPICom :: Write ( uint8_t * Buffer, uint32_t Length, bool Timeout )
{
	
	if ( ! PortOpen )
		return 0;
	
	int32_t WrittenBytes = 0;
	
	while ( ( static_cast <uint32_t> ( WrittenBytes ) < Length ) && ! Timeout )
		WrittenBytes += Port -> Write ( reinterpret_cast <char *> ( & Buffer [ WrittenBytes ] ), Length - WrittenBytes );
	
	return WrittenBytes;
	
};

int32_t WPICom :: Read ( uint8_t * Buffer, uint32_t Max, int32_t Length, bool Timeout )
{
	
	if ( ! PortOpen )
		return 0;
	
	int32_t ReadBytes = 0;
	
	do
		ReadBytes += Port -> Read ( reinterpret_cast <char *> ( & Buffer [ ReadBytes ] ), Max - ReadBytes );
	while ( ( ReadBytes < Length ) && ! Timeout );
	
	return ReadBytes;

};

void WPICom :: Flush ()
{
	
	if ( PortOpen )
		Port -> Flush ();
	
};

uint32_t WPICom :: AvailableByteCount ()
{
	
	return Port -> GetBytesReceived ();
	
};

#endif
