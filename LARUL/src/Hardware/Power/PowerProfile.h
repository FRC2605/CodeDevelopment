#ifndef LARUL_POWERPROFILE_H
#define LARUL_POWERPROFILE_H

#include <WPILib.h>
#include <string>

#include "Power.h"

#include "../../Util/Vector.h"

class PowerProfile
{
public:
	
	PowerProfile ( const char * Name );
	PowerProfile ( const std :: string Name );
	~PowerProfile ();
	
	void AddChannel ( uint8_t PDPChannel );
	void RemoveChannel ( uint8_t PDPChannel );
	
	const std :: string GetName ();
	
	double GetCurrent ();
	double GetCurrentPortion ();
	
	uint8_t GetHighestDemandChannel ();
	
private:
	
	Vector <uint8_t> Channels;
	std :: string Name;
	
};

#endif
