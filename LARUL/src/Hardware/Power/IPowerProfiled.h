#ifndef LARUL_IPOWERPROFILED_H
#define LARUL_IPOWERPROFILED_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB

#include "PowerProfile.h"

class IPowerProfiled
{
public:
	
	virtual ~IPowerProfiled () {};
	
	virtual PowerProfile * GetProfile () = 0;	
		
};

#endif

#endif
