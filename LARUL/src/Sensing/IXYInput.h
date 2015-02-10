#ifndef LARUL_IXYSOURCE_H
#define LARUL_IXYSOURCE_H

#include "IXInput.h"

class IXYInput : public IXInput
{
public:
	
	virtual ~IXYInput () {};
	
	virtual double GetY () = 0;
	
};

#endif
