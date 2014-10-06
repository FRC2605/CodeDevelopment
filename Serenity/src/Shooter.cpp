#include "Shooter.h"

Shooter :: Shooter ( SpeedController * Flywheel, SpeedController * TriggerArm, DigitalInput * TriggerSwitch ):
	Flywheel ( Flywheel ),
	TriggerArm ( TriggerArm ),
	TriggerSwitch ( TriggerSwitch ),
	FlywheelScale ( 1 ),
	TriggerSpeed ( 0.6 ),
	FlywheelInverted ( false ),
	FlywheelSpeed ( 0 ),
	FlywheelEnabled ( false ),
	Triggering ( false ),
	Triggered ( false )
{
};

Shooter :: ~Shooter ()
{
};

void Shooter :: SetFlywheelScale ( double Scale )
{
	
	FlywheelScale = Scale;
	
};

void Shooter :: SetTriggerSpeed ( double Speed )
{
	
	TriggerSpeed = Speed;
	
};
	
void Shooter :: SetFlywheelInverted ( bool Inverted )
{
	
	FlywheelInverted = Inverted;
	
};

void Shooter :: SetFlywheelSpeed ( double Speed )
{
	
	FlywheelSpeed = Speed;
	
};

void Shooter :: SetEnabled ( bool Enabled )
{
	
	FlywheelEnabled = Enabled;
	
	if ( ! Enabled )
	{
		
		Flywheel -> Disable ();
		TriggerArm -> Disable ();
		
	}
	
};

bool Shooter :: GetEnabled ()
{
	
	return FlywheelEnabled;
	
};

void Shooter :: Trigger ( bool Override )
{
	
	if ( FlywheelEnabled )
		Triggering = true;
	
};

void Shooter :: Update ()
{
	
	if ( FlywheelEnabled )
		Flywheel -> Set ( FlywheelSpeed * FlywheelScale * FlywheelInverted ? - 1.0 : 1.0 );
	
	
	if ( Triggering || Triggered )
		TriggerArm -> Set ( TriggerSpeed );
	
	if ( TriggerSwitch -> Get () )
	{
		
		Triggering = false;
		Triggered = true;
		
	}
	
	if ( ! TriggerSwitch -> Get () && Triggered )
	{
		
		TriggerArm -> Set ( 0 );
		Triggered = false;
		
	}
	
};
