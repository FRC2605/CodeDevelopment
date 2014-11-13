#ifndef FRC2605_SHOOTERTRIGGER_H
#define FRC2605_SHOOTERTRIGGER_H

#include <WPILib.h>

class ShooterTrigger
{
public:
	
	ShooterTrigger ( SpeedController * Motor, DigitalInput * Switch );
	~ShooterTrigger ();
	
	void SetMotorSpeed ( double Speed );
	
	void Update ();
	
	void Trigger ();
	
	void Enable ();
	void Disable ();
	
private:
	
	SpeedController * Motor;
	
	DigitalInput * Switch;
	
	bool Enabled;
	bool Triggering;
	bool Triggered;
	
	double MotorSpeed;
	
};

#endif
