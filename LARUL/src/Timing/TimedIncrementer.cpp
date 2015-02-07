#include "TimedIncrementer.h"

TimedIncrementer ( double Speed, double Offset ):
	Running ( false ),
	Value ( Offset ),
	Speed ( Speed ),
	LastKey ( 0.0 ),
	DeltaTimer (),
{
};

~TimedIncrementer ()
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
	
};

bool TimedIncrementer :: Running ()
{
	
	return Running;
	
};

void TimedIncrementer :: SetSpeed ( double Speed = 0.0 )
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
		
		Value += ( End - LastKey ) * Speed;
		LastKey = End;
		
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
