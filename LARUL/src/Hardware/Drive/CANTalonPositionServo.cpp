#include "CANTalonPositionServo.h"

#ifndef NO_WPIPIB

CANTalonPositionServo :: CANTalonPositionServo ( uint8_t CAN_ID, CANTalon :: FeedbackDevice Feedback, uint8_t PDPChannel ):
	Target ( 0.0 ),
	Enabled ( false ),
	Feedback ( Feedback ),
	Profile ( "CANTalon Position Servo" )
{
	
	Motor = new CANTalon ( CAN_ID );

	Motor -> SetControlMode ( CANTalon :: kPercentVbus );
	Motor -> SetPID ( 0.0, 0.0, 0.0, 0.0 );
	Motor -> SetFeedbackDevice ( Feedback );
	Motor -> Set ( 0 );
	Motor -> EnableControl ();
	
	Profile.AddChannel ( PDPChannel );
	
};

CANTalonPositionServo :: CANTalonPositionServo ( CANTalon * Motor ):
	Motor ( Motor ),
	Target ( 0.0 ),
	Enabled ( false ),
	Feedback ( CANTalon :: QuadEncoder ),
	Profile ( "CANTalon Position Servo" )
{

	Motor -> SetControlMode ( CANTalon :: kPercentVbus );
	Motor -> SetPID ( 0.0, 0.0, 0.0, 0.0 );
	Motor -> SetFeedbackDevice ( Feedback );
	Motor -> Set ( 0 );
	Motor -> EnableControl ();

};

CANTalon * CANTalonPositionServo :: GetCANTalon ()
{

	return Motor;

};

CANTalonPositionServo :: ~CANTalonPositionServo ()
{
};

void CANTalonPositionServo :: SetProfileSlot ( int Slot )
{
	
	Motor -> SelectProfileSlot ( Slot );
	
};

void CANTalonPositionServo :: SetPIDF ( double P, double I, double D, double F )
{
	
	Motor -> SetPID ( P, I, D, F );
	
}
void CANTalonPositionServo :: SetSensorInverted ( bool Inverted )
{
	
	Motor -> SetSensorDirection ( Inverted );
	
};

void CANTalonPositionServo :: SetPosition ( double Position )
{
	
	Motor -> SetPosition ( Position );
	
};

double CANTalonPositionServo :: GetPosition ()
{
	
	return Motor -> GetPosition ();
	
};

void CANTalonPositionServo :: SetTarget ( double Position )
{
	
	Target = Position;
	
	if ( Enabled )
		Motor -> Set ( Position );
	
};

double CANTalonPositionServo :: GetTarget ()
{
	
	return Target;
	
};

void CANTalonPositionServo :: SetLimitMode ( CANTalon :: LimitMode Mode )
{
	
	Motor -> ConfigLimitMode ( Mode );
	
};

void CANTalonPositionServo :: SetLimits ( double High, double Low )
{
	
	Motor -> ConfigForwardLimit ( High );
	Motor -> ConfigReverseLimit ( High );
	
};

void CANTalonPositionServo :: SetLimitsNormallyOpen ( bool High, bool Low )
{
	
	Motor -> ConfigFwdLimitSwitchNormallyOpen ( High );
	Motor -> ConfigRevLimitSwitchNormallyOpen ( Low );
	
};

void CANTalonPositionServo :: Enable ()
{
	
	if ( Enabled )
		return;
	
	Enabled = true;
	
	Motor -> SetControlMode ( CANTalon :: kPosition );
	
	Motor -> Set ( Target );
	
	Motor -> EnableControl ();
	
};

void CANTalonPositionServo :: Disable ()
{
	
	if ( ! Enabled )
		return;
	
	Motor -> SetPID ( 0.0, 0.0, 0.0, 0.0 );
	Motor -> SetFeedbackDevice ( Feedback );
	Motor -> SetControlMode ( CANTalon :: kPercentVbus );
	Motor -> Set ( 0.0 );
	
	Enabled = false;
	
};

bool CANTalonPositionServo :: GetEnabled ()
{
	
	return Enabled;
	
};

PowerProfile * CANTalonPositionServo :: GetProfile ()
{
	
	return & Profile;
	
};

#endif
