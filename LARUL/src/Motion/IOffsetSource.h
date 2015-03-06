#ifndef LARUL_IOFFSETSOURCE_H
#define LARUL_IOFFSETSOURCE_H

#include "IMotionSource.h"

class IOffsetSource : public IMotionSource
{
public:
	
	virtual double GetOffset () = 0;
	
	virtual double GetDistanceScale () = 0;
	virtual void SetDistanceScale ( double DistanceScale ) = 0;
	
};

#endif
