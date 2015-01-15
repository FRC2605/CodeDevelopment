#include "CANJaguarConfiguration.h"

CANJaguarConfiguration :: CANJaguarConfiguration ( CANSpeedController :: ControlMode Mode ):
	Mode ( Mode ),
	Feedback ( kFeedbackType_None ),
	EncoderCounts ( 1 ),
	P ( 0.0 ),
	I ( 0.0 ),
	D ( 0.0 ),
	NeutralMode ( CANSpeedController :: kNeutralMode_Jumper ),
	LimitMode  ( CANSpeedController :: kLimitMode_SwitchInputsOnly ),
	ForwardPositionLimit ( 0.0 ),
	ReversePositionLimit ( 0.0 ),
	MaxOutputVoltage ( 15.0 ),
	VoltageRampRate ( 1000.0 ),
	FaultTime ( 0.51 )
{
};

CANJaguarConfiguration :: ~CANJaguarConfiguration () 
{
};

void CANJaguarConfiguration :: SetMode ( CANSpeedController :: ControlMode Mode )
{
	
	this -> Mode = Mode;
	
};

void CANJaguarConfiguration :: SetNoFeedback () 
{
	
	Feedback = kFeedbackType_None;
	
};

void CANJaguarConfiguration :: SetPID ( double P, double I, double D )
{
	
	this -> P = P;
	this -> I = I;
	this -> D = D;
};

void CANJaguarConfiguration :: SetEncoderFeedback ( uint16_t CodesPerRevolution )
{
	
	Feedback = kFeedbackType_Encoder;
	
	EncoderCounts = CodesPerRevolution;
	
};

void CANJaguarConfiguration :: SetPotFeedBack ()
{
	
	Feedback = kFeedbackType_Potentiometer;
	
};

void CANJaguarConfiguration :: SetQuadEncoderFeedback ( uint16_t EncoderCounts )
{
	
	Feedback = kFeedbackType_QuadEncoder;
	
	this -> EncoderCounts = EncoderCounts;
	
};

void CANJaguarConfiguration :: SetLimits ( CANSpeedController :: LimitMode LimitMode, double ForwardPositionLimit, double ReversePositionLimit )
{
	
	this -> LimitMode = LimitMode;
	
	this -> ForwardPositionLimit = ForwardPositionLimit;
	this -> ReversePositionLimit = ReversePositionLimit;
	
}

void CANJaguarConfiguration :: SetFaultTime ( double FaultTime )
{
	
	this -> FaultTime = FaultTime;
	
};

void CANJaguarConfiguration :: SetMaxOutputVoltage ( double Voltage )
{
	
	MaxOutputVoltage = Voltage;
	
};


void CANJaguarConfiguration :: ConfigJag ( CANJaguar & Jag )
{
	
	Jag.DisableControl ();
	
	Jag.ConfigMaxOutputVoltage ( MaxOutputVoltage );
	Jag.SetVoltageRampRate ( VoltageRampRate );
	
	Jag.ConfigFaultTime ( FaultTime );
	
	Jag.ConfigNeutralMode ( NeutralMode );
	
	Jag.ConfigLimitMode ( LimitMode );
	Jag.ConfigForwardLimit ( ForwardPositionLimit );
	Jag.ConfigForwardLimit ( ReversePositionLimit );
	
	switch ( Feedback )
	{

	case kFeedbackType_None:

		switch ( Mode )
		{

		case CANSpeedController :: kPercentVbus:
			Jag.SetPercentMode ();
			break;

		case CANSpeedController :: kCurrent:
			
			Jag.SetCurrentMode ( P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;

		case CANSpeedController :: kVoltage:
			Jag.SetVoltageMode ();
			break;

		}
		
		break;
		
	case kFeedbackType_Encoder:
		
		switch ( Mode )
		{
			
		case CANSpeedController :: kPercentVbus:
			Jag.SetPercentMode ( CANJaguar :: Encoder, EncoderCounts );
			break;
	
		case CANSpeedController :: kCurrent:
			
			Jag.SetCurrentMode ( CANJaguar :: Encoder, EncoderCounts, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kSpeed:
			
			Jag.SetSpeedMode ( CANJaguar :: Encoder, EncoderCounts, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
			
		case CANSpeedController :: kVoltage:
			
			Jag.SetSpeedMode ( CANJaguar :: Encoder, EncoderCounts, P, I, D );
			break;
			
		}
		
		break;
		
	case kFeedbackType_QuadEncoder:
		
		switch ( Mode )
		{
			
		case CANSpeedController :: kPercentVbus:
			Jag.SetPercentMode ( CANJaguar :: QuadEncoder, EncoderCounts );
			break;
		
		case CANSpeedController :: kCurrent:
			
			Jag.SetCurrentMode ( CANJaguar :: QuadEncoder, EncoderCounts, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kSpeed:
			
			Jag.SetSpeedMode ( CANJaguar :: QuadEncoder, EncoderCounts, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kPosition:
			
			Jag.SetPositionMode ( CANJaguar :: QuadEncoder, EncoderCounts, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kVoltage:
			
			Jag.SetVoltageMode ( CANJaguar :: QuadEncoder, EncoderCounts );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		}
		
		break;
		
	case kFeedbackType_Potentiometer:
		
		switch ( Mode )
		{
		
		
		case CANSpeedController :: kPercentVbus:
			Jag.SetPercentMode ( CANJaguar :: Potentiometer );
			break;
		
		case CANSpeedController :: kCurrent:
			
			Jag.SetCurrentMode ( CANJaguar :: Potentiometer, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kPosition:
			
			Jag.SetPositionMode ( CANJaguar :: Potentiometer, P, I, D );
			
			Jag.Set ( 0 );
			Jag.EnableControl ();
			
			break;
		
		case CANSpeedController :: kVoltage:
			Jag.SetVoltageMode ( CANJaguar :: Potentiometer);
			break;
			
		}
		
		break;
		
	}
	
};

