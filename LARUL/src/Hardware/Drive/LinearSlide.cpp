#include "LinearSlide.h"

#include <math.h>

LinearSlide :: LinearSlide ( IPositionDrive * Motor, IMotionLimit * Limit, double HomingSpeed, double Initial, double LowLimit, double HighLimit ):
	Motor ( Motor ),
	Limit ( Limit ),
	LowLimit ( LowLimit ),
	HighLimit ( HighLimit ),
	Targeter ( 0.0, Initial ),
	Enabled ( false ),
	State ( kMode_Velocity ),
	HomingSpeed ( HomingSpeed )
{
	
	Motor -> SetPosition ( Initial );
	
};

LinearSlide :: LinearSlide ( IPositionDrive * Motor, double Initial, double LowLimit, double HighLimit ):
	Motor ( Motor ),
	Limit ( NULL ),
	LowLimit ( LowLimit ),
	HighLimit ( HighLimit ),
	Targeter ( 0.0, Initial ),
	Enabled ( false ),
	State ( kMode_Velocity ),
	HomingSpeed ( 0.0 )
{
	
	Motor -> SetPosition ( Initial );
	
};

LinearSlide :: ~LinearSlide ()
{
};

void LinearSlide :: TargetPosition ( double Position )
{
	
	Targeter.SetSpeed ( 0.0 );
	Targeter.Set ( Position );
	
	Motor -> SetTarget ( Position );
	
	State = kMode_Position;
	
};

void LinearSlide :: RunVelocity ( double Velocity )
{
	
	Targeter.SetSpeed ( Velocity );
	
	State = kMode_Velocity;
	
};

void LinearSlide :: HomeLow ()
{
	
	if ( LinearSlide :: Limit != NULL )
	{
		
		switch ( Limit -> GetBounding () )
		{
		
		case IMotionLimit :: kLimitBounding_Low:
		case IMotionLimit :: kLimitBounding_HighLow:
			
			Targeter.SetSpeed ( - HomingSpeed );
			
			break;
			
		default:
			
			break;
		
		}
		
	}
	
	State = kMode_HomeLow;
	
};

void LinearSlide :: HomeHigh ()
{
	
	if ( LinearSlide :: Limit != NULL )
	{
		
		
		switch ( Limit -> GetBounding () )
		{
		
		case IMotionLimit :: kLimitBounding_High:
		case IMotionLimit :: kLimitBounding_HighLow:
			
			Targeter.SetSpeed ( HomingSpeed );
			
			break;
			
		default:
			
			break;
		
		}
		
	}
	
	State = kMode_HomeHigh;
	
};

void LinearSlide :: Home ()
{
	
	if ( LinearSlide :: Limit != NULL )
	{
		
		switch ( Limit -> GetBounding () )
		{
		
		case IMotionLimit :: kLimitBounding_HighLow:
			
			Targeter.SetSpeed ( - HomingSpeed );
			
			break;
			
		case IMotionLimit :: kLimitBounding_High:
			
			return HomeHigh ();
			
		case IMotionLimit :: kLimitBounding_Low:
					
			return HomeLow ();
			
		default:
			
			return;
			
		}
	
	}
	
	State = kMode_HomeLowHigh;
	
};

bool LinearSlide :: IsHoming ()
{
	
	switch ( State )
	{
	
	case kMode_Velocity:
	case kMode_Position:
	case kMode_HomeLowHigh:
		
		return false;
		
	default:
		
		break;
		
	}
	
	return TargetReached ( 0.0 );
	
};

bool LinearSlide :: TargetReached ( double Tolerance )
{
	
	if ( ! Enabled )
		return false;
	
	switch ( State )
	{
	
	case kMode_Velocity:
		
		return false;
		
	case kMode_Position:
		
		return abs ( Motor -> GetPosition () - Targeter.Get () ) < Tolerance;
		
	case kMode_HomeLow:
		
		if ( Limit == NULL )
			return abs ( Motor -> GetPosition () - LowLimit ) < Tolerance;
		
		switch ( Limit -> GetBounding () )
		{
		
		case IMotionLimit :: kLimitBounding_HighLow:
		case IMotionLimit :: kLimitBounding_Low:
			
			return ( Limit -> GetLowLimit () ) || ( abs ( Motor -> GetPosition () - LowLimit ) < Tolerance );
			
		default:
			
			break;
			
		}
		
		return abs ( Motor -> GetPosition () - LowLimit ) < Tolerance;
		
	case kMode_HomeHigh:
		
		if ( Limit == NULL )
			return abs ( Motor -> GetPosition () - HighLimit ) < Tolerance;
		
		switch ( Limit -> GetBounding () )
		{
		
		case IMotionLimit :: kLimitBounding_High:
		case IMotionLimit :: kLimitBounding_HighLow:
			
			return ( Limit -> GetHighLimit () ) || ( abs ( Motor -> GetPosition () - HighLimit ) < Tolerance );
			
		default:
			
			break;
			
		}
		
		return abs ( Motor -> GetPosition () - HighLimit ) < Tolerance;
		
	case kMode_HomeLowHigh:
		
		return false;
			
	}
	
	return abs ( Targeter.Get () - Motor -> GetPosition () ) <= Tolerance;
	
};

double LinearSlide :: GetPosition ()
{
	
	return Motor -> GetPosition ();
	
};

double LinearSlide :: GetHighLimit ()
{
	
	return LowLimit;
	
};

double LinearSlide :: GetLowLimit ()
{
	
	return HighLimit;
	
};

void LinearSlide :: Update ()
{
	
	double Target = Targeter.Get ();
	
	switch ( State )
	{
		
	case kMode_Velocity:
		
		Motor -> SetTarget ( Targeter.Get () ); 
		
		if ( Limit != NULL )
		{
			
			switch ( Limit -> GetBounding () )
			{
			
			case IMotionLimit :: kLimitBounding_Low:
				
				if ( ( Limit -> GetLowLimit () ) && ( Targeter.GetSpeed () < 0 ) )
				{
					
					double MPosition = Motor -> GetPosition ();
					
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
				}
				
				break;
				
			case IMotionLimit :: kLimitBounding_High:
				
				if ( ( Limit -> GetHighLimit () ) && ( Targeter.GetSpeed () > 0 ) )
				{
					
					double MPosition = Motor -> GetPosition ();
					
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
				}
				
				break;
				
			case IMotionLimit :: kLimitBounding_HighLow:
				
				if ( ( Limit -> GetLowLimit () ) && ( Targeter.GetSpeed () < 0 ) )
				{
					
					double MPosition = Motor -> GetPosition ();
					
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
				}
				
				if ( ( Limit -> GetHighLimit () ) && ( Targeter.GetSpeed () > 0 ) )
				{
					
					double MPosition = Motor -> GetPosition ();
						
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
				}
				
				break;
				
			default:
				
				break;
			
			}
			
		}
		
		if ( Target > HighLimit )
		{
			
			Targeter.SetSpeed ( 0.0 );
			Targeter.Set ( HighLimit );
			
			Target = HighLimit;
			
			Motor -> SetTarget ( HighLimit );
			
		}
		else if ( Target < LowLimit )
		{
			
			Targeter.SetSpeed ( 0.0 );
			Targeter.Set ( LowLimit );
			
			Target = LowLimit;
			
			Motor -> SetTarget ( LowLimit );
			
		}
		
		break;
		
	case kMode_HomeLow:
		
		Motor -> SetTarget ( Targeter.Get () ); 
		
		if ( Limit != NULL )
		{
			
			switch ( Limit -> GetBounding () )
			{
				
			case IMotionLimit :: kLimitBounding_Low:
			case IMotionLimit :: kLimitBounding_HighLow:
				
				if ( Limit -> GetLowLimit () )
				{
					
					Targeter.SetSpeed ( 0 );
					
					double MPosition = Motor -> GetPosition ();
					
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
					LowLimit = MPosition;
					
				}
				
				break;
				
			default:
				break;
			
			}
			
		}
		
		break;
		
	case kMode_HomeHigh:
		
		Motor -> SetTarget ( Targeter.Get () ); 
		
		if ( Limit != NULL )
		{
			
			switch ( Limit -> GetBounding () )
			{
				
			case IMotionLimit :: kLimitBounding_High:
			case IMotionLimit :: kLimitBounding_HighLow:
				
				if ( Limit -> GetHighLimit () )
				{
					
					Targeter.SetSpeed ( 0 );
					
					double MPosition = Motor -> GetPosition ();
					
					Motor -> SetTarget ( MPosition );
					Targeter.Set ( MPosition );
					
					HighLimit = MPosition;
					
				}
				
				break;
				
			default:
				break;
			
			}
			
		}
		
		break;
		
	case kMode_HomeLowHigh:
		
		Motor -> SetTarget ( Targeter.Get () ); 
		
		if ( Limit != NULL )
		{
			
			if ( Limit -> GetLowLimit () )
			{
				
				Targeter.SetSpeed ( 0 );
				
				double MPosition = Motor -> GetPosition ();
				
				Motor -> SetTarget ( MPosition );
				Targeter.Set ( MPosition );
				
				LowLimit = MPosition;
				
				Targeter.SetSpeed ( HomingSpeed );
				
				State = kMode_HomeHigh;
				
			}
			
		}
		
		break;
		
	default:
		
		return;
		
	}
	
};

void LinearSlide :: SetLowLimit ( double LowLimit )
{
	
	double Delta = LowLimit - this -> LowLimit;
	
	Motor -> SetPosition ( Motor -> GetPosition () + Delta );
	Targeter.Set ( Targeter.Get () + Delta );
	
	this -> LowLimit += Delta;
	this -> HighLimit += Delta;
};

void LinearSlide :: SetHighLimit ( double HighLimit )
{
	
	double Delta = HighLimit - this -> HighLimit;
	
	Motor -> SetPosition ( Motor -> GetPosition () + Delta );
	Targeter.Set ( Targeter.Get () + Delta );
	
	this -> LowLimit += Delta;
	this -> HighLimit += Delta;
	
};

void LinearSlide :: OverrideLowLimit ( double LowLimit )
{
	
	this -> LowLimit = LowLimit;
	
};

void LinearSlide :: OverrideHighLimit ( double HighLimit )
{
	
	this -> HighLimit = HighLimit;
	
};

void LinearSlide :: Disable ()
{
	
	Motor -> Disable ();
	
	Targeter.Stop ();
	
	Enabled = false;
	
};

void LinearSlide :: Enable ()
{
	
	Enabled = true;
	
	Targeter.Start ();
	
	Motor -> Enable ();
	
};

bool LinearSlide :: GetEnabled ()
{
	
	return Enabled;
	
};
