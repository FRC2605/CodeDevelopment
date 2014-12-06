#include "BehaviorController.h"

BehaviorController :: BehaviorController ():
	Behaviors (),
	ListSync ()
{
};

BehaviorController :: ~BehaviorController ()
{
};

void BehaviorController :: AddBehavior ( IBehavior * NewBehavior, const char * Name )
{
	
	ListSync.Lock ();
	
	BehaviorRecord * CurrentRecord = GetBehavior ( Name );
	
	if ( CurrentRecord != NULL )
	{
		
		IBehavior * OldBehavior = CurrentRecord -> Behavior;
		BehaviorState OldState = CurrentRecord -> State;
		
		if ( OldState == kBehaviorState_Stopped )
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
	
	NewBehavior -> Init ();
	
	ListSync.Unlock ();
	
};

void BehaviorController :: RemoveBehavior ( const char * Name )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( strcmp ( Behaviors [ i ].Name, Name ) == 0 )
		{
			
			if ( Behaviors [ i ].State == kBehaviorState_Running )
				Behaviors [ i ].Behavior -> Stop ();
			
			Behaviors [ i ].Behavior -> Destroy ();
			
			Behaviors.Remove ( i, 1 );
			
			break;
			
		}
		
	}
	
	ListSync.Unlock ();
	
};

void BehaviorController :: StartBehavior ( const char * Name )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( strcmp ( Behaviors [ i ].Name, Name ) == 0 )
		{
			
			if ( Behaviors [ i ].State != kBehaviorState_Stopped )
				break;
			
			Behaviors [ i ].State = kBehaviorState_Running;
			Behaviors [ i ].Behavior -> Start ();
			
			break;
			
		}
		
	}
	
	ListSync.Unlock ();
	
};

void BehaviorController :: StopBehavior ( const char * Name )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
	{
		
		if ( strcmp ( Behaviors [ i ].Name, Name ) == 0 )
		{
			
			if ( Behaviors [ i ].State != kBehaviorState_Running )
				break;
			
			Behaviors [ i ].State = kBehaviorState_Stopped;
			Behaviors [ i ].Behavior -> Stop ();
			
			break;
			
		}
		
	}
	
	ListSync.Unlock ();
	
};

void BehaviorController :: Update ()
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < Behaviors.Length (); i ++ )
		Behaviors [ i ].Behavior -> Update ();
	
	ListSync.Unlock ();
	
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
