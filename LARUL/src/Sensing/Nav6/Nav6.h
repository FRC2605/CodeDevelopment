#ifndef LARUL_NAV6_H
#define LARUL_NAV6_H

#include <stdint.h>

#include "../../COM/ISerialInterface.h"

#include "../../Util/MethodClosure.h"

#include "../../Threading/Thread.h"
#include "../../Threading/Condition.h"
#include "../../Threading/Mutex.h"

class Nav6
{
public:
	
	Nav6 ( ISerialInterface * Serial, uint8_t UpdateRate );
	~Nav6 ();
	
	void Start ();
	void Stop ();
	
	double GetYaw ();
	double GetPitch ();
	double GetRoll ();
	
	double GetCompassHeading ();
	
private:
	
	ISerialInterface * Serial;
	uint8_t UpdateRate;
	
	double Yaw;
	double Pitch;
	double Roll;
	
	double AX;
	double AY;
	double AZ;
	
	double CompassHeading;
	
	void SendStreamCommand ( uint8_t UpdateRate );
	
	static uint8_t CalculateChecksum ( uint8_t * Buffer, uint32_t Length );
	
	static void SetStreamUint8 ( uint8_t * Buffer, uint32_t Index, uint8_t Value );
	static void SetStreamUint16 ( uint8_t * Buffer, uint32_t Index, uint16_t Value );
	static void SetStreamFloat ( uint8_t * Buffer, uint32_t Index, double Value );
	
	static uint8_t GetStreamUint8 ( uint8_t * Buffer, uint32_t Index );
	static int8_t GetStreamInt8 ( uint8_t * Buffer, uint32_t Index );
	static uint16_t GetStreamUint16 ( uint8_t * Buffer, uint32_t Index );
	static int16_t GetStreamInt16 ( uint8_t * Buffer, uint32_t Index );
	static double GetStreamNumber ( uint8_t * Buffer, uint32_t Index );
	
	static void SetStreamTermination ( uint8_t * Buffer, uint32_t MessageLength );
	
	void SerialUpdate ( Thread * UpdateThread );
	
	MethodClosure1 <Nav6, void, Thread *> SerialUpdateClosure;
	
	Thread SerialThread;
	
};

#endif
