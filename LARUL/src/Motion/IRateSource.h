#ifndef LARUL_IRATESOURCE_H
#define LARUL_IRATESOURCE_H

#include "../CPP/Virtual.h"

#include "IMotoinSource.h"

class IRateSource : public IMotionSource
{
public:
	
	VIRTUAL_CLASS ( IRateSource );
	
	virtual double GetRate () = 0;
	
	virtual double GetRateScale () = 0;
	virtual void SetRateScale ( double Scale ) = 0;
	
};

#endif
