#ifndef LARUL_TALONPOSITIONSERVO_H
#define LARUL_TALONPOSITIONSERVO_H

#include <WPILib.h>

#include "../../Motion/IPositionDrive.h"

class CANTalonPositionServo : public IPositionDrive
{
public:
	
	CANTalonPositionServo ( uint8_t CAN_ID, CANTalon :: FeedbackDevice Feedback, uint8_t PDPChannel );
	~CANTalonPositionServo ();
	
	void SetProfileSlot ( int Slot = 0 );
	void SetPIDF ( double P, double I, double D, double F );
	void SetSensorInverted ( bool Inverted );
	
	void SetPosition ( double Position );
	double GetPosition ();
	
	void SetTarget ( double Position );
	double GetTarget ();
	
	void SetLimitMode ( CANTalon :: LimitMode Mode );
	void SetLimits ( double High, double Low );
	void SetLimitsNormallyOpen ( bool High, bool Low );
	
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
private:
	
	CANTalon Motor;
	
	double Target;
	
	bool Enabled;
	
};


#endif
