#ifndef LARUL_MECANUMXYTVPFILTER_H
#define LARUL_MECANUMXYTVPFILTER_H

#include "../../../DSP/DSPFilter.h"

#include "../../../Timing/IntervalTimer.h"

class MecanumXYTVPFilter : public DSPFilter_2_2
{
public:

	MecanumXYTVPFilter ( double VRamp = 0.0 );
	~MecanumXYTVPFilter ();

	void SetVRamp ( double VRamp );

	void Compute ( double FeedA, double FeedB );

	double ReadA ();
	double ReadB ();

	void Reset ();

private:

	double CX, CY;
	double X, Y;

	double VRamp;

	IntervalTimer Delta;

};

#endif
