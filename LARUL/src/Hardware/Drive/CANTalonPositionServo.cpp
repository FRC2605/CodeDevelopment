#include <Hardware/Drive/CANTalonPositionServo.h>

CANTalonPositionServo :: CANTalonPositionServo ( uint8_t CAN_ID, CANTalon :: FeedbackDevice Feedback, uint8_t PDPChannel ):
	Motor ( CAN_ID ),
	Target ( 0.0 ),
	Enabled ( false )
{
	
	Motor.SetControlMode ( CANTalon :: kPercentVbus );
	Motor.SetPID ( 0.0, 0.0, 0.0, 0.0 );
	Motor.SetFeedbackDevice ( Feedback );
	Motor.Set ( 0 );
	Motor.EnableControl ();
	
};

CANTalonPositionServo :: ~CANTalonPositionServo ()
{
};

void CANTalonPositionServo :: SetProfileSlot ( int Slot )
{
	
	Motor.SelectProfileSlot ( Slot );
	
};

void CANTalonPositionServo :: SetPIDF ( double P, double I, double D, double F )
{
	
	Motor.SetPID ( P, I, D, F );
	
}
void CANTalonPositionServo :: SetSensorInverted ( bool Inverted )
{
	
	Motor.SetSensorDirection ( Inverted );
	
};

void CANTalonPositionServo :: SetPosition ( double Position )
{
	
	Motor.SetPosition ( Position );
	
};

double CANTalonPositionServo :: GetPosition ()
{
	
	return Motor.GetPosition ();
	
};

void CANTalonPositionServo :: SetTarget ( double Position )
{
	
	Target = Position;
	
	if ( Enabled )
		Motor.Set ( Position );
	
};

double CANTalonPositionServo :: GetTarget ()
{
	
	return Target;
	
};

void CANTalonPositionServo :: SetLimitMode ( CANTalon :: LimitMode Mode )
{
	
	Motor.ConfigLimitMode ( Mode );
	
};

void CANTalonPositionServo :: SetLimits ( double High, double Low )
{
	
	Motor.ConfigForwardLimit ( High );
	Motor.ConfigReverseLimit ( High );
	
};

void CANTalonPositionServo :: SetLimitsNormallyOpen ( bool High, bool Low )
{
	
	Motor.ConfigFwdLimitSwitchNormallyOpen ( High );
	Motor.ConfigRevLimitSwitchNormallyOpen ( Low );
	
};

void CANTalonPositionServo :: Enable ()
{
	
	if ( Enabled )
		return;
	
	Enabled = true;
	
	Motor.SetControlMode ( CANTalon :: kPosition );
	
	Motor.Set ( Target );
	
	Motor.EnableControl ();
	
};

void CANTalonPositionServo :: Disable ()
{
	
	if ( ! Enabled )
		return;
	
	Motor.SetControlMode ( CANTalon :: kPercentVbus );
	Motor.Set ( 0.0 );
	
	Enabled = false;
	
};

bool CANTalonPositionServo :: GetEnabled ()
{
	
	return Enabled;
	
};
