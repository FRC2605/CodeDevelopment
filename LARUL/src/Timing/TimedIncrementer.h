#ifndef LARUL_TIMEDINCREMENTER_H
#define LARUL_TIMEDINCREMENTER_H

#include "IntervalTimer.h"

#include "../Sensing/IScalarInput.h"

class TimedIncrementer : public IScalarInput
{
public:
	
	TimedIncrementer ( double Speed = 0.0, double Offset = 0.0 );
	~TimedIncrementer ();
	
	void Start ();
	void Stop ();
	
	bool IsRunning ();
	
	void SetSpeed ( double Speed = 0.0 );
	double GetSpeed ();
	
	double Get ();
	void Set ( double Value = 0.0 );
	void ApplyOffset ( double Offset = 0.0 );
	
	double GetScalar ();
	
	ScalarLimit GetScalarLimitType ();
	double GetLimitParam ( ScalarLimitParam Param );
	
private:
	
	bool Running;
	
	double Value;
	double Speed;
	
	double LastKey;
	
	IntervalTimer DeltaTimer;
	
};

#endif
