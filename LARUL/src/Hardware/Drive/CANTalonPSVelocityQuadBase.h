#ifndef LARUL_CANTALONPSVELOCITYQUADBASE_H
#define LARUL_CANTALONPSVELOCITYQUADBASE_H

#include "../../LARULTuning.h"

#ifndef NO_WPILIB

#include "CANTalonPositionServo.h"
#include "IQuadRectangularCANTalonDriveBase.h"

#include "../Power/PowerProfile.h"
#include "../Power/PowerUsageSpec.h"

#include "../../Timing/TimedIncrementer.h"

class CANTalonPSVelocityQuadBase : public IQuadRectangularCANTalonDriveBase
{
public:
	
	CANTalonPSVelocityQuadBase ( uint8_t CAN_ID_FL, uint8_t PDPChannelFL, uint8_t CAN_ID_FR, uint8_t PDPChannelFR, uint8_t CAN_ID_RL, uint8_t PDPChannelRL, uint8_t CAN_ID_RR, uint8_t PDPChannelRR, CANTalon :: FeedbackDevice Feedback, double MotorDrawAverage, double MotorDrawMax );
	CANTalonPSVelocityQuadBase ( IQuadRectangularCANTalonDriveBase * MotorSource, double MotorDrawAverage, double MotorDrawMax );
	~CANTalonPSVelocityQuadBase ();
	
	void SetInversion ( bool Fl, bool FR, bool RL, bool RR );
	void SetSensorInversion ( bool Fl, bool FR, bool RL, bool RR );
	
	void SetProfileSlot ( int Slot = 0 );
	void SetPIDF ( double P, double I, double D, double F );
	
	void Update ();
	
	// HWSystem interface
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	// IPowerScalable interface
	PowerProfile * GetProfile ();
	PowerUsageSpec * GetSpec ();
		
	void SetPowerScale ( double Scale );
	
	// IQuadRectangularDriveBase Interface
	void SetMotor ( MotorPosition Motor, double Value );
	
	CANTalon * GetCANTalon ( MotorPosition Position );

private:
	
	typedef struct MotorInfo_Struct
	{
		
		MotorInfo_Struct ();
		~MotorInfo_Struct ();
		
		bool SensorInverted;
		bool Inverted;
		
		double SetPoint;
		
		TimedIncrementer Increment;
		
	} MotorInfo;
	
	CANTalonPositionServo ServoFL;
	CANTalonPositionServo ServoFR;
	CANTalonPositionServo ServoRL;
	CANTalonPositionServo ServoRR;
	
	PowerProfile PProfile;
	PowerUsageSpec PSpec;
	
	bool Enabled;
	
	double PowerScale;
	
	double P;
	double I;
	double D;
	double F;
	
	int32_t Slot;
	
	MotorInfo MInfoFL;
	MotorInfo MInfoFR;
	MotorInfo MInfoRL;
	MotorInfo MInfoRR;
	
};


#endif

#endif
