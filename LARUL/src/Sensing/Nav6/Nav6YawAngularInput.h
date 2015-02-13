#ifndef LARUL_NAV6YAWANGULARINPUT_H
#define LARUL_NAV6YAWANGULARINPUT_H

#include "../IAngularInput.h"
#include "Nav6.h"

class Nav6YawAngularInput : public IAngularInput
{
public:
	
	Nav6YawAngularInput ( Nav6 * Nav );
	~Nav6YawAngularInput ();
	
	double GetAngle ();
	
private:
	
	Nav6 * Nav;
	
};

#endif
