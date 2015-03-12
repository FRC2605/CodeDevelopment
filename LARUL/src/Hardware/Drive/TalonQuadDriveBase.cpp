#include "TalonQuadDriveBase.h"

TalonQuadDriveBase :: TalonQuadDriveBase ( uint8_t PWMChannelFL, uint8_t PDPChannelFL, uint8_t PWMChannelFR, uint8_t PDPChannelFR, uint8_t PWMChannelRL, uint8_t PDPChannelRL, uint8_t PWMChannelRR, uint8_t PDPChannelRR, double MotorDrawAverage, double MotorDrawMax ):
	WheelFL ( PWMChannelFL ),
	WheelFR ( PWMChannelFR ),
	WheelRL ( PWMChannelRL ),
	WheelRR ( PWMChannelRR ),
	Enabled ( false ),
	MotorProfile ( "TalonQuadDriveBase" ),
	MotorSpec ( MotorDrawMax * 4.0, 0.0, MotorDrawAverage, 20 ),
	PowerScale ( 1.0 )
{
	
	MotorProfile.AddChannel ( PDPChannelFL );
	MotorProfile.AddChannel ( PDPChannelFR );
	MotorProfile.AddChannel ( PDPChannelRL );
	MotorProfile.AddChannel ( PDPChannelRR );
	
};

TalonQuadDriveBase :: ~TalonQuadDriveBase ()
{
};

void TalonQuadDriveBase :: SetInversion ( bool FL, bool FR, bool RL, bool RR )
{
	
	MInfoFL.MotorInverted = FL;
	MInfoFR.MotorInverted = FR;
	MInfoRL.MotorInverted = RL;
	MInfoRR.MotorInverted = RR;
	
	if ( Enabled )
	{
		
		WheelFL.Set ( MInfoFL.SetPoint * ( MInfoFL.MotorInverted ? - PowerScale : PowerScale ) );
		WheelFR.Set ( MInfoFR.SetPoint * ( MInfoFR.MotorInverted ? - PowerScale : PowerScale ) );
		WheelRL.Set ( MInfoRL.SetPoint * ( MInfoRL.MotorInverted ? - PowerScale : PowerScale ) );
		WheelRR.Set ( MInfoRR.SetPoint * ( MInfoRR.MotorInverted ? - PowerScale : PowerScale ) );
		
	}
	
};

void TalonQuadDriveBase :: Enable ()
{
	
	Enabled = true;
	
};

void TalonQuadDriveBase :: Disable ()
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

bool TalonQuadDriveBase :: GetEnabled ()
{
	
	return Enabled;
	
};

void TalonQuadDriveBase :: Update ()
{
};

PowerProfile * TalonQuadDriveBase :: GetProfile ()
{
	
	return & MotorProfile;
	
};

PowerUsageSpec * TalonQuadDriveBase :: GetSpec ()
{
	
	return & MotorSpec;
	
};

void TalonQuadDriveBase :: SetPowerScale ( double Scale )
{
	
	PowerScale = Scale;
		
	if ( Enabled )
	{
		
		WheelFL.Set ( MInfoFL.SetPoint * ( MInfoFL.MotorInverted ? - PowerScale : PowerScale ) );
		WheelFR.Set ( MInfoFR.SetPoint * ( MInfoFR.MotorInverted ? - PowerScale : PowerScale ) );
		WheelRL.Set ( MInfoRL.SetPoint * ( MInfoRL.MotorInverted ? - PowerScale : PowerScale ) );
		WheelRR.Set ( MInfoRR.SetPoint * ( MInfoRR.MotorInverted ? - PowerScale : PowerScale ) );
			
	}
	
};
	
// IQuadRectangularDriveBase interace
void TalonQuadDriveBase :: SetMotor ( MotorPosition Motor, double Value )
{
	
	if ( ! Enabled )
		return;
	
	switch ( Motor )
	{
	
	case kMotorPosition_FL:
		
		MInfoFL.SetPoint = Value;
		WheelFL.Set ( MInfoFL.SetPoint * ( MInfoFL.MotorInverted ? - PowerScale : PowerScale ) );
		
		break;
		
	case kMotorPosition_FR:
		
		MInfoFR.SetPoint = Value;
		WheelFR.Set ( MInfoFR.SetPoint * ( MInfoFR.MotorInverted ? - PowerScale : PowerScale ) );
			
		break;
		
		case kMotorPosition_RL:
		
		MInfoRL.SetPoint = Value;
		WheelRL.Set ( MInfoRL.SetPoint * ( MInfoRL.MotorInverted ? - PowerScale : PowerScale ) );
		
		break;
		
	case kMotorPosition_RR:
		
		MInfoRR.SetPoint = Value;
		WheelRR.Set ( MInfoRR.SetPoint * ( MInfoRR.MotorInverted ? - PowerScale : PowerScale ) );
		
		break;
	
	}
	
};
