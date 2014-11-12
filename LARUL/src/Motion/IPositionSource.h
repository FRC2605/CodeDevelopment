#ifndef LARUL_IPOSITIONSOURCE_H
#define LARUL_IPOSITIONSOURCE_H

#include "../CPP/Virtual.h"

#include "IMotoinSource.h"

class IPositionSource : public IMotionSource
{
public:
	
	VIRTUAL_CLASS ( IPositionSource );
	
	virtual double GetPosition () = 0;
	
	virtual double GetPositionScale () = 0;
	virtual void SetPositionScale ( double Scale ) = 0;
	
};

#endif
