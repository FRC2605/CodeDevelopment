#include "../Behaviors/BehaviorController.h"

#include <iostream>

BehaviorController :: BehaviorController ():
	Behaviors ()
{
};

BehaviorController :: ~BehaviorController ()
{
};

void BehaviorController :: AddBehavior ( IBehavior * NewBehavior, const char * Name )
{
	
	BehaviorRecord * CurrentRecord = GetBehavior ( Name );
	
	if ( CurrentRecord != NULL )
	{
		
		IBehavior * OldBehavior = CurrentRecord -> Behavior;
		BehaviorState OldState = CurrentRecord -> State;
		
		if ( OldState != kBehaviorState_Stopped )
			OldBehavior -> Stop ();
		
		OldBehavior -> Destroy ();
		
	}
	else
	{
		
		Behaviors.Push ( BehaviorRecord () );
		
		CurrentRecord = & Behaviors [ Behaviors.Length () - 1 ];
		
	}
	
	CurrentRecord -> Behavior = NewBehavior;
	CurrentRecord -> State = kBehaviorState_Stopped;
	CurrentRecord -> Name = Name;
	
	NewBehavior -> Init ( this, Name );
	
};

void BehaviorController :: RemoveBehavior ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( ( Name == Behaviors [ i ].Name ) || ( strcmp ( Behaviors [ i ].Name, Name ) == 0 ) )
		{
			
			if ( Behaviors [ i ].State == kBehaviorState_Running )
				Behaviors [ i ].Behavior -> Stop ();
			
			Behaviors [ i ].Behavior -> Destroy ();
			
			Behaviors.Remove ( i, 1 );
			
			break;
			
		}
		
	}
	
};

void BehaviorController :: StartBehavior ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( ( Name == Behaviors [ i ].Name ) || ( strcmp ( Behaviors [ i ].Name, Name ) == 0 ) )
		{
			
			if ( Behaviors [ i ].State == kBehaviorState_Running )
				break;
			
			std :: cout << "Starting behavior: " << Name << "\n";
			
			Behaviors [ i ].State = kBehaviorState_Running;
			Behaviors [ i ].Behavior -> Start ();
			
			break;
			
		}
		
	}
	
};

void BehaviorController :: StopBehavior ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( ( Name == Behaviors [ i ].Name ) || ( strcmp ( Behaviors [ i ].Name, Name ) == 0 ) )
		{
			
			if ( Behaviors [ i ].State == kBehaviorState_Stopped )
				break;
			
			std :: cout << "Stopping behavior: " << Name << "\n";
			
			Behaviors [ i ].State = kBehaviorState_Stopped;
			Behaviors [ i ].Behavior -> Stop ();
			
			break;
			
		}
		
	}
	
};

void BehaviorController :: Update ()
{
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( Behaviors [ i ].State == kBehaviorState_Running )
			Behaviors [ i ].Behavior -> Update ();
		
	}
	
};

BehaviorController :: BehaviorRecord * BehaviorController :: GetBehavior ( const char * Name )
{
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( strcmp ( Behaviors [ i ].Name, Name ) == 0 )
			return & Behaviors [ i ];
		
	}
	
	return NULL;
	
};
