#ifndef LARUL_CANJAGUARCONFIGURATION_H
#define LARUL_CANJAGUARCONFIGURATION_H

#include <WPILib.h>

class CANJaguarConfiguration
{
public:
	
	typedef enum
	{
		kFeedbackType_None,
		kFeedbackType_QuadEncoder,
		kFeedbackType_Encoder,
		kFeedbackType_Potentiometer,
		
	} FeedbackType;
	
	CANJaguarConfiguration ( CANSpeedController :: ControlMode Mode );
	~CANJaguarConfiguration ();
	
	void SetMode ( CANSpeedController :: ControlMode Mode );
	
	void SetPID ( double P, double I, double D );
	
	void SetEncoderFeedback ( uint16_t CodesPerRevolution );
	void SetQuadEncoderFeedback ( uint16_t CodesPerRevolution );
	void SetPotFeedBack ();
	void SetNoFeedback ();

	void SetLimits ( CANSpeedController :: LimitMode LimitType, double ForwardPositionLimit, double ReversePositionLimit );
	
	void SetFaultTime ( double FaultTime );
	void SetMaxOutputVoltage ( double Voltage );
	void SetVoltageRampRate ( double RampRate );

	void Configure (  CANJaguar & Jag );

private:
	
	CANSpeedController :: ControlMode Mode;
	
	FeedbackType Feedback;
	uint16_t EncoderCounts;
	
	double P;
	double I;
	double D;
		
	CANSpeedController :: NeutralMode NeutralMode;
	
	CANSpeedController :: LimitMode LimitMode;
	double ForwardPositionLimit;
	double ReversePositionLimit;
	
	double MaxOutputVoltage;
	double VoltageRampRate;
	
	double FaultTime;
	
};


#endif
