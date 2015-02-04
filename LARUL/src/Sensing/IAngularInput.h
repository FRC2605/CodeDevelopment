#ifndef LARUL_ANGULARINPUT_H
#define LARUL_ANGULARINPUT_H

#include "IScalarInput.h"

class IAngularInput : public IScalarInput
{
public:
	
	~IAngularInput ();
	
	double GetScalar ();
	virtual double GetAngle () = 0;
		
	ScalarLimit GetScalarLimitType ();
	double GetLimitParam ( ScalarLimitParam Param );
	
};

#endif
