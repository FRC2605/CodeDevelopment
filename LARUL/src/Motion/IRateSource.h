#ifndef LARUL_IRATESOURCE_H
#define LARUL_IRATESOURCE_H

#include "IMotoinSource.h"

class IRateSource : public IMotionSource
{
public:
	
	virtual double GetRate () = 0;
	
	virtual double GetRateScale () = 0;
	virtual void SetRateScale ( double RateScale ) = 0;
	
};

#endif
