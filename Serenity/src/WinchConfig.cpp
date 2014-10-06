#include "WinchConfig.h"

const char * HIGH_LIMIT_NAME = "High Limit";
const char * LOW_LIMIT_NAME = "Low Limit";

WinchConfig :: WinchConfig ( Winch * Device ):
	ConfigSection ( "Winch" ),
	Device ( Device )
{	
};

WinchConfig :: ~WinchConfig ()
{
};

void WinchConfig :: WriteConfig ()
{
	
	json_t * HighLimit = json_real ( Device -> HighLimit );
	json_t * LowLimit = json_real ( Device -> LowLimit );
	
	json_object_set_new ( SectionNode, HIGH_LIMIT_NAME, HighLimit );
	json_object_set_new ( SectionNode, LOW_LIMIT_NAME, LowLimit );
	
};

void WinchConfig :: LoadConfig ()
{
	
	json_t * HighLimit = json_object_get ( SectionNode, HIGH_LIMIT_NAME );
	json_t * LowLimit = json_object_get ( SectionNode, LOW_LIMIT_NAME );
	
	Device -> HighLimit = json_real_value ( HighLimit );
	Device -> LowLimit = json_real_value ( LowLimit );
	
};

