#include "CANTalonQuadDriveBase.h"

CANTalonQuadDriveBase :: CANTalonQuadDriveBase ( uint8_t CAN_ID_FL, uint8_t PDPChannelFL, uint8_t CAN_ID_FR, uint8_t PDPChannelFR, uint8_t CAN_ID_RL, uint8_t PDPChannelRL, uint8_t CAN_ID_RR, uint8_t PDPChannelRR, CANTalonConfiguration Config, double MotorDrawAverage, double MotorDrawMax ):
	WheelFL ( CAN_ID_FL ),
	WheelFR ( CAN_ID_FR ),
	WheelRL ( CAN_ID_RL ),
	WheelRR ( CAN_ID_RR ),
	UnInvertedConfig ( Config ),
	InvertedConfig ( Config ),
	Enabled ( false ),
	MotorProfile ( "CANTalonDriveBase" ),
	MotorSpec ( MotorDrawMax * 4.0, 0.0, MotorDrawAverage, 20 ),
	PowerScale ( 1.0 )
{
	
	MotorProfile.AddChannel ( PDPChannelFL );
	MotorProfile.AddChannel ( PDPChannelFR );
	MotorProfile.AddChannel ( PDPChannelRL );
	MotorProfile.AddChannel ( PDPChannelRR );
	
	MInfoFL.MotorInverted = false;
	MInfoFL.SensorInverted = false;
	MInfoFL.SetPoint = 0.0;
	MInfoFR.MotorInverted = false;
	MInfoFR.SensorInverted = false;
	MInfoFR.SetPoint = 0.0;
	MInfoRL.MotorInverted = false;
	MInfoRL.SensorInverted = false;
	MInfoRL.SetPoint = 0.0;
	MInfoRR.MotorInverted = false;
	MInfoRR.SensorInverted = false;
	MInfoRR.SetPoint = 0.0;
	
	UnInvertedConfig.SetInversion ( false );
	InvertedConfig.SetInversion ( true );
	
	UnInvertedConfig.Configure ( & WheelFL );
	UnInvertedConfig.Configure ( & WheelFR );
	UnInvertedConfig.Configure ( & WheelRL );
	UnInvertedConfig.Configure ( & WheelRR );
	
};

CANTalonQuadDriveBase :: ~CANTalonQuadDriveBase ()
{
};

void CANTalonQuadDriveBase :: SetInversion ( bool FL, bool FR, bool RL, bool RR )
{
	
	MInfoFL.MotorInverted = FL;
	MInfoFR.MotorInverted = FR;
	MInfoRL.MotorInverted = RL;
	MInfoRR.MotorInverted = RR;
	
};

void CANTalonQuadDriveBase :: SetSensorInversion ( bool FL, bool FR, bool RL, bool RR )
{
	
	MInfoFL.SensorInverted = FL;
	MInfoFR.SensorInverted = FR;
	MInfoRL.SensorInverted = RL;
	MInfoRR.SensorInverted = RR;
	
	MInfoFL.SensorInverted ? InvertedConfig.Configure ( & WheelFL ) : UnInvertedConfig.Configure ( & WheelFL );
	MInfoFR.SensorInverted ? InvertedConfig.Configure ( & WheelFR ) : UnInvertedConfig.Configure ( & WheelFR );
	MInfoRL.SensorInverted ? InvertedConfig.Configure ( & WheelRL ) : UnInvertedConfig.Configure ( & WheelRL );
	MInfoRR.SensorInverted ? InvertedConfig.Configure ( & WheelRR ) : UnInvertedConfig.Configure ( & WheelRR );
	
};

void CANTalonQuadDriveBase :: Enable ()
{
	
	Enabled = true;
	
};

void CANTalonQuadDriveBase :: Disable ()
{
	
	Enabled = false;
	
	MInfoFL.SetPoint = 0.0;
	WheelFL.Set ( 0 );
	MInfoFR.SetPoint = 0.0;
	WheelFR.Set ( 0 );
	MInfoRL.SetPoint = 0.0;
	WheelRL.Set ( 0 );
	MInfoRR.SetPoint = 0.0;
	WheelRR.Set ( 0 );
	
};

bool CANTalonQuadDriveBase :: GetEnabled ()
{
	
	return Enabled;
	
};

PowerProfile * CANTalonQuadDriveBase :: GetProfile ()
{
	
	return & MotorProfile;
	
};

PowerUsageSpec * CANTalonQuadDriveBase :: GetSpec ()
{
	
	return & MotorSpec;
	
};

void CANTalonQuadDriveBase :: SetPowerScale ( double Scale )
{
	
	PowerScale = Scale;
	
	if ( Enabled )
	{
		
		WheelFL.Set ( MInfoFL.SetPoint * MInfoFL.MotorInverted ? - PowerScale : PowerScale );
		WheelFR.Set ( MInfoFR.SetPoint * MInfoFR.MotorInverted ? - PowerScale : PowerScale );
		WheelRL.Set ( MInfoRL.SetPoint * MInfoRL.MotorInverted ? - PowerScale : PowerScale );
		WheelRR.Set ( MInfoRR.SetPoint * MInfoRR.MotorInverted ? - PowerScale : PowerScale );
		
	}
	
};

void CANTalonQuadDriveBase :: SetMotor ( MotorPosition Motor, double Value )
{
	
	if ( ! Enabled )
		return;
	
	switch ( Motor )
	{
	
	case kMotorPosition_FL:
		
		MInfoFL.SetPoint = Value;
		WheelFL.Set ( MInfoFL.SetPoint * MInfoFL.MotorInverted ? - PowerScale : PowerScale );
		
		break;
		
	case kMotorPosition_FR:
		
		MInfoFR.SetPoint = Value;
		WheelFR.Set ( MInfoFR.SetPoint * MInfoFR.MotorInverted ? - PowerScale : PowerScale );
		
		break;
		
	case kMotorPosition_RL:
		
		MInfoRL.SetPoint = Value;
		WheelRL.Set ( MInfoRL.SetPoint * MInfoRL.MotorInverted ? - PowerScale : PowerScale );
		
		break;
		
	case kMotorPosition_RR:
		
		MInfoRR.SetPoint = Value;
		WheelRR.Set ( MInfoRR.SetPoint * MInfoRR.MotorInverted ? - PowerScale : PowerScale );
		
		break;
	
	}
	
}

