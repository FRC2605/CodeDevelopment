#ifndef LARUL_ACTIONCONTROLLER_H
#define LARUL_ACTIONCONTROLLER_H

#include <stdint.h>

#include "../Util/Vector.h"

#include "IAction.h"

class ActionController
{
public:
	
	ActionController ();
	~ActionController ();
	
	void AddAction ( IAction * Action );
	void RemoveAction ( IAction * Action );
	
	IAction * GetCurrentAction ();
	
	void Start ( IAction * Beginning = NULL );
	void Stop ();
	void Reset ();
	
	bool IsFinished ();
	
	void Update ();
	
private:
	
	typedef enum
	{
		
		kState_Stopped,
		kState_Running,
		kState_Paused
		
	} State;
	
	Vector <IAction *> Actions;
	
	uint32_t CurrentActionIndex;
	State CurrentState;
	
	bool Finished;
	
};

#endif
