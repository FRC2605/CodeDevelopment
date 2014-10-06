#ifndef SHOOTER_H
#define SHOOTER_H

#include <WPILib.h>

class Shooter
{
public:
	
	Shooter ( SpeedController * Flywheel, SpeedController * TriggerArm, DigitalInput * TriggerSwitch );
	~Shooter ();
	
	void SetFlywheelScale ( double Scale );
	void SetTriggerSpeed ( double Speed );
	
	void SetFlywheelInverted ( bool Inverted );
	
	void SetFlywheelSpeed ( double Speed );
	
	void SetEnabled ( bool Enabled );
	bool GetEnabled ();
	
	void Trigger ( bool Override = false );
	
	void Update ();
	
private:
	
	SpeedController * Flywheel;
	SpeedController * TriggerArm;
	
	DigitalInput * TriggerSwitch;
	
	double FlywheelScale;
	double TriggerSpeed;
	
	bool FlywheelInverted;
	
	double FlywheelSpeed;
	bool FlywheelEnabled;
	
	bool Triggering;
	bool Triggered;
	
};

#endif
