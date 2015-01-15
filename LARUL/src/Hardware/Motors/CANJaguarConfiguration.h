#ifndef LARUL_CANJAGUARCONFIGURATION_H
#define LARUL_CANJAGUARCONFIGURATION_H

#include <WPILib.h>

class CANJaguarConfiguration
{
	



	
public:
	enum FeedbackType
	{
		kFeedbackType_None,
		kFeedbackType_QuadEncoder,
		kFeedbackType_Encoder,
		kFeedbackType_Potentiometer,
		
	};



	CANJaguarConfiguration ( CANSpeedController :: ControlMode CtlMode );
	~CANJaguarConfiguration ( );
	
	void DissableFeedback ( );
	void SetConfPID ( double & pConf, double & iConf, double & dConf );
	void SetEncoderFeedback ( double pConf, double iConf, double dConf, uint16_t codesPerRev);
	void SetPotFeedBack ( double pConf, double iConf, double dConf, uint16_t turns);
	void SetQuadEncoderFeedback ( double pConf, double iConf, double dConf, uint16_t codesPerRev);

	void SetLimits ( CANSpeedController :: LimitMode LimitType, double ConfigForwardLimit, double ConfigReverseLimit );
	void SetFaultTime ( double ConfigFaultTime );
	void SetMaxOutputVoltage ( double ConfigVoltage );
	void SetVoltageRampRate ( double Rate );

	void ConfigJag (  CANJaguar & Jag );

private:
	CANSpeedController :: NeutralMode NeutralMode;
	CANSpeedController :: LimitMode LimitMode;
	double ForwardLimitPosition;
	double ReverseLimitPosition;
	double MaxOutputVoltage;
	double FaultTime;
	double VoltageRampRate;
	
	CANSpeedController :: ControlMode ControlMode;
	FeedbackType Feedback;
	double P, I, D;
	uint16_t Counts;
};


#endif
