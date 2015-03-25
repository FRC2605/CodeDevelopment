#include <math.h>
#include "RotationTVPFilter.h"

RotationTVPFilter::RotationTVPFilter(double VRamp) :
	VRamp(VRamp),
	CR(0.0)
{
}

RotationTVPFilter::~RotationTVPFilter() {
	// TODO Auto-generated destructor stub
}

void RotationTVPFilter::Compute(double R) {

	double Delt = Delta.GetTimeS();
	Delta.Restart();

	double RDiff = R - CR;

	if ((fabs(RDiff) < Delt * VRamp))
		CR = R;
	else
		CR += ((RDiff > 0) ? VRamp : -VRamp) * Delt;

}

double RotationTVPFilter::Read() {

	return CR;

}

void RotationTVPFilter::Reset() {

}
