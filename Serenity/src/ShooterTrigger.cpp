#include "ShooterTrigger.h"

ShooterTrigger :: ShooterTrigger ( SpeedController * Motor, DigitalInput * Switch ):
	Motor ( Motor ),
	Switch ( Switch ),
	Enabled ( false ),
	Triggering ( false ),
	Triggered ( false ),
	MotorSpeed ( 1 )
{
};

ShooterTrigger :: ~ShooterTrigger ()
{
	
	
	
};

void ShooterTrigger :: SetMotorSpeed ( double Speed )
{
	
	MotorSpeed = Speed;
	
};

void ShooterTrigger :: Update ()
{
	
	if ( ! Enabled )
	{
		
		Motor -> Set ( 0 );
		
		return;
		
	}
	
	if ( Triggered )
	{
		
		Motor -> Set ( MotorSpeed );
		
		if ( Triggering && ( Switch -> Get () != 0 ) )
		{
			
			Triggering = false;
			Triggered = false;
			
			Motor -> Set ( 0 );
			
		}
		else if ( ! Triggering && ( Switch -> Get () == 0 ) )
			Triggering = true;
		
	}
	else
		Motor -> Set ( 0 );
	
};

void ShooterTrigger :: Trigger ()
{
	
	if ( Enabled )
		Triggered = true;
	
	Motor -> Set ( MotorSpeed );
	
};

void ShooterTrigger :: Enable ()
{
	
	Enabled = true;
	
	Triggering = false;
	Triggered = false;
	
};

void ShooterTrigger :: Disable ()
{
	
	Enabled = false;
	
	Motor -> Disable ();
	
};
