#ifndef BUTTON_MONITOR_H
#define BUTTON_MONITOR_H

#include <stdint.h>
#include <WPILib.h>

class ButtonMonitor
{
public:

	ButtonMonitor ( GenericHID * Device, uint32_t Button );
	~ButtonMonitor ();
	
	bool Update ();
	
private:
	
	GenericHID * Device;
	uint32_t Button;
	
	bool PState;
	
};

#endif
