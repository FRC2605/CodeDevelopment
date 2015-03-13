#ifndef LARUL_MECANUMXYSLEWFILTER_H
#define LARUL_MECANUMXYSLEWFILTER_H

#include "../../../DSP/DSPFilter.h"

#include "../../../Timing/IntervalTimer.h"

class MecanumXYSlewFilter : public DSPFilter_2_2
{
public:
	
	MecanumXYSlewFilter ( double MaxSlew, double MaxDelta = 1.0 );
	~MecanumXYSlewFilter ();
	
	void Compute ( double FeedA, double FeedB );

	double ReadA ();
	double ReadB ();

	void Reset ();

private:
	
	double MaxSlew;
	double MaxDelta;
	
	double LX;
	double LY;
	
	IntervalTimer DeltaTimer;
	
};

#endif
