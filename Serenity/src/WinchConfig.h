#ifndef WINCHCONFIG_H
#define WINCHCONFIG_H

#include "ConfigSection.h"
#include "Winch.h"

class WinchConfig : public ConfigSection
{
public:
	
	WinchConfig ( Winch * Device );
	~WinchConfig ();
	
	void WriteConfig ();
	void LoadConfig ();
	
private:
	
	Winch * Device;
	
};

#endif
