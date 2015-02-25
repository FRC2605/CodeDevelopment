#ifndef LARUL_MECANUMORIENTATIONOFFSET_H
#define LARUL_MECANUMORIENTATIONOFFSET_H

#include "../../../DSP/DSPFilter.h"

#include "../../../Sensing/IAngularInput.h"

class MecanumMagDirOrientationOffset : public DSPFilter_2_2
{
public:
	
	MecanumMagDirOrientationOffset ( IAngularInput * Angle );
	~MecanumMagDirOrientationOffset ();
	
	void CalibrateZero ( double AdditionalOffset = 0.0 );
	
	void Compute ( double FeedA, double FeedB );
	
	void SetEnabled ( bool Enabled );
	
	double ReadA ();
	double ReadB ();
	
	void Reset ();
	
private:
	
	IAngularInput * Angle;
	double Offset;
	
	double Magnitude;
	double Direction;
	
	bool Enabled;
	
};

#endif
