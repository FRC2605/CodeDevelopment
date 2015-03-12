#ifndef LARUL_TALONQUADDRIVEBASE_H
#define LARUL_TALONQUADDRIVEBASE_H

#include "IQuadRectangularDriveBase.h"

class TalonQuadDriveBase : public IQuadRectangularDriveBase
{
public:
	
	TalonQuadDriveBase ( uint8_t PWMChannelFL, uint8_t PDPChannelFL, uint8_t PWMChannelFR, uint8_t PDPChannelFR, uint8_t PWMChannelRL, uint8_t PDPChannelRL, uint8_t PWMChannelRR, uint8_t PDPChannelRR, double MotorDrawAverage, double MotorDrawMax );
	~TalonQuadDriveBase ();
	
	void SetInversion ( bool FL, bool FR, bool RL, bool RR );
	
	void Update ();
	
	// HWSystem interface
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	// IPowerScalable interface
	PowerProfile * GetProfile ();
	PowerUsageSpec * GetSpec ();
		
	void SetPowerScale ( double Scale );
	
	// IQuadRectangularDriveBase interace
	void SetMotor ( MotorPosition Motor, double Value );

private:
	
	typedef struct
	{
		
		bool MotorInverted;
		
		double SetPoint;
		
	} MotorInfo;
	
	Talon WheelFL;
	Talon WheelFR;
	Talon WheelRL;
	Talon WheelRR;
	
	MotorInfo MInfoFL;
	MotorInfo MInfoFR;
	MotorInfo MInfoRL;
	MotorInfo MInfoRR;
	
	bool Enabled;
	
	PowerProfile MotorProfile;
	PowerUsageSpec MotorSpec;
	
	double PowerScale;
	
};

#endif
