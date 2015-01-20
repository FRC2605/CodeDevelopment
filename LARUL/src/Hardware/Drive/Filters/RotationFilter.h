#ifndef HARDWARE_DRIVE_FILTERS_ROTATIONFILTER_H_
#define HARDWARE_DRIVE_FILTERS_ROTATIONFILTER_H_

#include "../../../DSP/DSPFilter.h"

class RotationFilter : public DSPFilter_1_1
{

public:

	RotationFilter (double Exponent);
	~RotationFilter ();

	void Compute ( double Magnitude );
	double Read ();

	void Reset ();

private:

	double Exponent;
	double Magnitude;
};


#endif
