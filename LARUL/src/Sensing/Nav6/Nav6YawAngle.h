#ifndef LARUL_NAV6YAWANGLE_H
#define LARUL_NAV6YAWANGLE_H

#include "IMU.h"
#include "../IAngularInput.h"

class Nav6YawAngle : public IAngularInput
{
public:
	
	Nav6YawAngle ( IMU * Nav6 );
	~Nav6YawAngle ();
	
	double GetAngle ();
	
private:
	
	IMU * Nav6;
	
};

#endif
