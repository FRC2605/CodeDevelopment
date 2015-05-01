#ifndef LARUL_ACTIONCONTROLLER_H
#define LARUL_ACTIONCONTROLLER_H

#include <stdint.h>

#include "../Util/Vector.h"

#include "IAction.h"

/* ActionController: A controller object to manage the sequential execution of
 * actions.  (Actions being any instance of a class implementing the IAction
 * interface. )
 *
 *	ActionController ()
 *	--------------------------------------------------------------------------------
 * 	Constructor. Takes no parameters
 *
 * 	void AddAction ( IAction * Action )
 * 	---------------------------------------------------------------------------------
 * 	Adds an action to the internal action list. Takes the address of the action to be
 * 	added. This function should be called in the order that is wished for execution,
 * 	IE if action B should happen after action A, call AddAction ( & A ), then
 * 	AddAction ( & B ).
 *
 * 	void RemoveAction ( IAction * Action )
 * 	---------------------------------------------------------------------------------
 * 	Removes an action from the internal list. Takes the address of the action to be
 * 	removed, and removes it's first occurrence in the sequential internal list. It is
 * 	safe to remove an executing action from the list, however it will cause that
 * 	action to stop immediately.
 *
 * 	IAction * GetCurrentAction ()
 * 	---------------------------------------------------------------------------------
 * 	Returns the currently executing action. If no action is currently executing, NULL
 * 	is returned.
 *
 * 	void Start ( IAction * Beginning (OPTIONAL) )
 * 	---------------------------------------------------------------------------------
 * 	Starts the list of actions from the first occurrence of the supplied action in
 * 	the list. If no action or NULL is supplied, or the supplied action is not in the
 * 	internal list, then the controller will start from the last executing action.
 *
 * 	void Stop ()
 * 	---------------------------------------------------------------------------------
 * 	Stops the controller and currently executing action, if there is one.
 *
 * 	void Reset ()
 * 	---------------------------------------------------------------------------------
 * 	If the controller is not running, this method resets the list, such that calling
 * 	Start () with NULL will start the controller from the beginning.
 *
 * 	bool IsFinished ()
 * 	---------------------------------------------------------------------------------
 * 	Returns true if the list of actions has completely finished executing, otherwise
 * 	returns false.
 *
 * 	void Update ()
 * 	---------------------------------------------------------------------------------
 * 	Updates the currently executing action, as well as moving on the the next if the
 * 	current action is finished. This should be called periodically as long as the
 * 	controller and all actions inside it are supposed to be running.
 *
 */

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
