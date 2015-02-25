#include "ActionController.h"

ActionController :: ActionController ():
	Actions (),
	CurrentActionIndex ( 0 ),
	CurrentState ( ActionController :: kState_Stopped ),
	Finished ( false )
{
};

ActionController :: ~ActionController ()
{
	
	Stop ();
	
};

void ActionController :: AddAction ( IAction * Action )
{
	
	if ( Action == NULL )
		return;
	
	Actions.Push ( Action );
	
};

void ActionController :: RemoveAction ( IAction * Action )
{
	
	int32_t Index = Actions.IndexOf ( Action );
	
	if ( Index - 1 )
		return;
	
	if ( CurrentState == ActionController :: kState_Running )
	{
		
		if ( Index == static_cast <int32_t> ( CurrentActionIndex ) )
			Actions [ Index ] -> Stop ();
		
	}
	
	Actions.Remove ( Index, 1 );
	
};

IAction * ActionController :: GetCurrentAction ()
{
	
	if ( CurrentActionIndex >= Actions.Length () )
		return NULL;
	
	return Actions [ CurrentActionIndex ];
	
};

void ActionController :: Start ( IAction * Beginning )
{
	
	if ( CurrentState == ActionController :: kState_Running )
		return;
	
	if ( CurrentState == ActionController :: kState_Stopped )
	{
		
		if ( Beginning != NULL )
		{
			
			int32_t Index = Actions.IndexOf ( Beginning );
			
			if ( Index != - 1 )
				CurrentActionIndex = Index;
			
		}
		
		for ( uint32_t i = CurrentActionIndex; i < Actions.Length (); i ++ )
			Actions [ i ] -> Reset ();
		
	}
	
	if ( CurrentActionIndex >= Actions.Length () )
		return;
	
	Actions [ CurrentActionIndex ] -> Start ();
	
	CurrentState = kState_Running;
	Finished = false;
	
	Update ();
	
};

void ActionController :: Stop ()
{
	
	if ( CurrentState != ActionController :: kState_Running )
		return;
	
	if ( CurrentActionIndex < Actions.Length () )
		Actions [ CurrentActionIndex ] -> Stop ();
	
	CurrentState = kState_Paused;
	
};

void ActionController :: Reset ()
{
	
	if ( CurrentState == ActionController :: kState_Running )
		return;
	
	CurrentActionIndex = 0;
	Finished = false;
	
};

void ActionController :: Update ()
{
	
	if ( CurrentState == ActionController :: kState_Running )
	{
		
		if ( CurrentActionIndex >= Actions.Length () )
			return;
		
		if ( Actions [ CurrentActionIndex ] -> IsComplete () )
		{
			
			Actions [ CurrentActionIndex ] -> Stop ();
			
			CurrentActionIndex ++;
			
			if ( CurrentActionIndex >= Actions.Length () )
			{
				
				CurrentState = kState_Stopped;
				Finished = true;
				
				return;
				
			}
			else
				Actions [ CurrentActionIndex ] -> Start ();
			
		}
		
		Actions [ CurrentActionIndex ] -> Update ();
		
	}
	
};

bool ActionController :: IsFinished ()
{
	
	return Finished;
	
};
