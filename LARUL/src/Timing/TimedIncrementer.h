#ifndef LARUL_TIMEDINCREMENTER_H
#define LARUL_TIMEDINCREMENTER_H

#include "IntervalTimer.h"

class TimedIncrementer
{
public:
	
	TimedIncrementer ( double Speed = 0.0, double Offset = 0.0 );
	~TimedIncrementer ();
	
	void Start ();
	void Stop ();
	
	bool Running ();
	
	void SetSpeed ( double Speed = 0.0 );
	double GetSpeed ();
	
	double Get ();
	void Set ( double Value = 0.0 );
	void ApplyOffset ( double Offset = 0.0 );
	
private:
	
	bool Running;
	
	double Value;
	double Speed;
	
	double LastKey;
	
	IntervalTimer DeltaTimer;
	
};

#endif
