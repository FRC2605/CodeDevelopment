#ifndef LARUL_MECANUMDRIVETRAIN_H
#define LARUL_MECANUMDRIVETRAIN_H

#include <Hardware/Drive/IDriveTrain.h>
#include "IQuadRectangularDriveBase.h"

#include "../../DSP/DSPFilter.h"
#include "../../Util/Vector.h"

class MecanumDriveTrain : public IDriveTrain
{
public:
	
	MecanumDriveTrain ( IQuadRectangularDriveBase * DriveBase = NULL );
	
	void SetDriveBase ( IQuadRectangularDriveBase * DriveBase = NULL );
	
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	void SetMotorScale ( double S );
	double GetMotorScale ();
	
	void SetPreScale ( double Translation, double Rotation );
	double GetPreScaleTranslation ();
	double GetPreScaleRotation ();
	
	void SetTranslation ( double X, double Y );
	void SetRotation ( double R );
	
	void SetSineInversion ( bool Inverted );
	
	void DebugValues ();
	
	void PushTransform ();
	
	void AddXYFilter ( DSPFilter_2_2 * XYFilter );
	void RemoveXYFilter ( DSPFilter_2_2 * XYFilter );
	
	void AddMagDirFilter ( DSPFilter_2_2 * MagDirFilter );
	void RemoveMagDirFilter ( DSPFilter_2_2 * MagDirFilter );
	
	void AddRotationFilter ( DSPFilter_1_1 * RotationFilter );
	void RemoveRotationFilter ( DSPFilter_1_1 * RotationFilter );
	
private:
	
	IQuadRectangularDriveBase * DriveBase;
	
	double TX, TY, TR, Scale, PrescaleR, PrescaleT;
	
	bool Enabled, SineInverted;
	
	Vector <DSPFilter_2_2 *> XYFilters;
	Vector <DSPFilter_2_2 *> MDFilters;
	Vector <DSPFilter_1_1 *> RFilters;
	
};

#endif
