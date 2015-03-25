#ifndef HARDWARE_DRIVE_FILTERS_ROTATIONTVPFILTER_H_
#define HARDWARE_DRIVE_FILTERS_ROTATIONTVPFILTER_H_
#include "../../../DSP/DSPFilter.h"

#include "../../../Timing/IntervalTimer.h"

class RotationTVPFilter : public DSPFilter_1_1 {
public:
	RotationTVPFilter( double VRamp );
	virtual ~RotationTVPFilter();

	void Compute ( double R );
	double Read ();

	void Reset ();

private:

	double Exponent;
	double VRamp;
	double CR;
	IntervalTimer Delta;

};

#endif /* HARDWARE_DRIVE_FILTERS_ROTATIONTVPFILTER_H_ */
