#include "CANTalonPSVelocityQuadBase.h"

#ifndef NO_WPILIB

CANTalonPSVelocityQuadBase :: MotorInfo_Struct :: MotorInfo_Struct ():
	SensorInverted ( false ),
	Inverted ( false ),
	SetPoint ( 0.0 ),
	Increment ()
{
};

CANTalonPSVelocityQuadBase :: MotorInfo_Struct :: ~MotorInfo_Struct ()
{
};

CANTalonPSVelocityQuadBase :: CANTalonPSVelocityQuadBase ( uint8_t CAN_ID_FL, uint8_t PDPChannelFL, uint8_t CAN_ID_FR, uint8_t PDPChannelFR, uint8_t CAN_ID_RL, uint8_t PDPChannelRL, uint8_t CAN_ID_RR, uint8_t PDPChannelRR, CANTalon :: FeedbackDevice Feedback, double MotorDrawAverage, double MotorDrawMax ):
	ServoFL ( CAN_ID_FL, Feedback, PDPChannelFL ),
	ServoFR ( CAN_ID_FR, Feedback, PDPChannelFR ),
	ServoRL ( CAN_ID_RL, Feedback, PDPChannelRL ),
	ServoRR ( CAN_ID_RR, Feedback, PDPChannelRR ),
	PProfile ( "CANTalon Quad Drive Position Servo Veelocity" ),
	PSpec ( 0.0, MotorDrawMax, MotorDrawAverage, 50 ),
	Enabled ( false ),
	PowerScale ( 1.0 ),
	P ( 0.0 ),
	I ( 0.0 ),
	D ( 0.0 ),
	F ( 0.0 ),
	Slot ( 0 )
{
	
	PProfile.AddSubProfile ( ServoFL.GetProfile () );
	PProfile.AddSubProfile ( ServoFR.GetProfile () );
	PProfile.AddSubProfile ( ServoRL.GetProfile () );
	PProfile.AddSubProfile ( ServoRR.GetProfile () );
	
};

CANTalonPSVelocityQuadBase :: ~CANTalonPSVelocityQuadBase ()
{
};

void CANTalonPSVelocityQuadBase :: SetInversion ( bool FL, bool FR, bool RL, bool RR )
{
	
	MInfoFL.Inverted = FL;
	MInfoFR.Inverted = FR;
	MInfoRL.Inverted = RL;
	MInfoRR.Inverted = RR;
	
	if ( Enabled )
	{
		
		MInfoFL.Increment.SetSpeed ( MInfoFL.SetPoint * MInfoFL.Inverted ? - PowerScale : PowerScale );
		MInfoFR.Increment.SetSpeed ( MInfoFR.SetPoint * MInfoFR.Inverted ? - PowerScale : PowerScale );
		MInfoRL.Increment.SetSpeed ( MInfoRL.SetPoint * MInfoRL.Inverted ? - PowerScale : PowerScale );
		MInfoRR.Increment.SetSpeed ( MInfoRR.SetPoint * MInfoRR.Inverted ? - PowerScale : PowerScale );
		
		Update ();
		
	}
	
};

void CANTalonPSVelocityQuadBase :: SetSensorInversion ( bool FL, bool FR, bool RL, bool RR )
{
	
	if ( Enabled )
		return;
	
	ServoFL.SetSensorInverted ( FL );
	ServoFR.SetSensorInverted ( FR );
	ServoRL.SetSensorInverted ( RL );
	ServoRR.SetSensorInverted ( RR );
	
};

void CANTalonPSVelocityQuadBase :: SetProfileSlot ( int Slot )
{
	
	this -> Slot = Slot;
	
	if ( Enabled )
	{
		
		ServoFL.SetProfileSlot ( Slot );
		ServoFR.SetProfileSlot ( Slot );
		ServoRL.SetProfileSlot ( Slot );
		ServoRR.SetProfileSlot ( Slot );
		
	}
	
};

void CANTalonPSVelocityQuadBase :: SetPIDF ( double P, double I, double D, double F )
{
	
	this -> P = P;
	this -> I = I;
	this -> D = D;
	this -> F = F;
	
	ServoFL.SetPIDF ( P, I, D, F );
	ServoFR.SetPIDF ( P, I, D, F );
	ServoRL.SetPIDF ( P, I, D, F );
	ServoRR.SetPIDF ( P, I, D, F );
	
};

// HWSystem interface
void CANTalonPSVelocityQuadBase :: Enable ()
{
	
	Enabled = true;
	
	ServoFL.SetPIDF ( P, I, D, F );
	ServoFR.SetPIDF ( P, I, D, F );
	ServoRL.SetPIDF ( P, I, D, F );
	ServoRR.SetPIDF ( P, I, D, F );
	
	ServoFL.SetPosition ( 0.0 );
	ServoFR.SetPosition ( 0.0 );
	ServoRL.SetPosition ( 0.0 );
	ServoRR.SetPosition ( 0.0 );
	
	ServoFL.Enable ();
	ServoFR.Enable ();
	ServoRL.Enable ();
	ServoRR.Enable ();
	
	ServoFL.SetTarget ( 0.0 );
	ServoFR.SetTarget ( 0.0 );
	ServoRL.SetTarget ( 0.0 );
	ServoRR.SetTarget ( 0.0 );
	
	MInfoFL.Increment.Set ( 0.0 );
	MInfoFR.Increment.Set ( 0.0 );
	MInfoRL.Increment.Set ( 0.0 );
	MInfoRR.Increment.Set ( 0.0 );
	
	MInfoFL.Increment.SetSpeed ( MInfoFL.SetPoint = 0.0 );
	MInfoFR.Increment.SetSpeed ( MInfoFR.SetPoint = 0.0 );
	MInfoRL.Increment.SetSpeed ( MInfoRL.SetPoint = 0.0 );
	MInfoRR.Increment.SetSpeed ( MInfoRR.SetPoint = 0.0 );
	
	MInfoFL.Increment.Start ();
	MInfoFR.Increment.Start ();
	MInfoRL.Increment.Start ();
	MInfoRR.Increment.Start ();
	
};

void CANTalonPSVelocityQuadBase :: Disable ()
{
	
	ServoFL.Disable ();
	ServoFR.Disable ();
	ServoRL.Disable ();
	ServoRR.Disable ();
	
	MInfoFL.Increment.Stop ();
	MInfoFR.Increment.Stop ();
	MInfoRL.Increment.Stop ();
	MInfoRR.Increment.Stop ();
	
	Enabled = false;
	
};

bool CANTalonPSVelocityQuadBase :: GetEnabled ()
{
	
	return Enabled;
	
};

#include <iostream>

void CANTalonPSVelocityQuadBase :: Update ()
{
	
	if ( ! Enabled )
		return;
	
	double MLP = MInfoFL.Increment.Get ();

	std :: cout << "MLP: " << MLP << ", Speed: " << MInfoFL.Increment.GetSpeed () << "\n";

	ServoFL.SetTarget ( MLP );
	ServoFR.SetTarget ( MInfoFR.Increment.Get () );
	ServoRL.SetTarget ( MInfoRL.Increment.Get () );
	ServoRR.SetTarget ( MInfoRR.Increment.Get () );
	
};

// IPowerScalable interface
PowerProfile * CANTalonPSVelocityQuadBase :: GetProfile ()
{
	
	return & PProfile;
	
};

PowerUsageSpec * CANTalonPSVelocityQuadBase :: GetSpec ()
{
	
	return & PSpec;
	
};
	
void CANTalonPSVelocityQuadBase :: SetPowerScale ( double Scale )
{
	
	PowerScale = Scale;
	
	if ( Enabled )
	{
		
		MInfoFL.Increment.SetSpeed ( MInfoFL.SetPoint * MInfoFL.Inverted ? - PowerScale : PowerScale );
		MInfoFR.Increment.SetSpeed ( MInfoFR.SetPoint * MInfoFR.Inverted ? - PowerScale : PowerScale );
		MInfoRL.Increment.SetSpeed ( MInfoRL.SetPoint * MInfoRL.Inverted ? - PowerScale : PowerScale );
		MInfoRR.Increment.SetSpeed ( MInfoRR.SetPoint * MInfoRR.Inverted ? - PowerScale : PowerScale );
		
		Update ();
		
	}
	
};

// IQuadRectangularDriveBase Interface
void CANTalonPSVelocityQuadBase :: SetMotor ( MotorPosition Motor, double Value )
{
	
	if ( ! Enabled )
		return;
	
	switch ( Motor )
	{
	
	case kMotorPosition_FL:
		
		std :: cout << "FL Set Speed: " << Value << "\n";

		MInfoFL.SetPoint = Value;
		MInfoFL.Increment.SetSpeed ( MInfoFL.SetPoint * ( MInfoFL.Inverted ? - PowerScale : PowerScale ) );
		
		break;
		
	case kMotorPosition_FR:
		
		MInfoFR.SetPoint = Value;
		MInfoFR.Increment.SetSpeed ( MInfoFR.SetPoint * ( MInfoFR.Inverted ? - PowerScale : PowerScale ) );
		
		break;
		
	case kMotorPosition_RL:
		
		MInfoRL.SetPoint = Value;
		MInfoRL.Increment.SetSpeed ( MInfoRL.SetPoint * ( MInfoRL.Inverted ? - PowerScale : PowerScale ) );
		
		break;
		
	case kMotorPosition_RR:
		
		MInfoRR.SetPoint = Value;
		MInfoRR.Increment.SetSpeed ( MInfoRR.SetPoint * ( MInfoRR.Inverted ? - PowerScale : PowerScale ) );
		
		break;
	
	}
	
};


#endif
