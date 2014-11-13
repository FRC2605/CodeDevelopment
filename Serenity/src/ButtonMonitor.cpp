#include "ButtonMonitor.h"

ButtonMonitor :: ButtonMonitor ( GenericHID * Device, uint32_t Button ):
	Device ( Device ),
	Button ( Button ),
	PState ( false )
{	
};

ButtonMonitor :: ~ButtonMonitor ()
{	
};
	
bool ButtonMonitor :: Update ()
{
	
	if ( ! PState )
	{
		
		if ( Device -> GetRawButton ( Button ) )
		{
			
			PState = true;
			
			return true;
			
		}
		
	}
	
	PState = Device -> GetRawButton ( Button );
	
	return false;
	
};
