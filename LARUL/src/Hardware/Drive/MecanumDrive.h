#ifndef LARUL_MECANUMDRIVE_H
#define LARUL_MECANUMDRIVE_H

#include <math.h>

#include "WPILib.h"

#include "../../DSP/DSPFilter.h"
#include "../../Util/Vector.h"

#define PI_Div_4 0.78539816339
#define SQRT_2 1.41421356237

class MecanumDrive
{
public:

	MecanumDrive ( SpeedController * WwheelFL, SpeedController * WheelFR, SpeedController * WheelRL, SpeedController * WheelRR );
	~MecanumDrive ();
	
	void SetMotors ( SpeedController * WwheelFL, SpeedController * WheelFR, SpeedController * WheelRL, SpeedController * WheelRR );
	
	void SetInverted ( bool FL, bool FR, bool RL, bool RR );

	bool Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	void SetMotorScale ( double s );
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
	
	typedef struct MecMotorStruct
	{
		
		MecMotorStruct ( SpeedController * Motor );
		
		SpeedController * Motor;
		bool Inverted;
		
	} MecMotor;
	
	MecMotor MotorFL, MotorFR, MotorRL, MotorRR;
	
	double TX, TY, TR, Scale, PrescaleR, PrescaleT;

	bool Enabled, SineInverted;
	
	Vector <DSPFilter_2_2 *> XYFilters;
	Vector <DSPFilter_2_2 *> MDFilters;
	Vector <DSPFilter_1_1 *> RFilters;
	
};

#endif
