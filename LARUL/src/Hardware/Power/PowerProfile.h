#ifndef LARUL_POWERPROFILE_H
#define LARUL_POWERPROFILE_H

#include <string>

#include "../../Util/Vector.h"

#include "../../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

#include "Power.h"

class PowerProfile
{
public:
	
	PowerProfile ( const char * Name );
	PowerProfile ( const std :: string Name );
	~PowerProfile ();
	
	void AddChannel ( uint8_t PDPChannel );
	void RemoveChannel ( uint8_t PDPChannel );
	
	void AddSubProfile ( PowerProfile * Profile );
	void RemoveSubProfile ( PowerProfile * Profile );
	
	const std :: string GetName ();
	
	double GetCurrent ();
	double GetCurrentPortion ();
	
	uint8_t GetHighestDemandChannel ();
	
private:
	
	Vector <uint8_t> Channels;
	Vector <PowerProfile *> SubProfiles;
	std :: string Name;
	
};

#endif

#endif
