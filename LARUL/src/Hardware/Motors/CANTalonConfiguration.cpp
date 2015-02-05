#include "CANTalonConfiguration.h"

CANTalonConfiguration :: CANTalonConfiguration ( CANSpeedController ::ControlMode Mode, FeedbackType Feedback ):
	Mode ( Mode ),
	Feedback ( Feedback ),
	ControlSlot ( 0 ),
	P ( 0 ),
	I ( 0 ),
	D ( 0 ),
	F ( 0 ),
	IZone ( 0 ),
	SensorInverted ( false ),
	ClosedLoopRamp ( 0 ),
	MotorRamp ( 0 )
{
};

CANTalonConfiguration :: ~CANTalonConfiguration ()
{
};

void CANTalonConfiguration :: SetInversion ( bool Sensor )
{
	
	SensorInverted = Sensor;
	
};

void CANTalonConfiguration :: SetPIDF ( double P, double I, double D, double F )
{
	
	this -> P = P;
	this -> I = I;
	this -> D = D;
	this -> F = F;
	
};

void CANTalonConfiguration :: SetIZone ( double IZone )
{
	
	this -> IZone = IZone;
	
};

void CANTalonConfiguration :: SetRampRates ( double Motor, double ClosedLoop )
{
	
	this -> MotorRamp = Motor;
	this -> ClosedLoopRamp = ClosedLoop;
	
};

void CANTalonConfiguration :: SetControlSlot ( int Slot )
{
	
	if ( ( Slot > 1 ) || ( Slot < -1 ) )
		Slot = -1;
	
	this -> ControlSlot = Slot;
	
};

void CANTalonConfiguration :: Configure ( CANTalon * ToConfig )
{
	
	ToConfig -> SetControlMode ( Mode );
	
	switch ( Feedback )
	{
	
	case kFeedbackType_AnalogEncoder:
		
		ToConfig -> SetFeedbackDevice ( CANTalon :: AnalogEncoder );
		
		break;
		
	case kFeedbackType_Potentiometer:
		
		ToConfig -> SetFeedbackDevice ( CANTalon :: AnalogPot );
		
		break;
		
	case kFeedbackType_EncoderRising:
		
		ToConfig -> SetFeedbackDevice ( CANTalon :: EncRising );
		
		break;
		
	case kFeedbackType_EncoderFalling:
		
		ToConfig -> SetFeedbackDevice ( CANTalon :: EncFalling );
		
		break;
	
	case kFeedbackType_QuadratureEncoder:
		
		ToConfig -> SetFeedbackDevice ( CANTalon :: QuadEncoder );
		
		break;
		
	case kFeedbackType_None:
	default:
		
		break;
		
	}
	
	if ( ControlSlot != - 1 )
	{
		
		ToConfig -> SelectProfileSlot ( ControlSlot );
		
		ToConfig -> SetPID ( P, I, D, F );
		ToConfig -> SetIzone ( IZone );
		
	}
	
	ToConfig -> SetSensorDirection ( SensorInverted );
	
	ToConfig -> Set ( 0 );
	ToConfig -> EnableControl ();
	
};
