#include "TimedIncrementer.h"

#include <math.h>
#include <iostream>

TimedIncrementer :: TimedIncrementer ( double Speed, double Offset ):
	Running ( false ),
	Value ( Offset ),
	Speed ( Speed ),
	LastKey ( 0.0 ),
	DeltaTimer ()
{
};

TimedIncrementer :: ~TimedIncrementer ()
{
};

void TimedIncrementer :: Start ()
{
	
	if ( Running )
		return;
	
	LastKey = 0.0;
	DeltaTimer.Start ();
	
	Running = true;
	
};

void TimedIncrementer :: Stop ()
{
	
	if ( ! Running )
		return;
	
	double End = DeltaTimer.GetTimeS ();
	
	DeltaTimer.Stop ();
	DeltaTimer.Reset ();
	
	Value += ( End - LastKey ) * Speed;
	
	Running = false;
	
};

bool TimedIncrementer :: IsRunning ()
{
	
	return Running;
	
};

void TimedIncrementer :: SetSpeed ( double Speed )
{
	
	if ( Running )
	{
		
		double End = DeltaTimer.GetTimeS ();
		
		Value += ( End - LastKey ) * this -> Speed;
		LastKey = End;
		
	}
	
	this -> Speed = Speed;
	
};

double TimedIncrementer :: GetSpeed ()
{
	
	return Speed;
	
};

double TimedIncrementer :: Get ()
{
	
	if ( Running )
	{
		
		double End = DeltaTimer.GetTimeS ();
		
		return Value + ( End - LastKey ) * Speed;
		
	}
	
	return Value;
	
};

void TimedIncrementer :: Set ( double Value )
{
	
	LastKey = DeltaTimer.GetTimeS ();
	
	this -> Value = Value;
	
};

void TimedIncrementer :: ApplyOffset ( double Offset )
{
	
	Value += Offset;
	
};

double TimedIncrementer :: GetScalar ()
{
	
	return Get ();
	
};

IScalarInput :: ScalarLimit TimedIncrementer :: GetScalarLimitType ()
{
	
	return kScalarLimit_None;
	
};

double TimedIncrementer :: GetLimitParam ( ScalarLimitParam Param )
{
	
	return NAN;
	
};
