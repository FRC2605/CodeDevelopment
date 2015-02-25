#ifndef LARUL_INDICATORBLINKER_H
#define LARUL_INDICATORBLINKER_H

#include "../Timing/IntervalTimer.h"

#include "IBooleanIndicator.h"

class BooleanIndicatorBlinker
{
public:
	
	typedef enum
	{
		
		kMode_Off,
		kMode_Blinking,
		kMode_On
		
	} Mode;
	
	BooleanIndicatorBlinker ( double Frequencey, IBooleanIndicator * Indicator = NULL, Mode InitialMode = kMode_Off );
	~BooleanIndicatorBlinker ();
	
	void Update ();
	
	void SetMode ( Mode IMode );
	void SetFrequencey ( double Frequencey );
	
	void SetIndicator ( IBooleanIndicator * Indicator, bool OldEndState = false );
	
private:
	
	IBooleanIndicator * Indicator;
	
	IntervalTimer Timer;
	
	double Period;
	Mode IMode;
	
};



#endif
