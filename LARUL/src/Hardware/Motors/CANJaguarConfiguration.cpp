#include "CANJaguarConfiguration.h"
#include <limits>

CANJaguarConfiguration :: CANJaguarConfiguration ( CANSpeedController :: ControlMode CtlMode):
NeutralMode ( CANSpeedController :: kNeutralMode_Jumper),
LimitMode  ( CANSpeedController :: kLimitMode_SwitchInputsOnly),
ForwardLimitPosition ( std::numeric_limits<int>::max() ),
ReverseLimitPosition (  std::numeric_limits<int>::max() ),
MaxOutputVoltage ( 15.0 ),
FaultTime ( 0.51f ),
VoltageRampRate ( 1000 ),
ControlMode ( CtlMode ),
Feedback ( kFeedbackType_None ),
Counts ( ),
P ( ),
I ( ),
D ( )

{

}

CANJaguarConfiguration :: ~CANJaguarConfiguration ( ) 
{

}

void CANJaguarConfiguration :: DissableFeedback ( ) 
{
	Feedback = kFeedbackType_None;
}

void CANJaguarConfiguration :: SetConfPID ( double & pConf, double & iConf, double & dConf )
{
	P = pConf;
	I = iConf;
	D = dConf;
}

void CANJaguarConfiguration :: SetEncoderFeedback ( double pConf, double iConf, double dConf, uint16_t codesPerRev)
{
	SetConfPID ( pConf, iConf, dConf);
	Feedback = kFeedbackType_Encoder;
	Counts = codesPerRev;
}

void CANJaguarConfiguration :: SetPotFeedBack ( double pConf, double iConf, double dConf, uint16_t turns)
{
	SetConfPID ( pConf, iConf, dConf);
	Feedback = kFeedbackType_Potentiometer;
	Counts = turns;
}

void CANJaguarConfiguration :: SetQuadEncoderFeedback ( double pConf, double iConf, double dConf, uint16_t codesPerRev)
{
	SetConfPID ( pConf, iConf, dConf);
	Feedback = kFeedbackType_QuadEncoder;
	Counts = codesPerRev;
}

void CANJaguarConfiguration :: SetLimits ( CANSpeedController :: LimitMode LimitType, double ConfigForwardLimit, double ConfigReverseLimit )
{
	LimitMode = LimitType;
	ForwardLimitPosition = ConfigForwardLimit;
	ReverseLimitPosition = ConfigReverseLimit;
}

void CANJaguarConfiguration :: SetFaultTime ( double ConfigFaultTime )
{
	FaultTime = ConfigFaultTime;
}

void CANJaguarConfiguration :: SetMaxOutputVoltage ( double ConfigVoltage )
{
	MaxOutputVoltage = ConfigVoltage;
}


void CANJaguarConfiguration :: ConfigJag (  CANJaguar & Jag )
{
	Jag.SetVoltageRampRate ( VoltageRampRate );
	Jag.ConfigFaultTime ( FaultTime );
	Jag.ConfigNeutralMode ( NeutralMode );
	Jag.ConfigLimitMode ( LimitMode );
	Jag.ConfigForwardLimit ( ForwardLimitPosition );
	Jag.ConfigReverseLimit ( ReverseLimitPosition );
	Jag.ConfigMaxOutputVoltage ( MaxOutputVoltage );
	
	switch ( Feedback )
	{

	case kFeedbackType_None:

		switch ( ControlMode )
		{

		case CANSpeedController :: kPercentVbus:
			Jag.SetPercentMode ( );
			break;

		case CANSpeedController :: kCurrent:
			Jag.SetCurrentMode ( P ,I ,D );
			break;

		case CANSpeedController :: kVoltage:
			Jag.SetVoltageMode ( );
			break;

		default:

			break;

		}
		break;

	case kFeedbackType_Encoder:

		switch ( ControlMode )
		{
			case CANSpeedController :: kPercentVbus:
				Jag.SetPercentMode ( CANJaguar :: Encoder, Counts );
				break;

			case CANSpeedController :: kCurrent:
				Jag.SetCurrentMode ( CANJaguar :: Encoder, Counts, P, I, D );
				break;

			case CANSpeedController :: kSpeed:
				Jag.SetSpeedMode ( CANJaguar :: Encoder, Counts, P, I, D );
				break;

			case CANSpeedController :: kVoltage:
				Jag.SetSpeedMode ( CANJaguar :: Encoder, Counts, P, I, D );
				break;
			default:
				break;
		}
		break;
	case kFeedbackType_QuadEncoder:

		switch ( ControlMode )
		{
			case CANSpeedController :: kPercentVbus:
				Jag.SetPercentMode ( CANJaguar :: QuadEncoder, Counts );
				break;
			case CANSpeedController :: kCurrent:
				Jag.SetCurrentMode ( CANJaguar :: QuadEncoder, Counts, P, I, D );
				break;
			case CANSpeedController :: kSpeed:
				Jag.SetSpeedMode ( CANJaguar :: QuadEncoder, Counts, P, I, D );
				break;
			case CANSpeedController :: kPosition:
				Jag.SetPositionMode ( CANJaguar :: QuadEncoder, Counts, P, I, D );
				break;
			case CANSpeedController :: kVoltage:
				Jag.SetVoltageMode ( CANJaguar :: QuadEncoder, Counts);
				break;
			default:
				break;
		}
		break;
	case kFeedbackType_Potentiometer:
		switch ( ControlMode )
		{
			case CANSpeedController :: kPercentVbus:
				Jag.SetPercentMode ( CANJaguar :: Potentiometer);
				break;
			case CANSpeedController :: kCurrent:
				Jag.SetCurrentMode ( CANJaguar :: Potentiometer, P, I, D );
				break;
			case CANSpeedController :: kPosition:
				Jag.SetPositionMode ( CANJaguar :: Potentiometer, P, I, D );
				break;
			case CANSpeedController :: kVoltage:
				Jag.SetVoltageMode ( CANJaguar :: Potentiometer);
				break;
			default:
				break;
		}
		break;
	}
}

