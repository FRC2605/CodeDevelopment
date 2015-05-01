#ifndef LARUL_IACTION_H
#define LARUL_IACTION_H

/* IAction: Virtual base class for an Action to be run by the Action Controller.
 *
 * Actions are like sequential functions that don't happen in discrete time.
 *
 * Methods:
 *
 *	virtual void Reset ()
 *	----------------------------------------------------------------------------
 *	Resets the action to a known initial state. For example, if this action
 *	waits a specific amount of time before completing, reset would zero the
 *	running time, effectively resetting the timer.
 *
 *	virtual void Start ()
 *	----------------------------------------------------------------------------
 *	Starts the action. This is called at the beginning of an action's active
 *	period. For example, if you had an action to drive a motor for a specific
 *	amount of time, this would set it's speed to the running speed.
 *
 * 	virtual bool IsComplete ()
 * 	----------------------------------------------------------------------------
 * 	Returns to the caller whether the action is complete. For example, in an
 * 	action that waits a specific amount of time, you would return false until
 * 	the timer was beyond the trigger time. Another example would be an action
 * 	that waits for a limit switch to be pressed, where this method would return
 * 	true only if the limit switch was pressed.
 *
 * 	virtual void Stop ()
 * 	----------------------------------------------------------------------------
 * 	Stops the action. This method is designed to end any effects of the action,
 * 	like stopping a motor or turning off an indicator. Typically speaking, this
 * 	action will only be called right after IsComplete returns true, however,
 * 	this behavior is not guaranteed, and should not be relied on.
 *
 * 	virtual void Update ()
 * 	----------------------------------------------------------------------------
 * 	Updates the action. This method is called periodically in order to update
 * 	any state information in the action as well as perform any real-time control
 * 	of systems per the action's purpose. This method has no requirements other
 * 	than that generally, it should complete in discrete time. (IE no waiting
 * 	or blocking IO calls) This is to preserve system response time.
 *
 */

class IAction
{
public:
	
	virtual ~IAction () {};
	
	virtual void Reset () = 0;
	
	virtual void Start () = 0;
	virtual bool IsComplete () = 0;
	virtual void Stop () = 0;
	
	virtual void Update () = 0;
	
};


#endif
