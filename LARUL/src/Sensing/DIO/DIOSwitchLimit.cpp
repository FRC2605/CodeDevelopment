#include "DIOSwitchLimit.h"

DIOSwitchLimit :: DIOSwitchLimit ( DigitalInput * LowLimit, DigitalInput * HighLimit ):
	LowLimit ( LowLimit ),
	HighLimit ( HighLimit ),
	InvertedL ( false ),
	InvertedH ( false )
{
	
	if ( LowLimit != NULL )
	{
		
		if ( HighLimit != NULL )
			Bounding = LimitBounding :: kLimitBounding_HighLow;
		else
			Bounding = LimitBounding :: kLimitBounding_Low;
		
	}
	else
		Bounding = LimitBounding :: kLimitBounding_High;
	
};

DIOSwitchLimit :: ~DIOSwitchLimit ()
{
};

void DIOSwitchLimit :: SetInversion ( bool Low, bool High )
{
	
	InvertedL = Low;
	InvertedH = High;
	
};

IMotionLimit :: LimitBounding DIOSwitchLimit :: GetBounding ()
{
	
	return Bounding;
	
};

bool DIOSwitchLimit :: GetHighLimit ()
{
	
	if ( LowLimit == NULL )
		return false;
	
	return LowLimit -> Get () ^ InvertedL;
	
};

bool DIOSwitchLimit :: GetLowLimit ()
{
	
	if ( HighLimit == NULL )
		return false;
	
	return HighLimit -> Get () ^ InvertedH;
	
};
