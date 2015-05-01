#ifndef LARUL_IBEHAVIOR_H
#define LARUL_IBEHAVIOR_H

class BehaviorController;

/* IBehavior: Virtual base class for a behavior to be run by the BehaviorController
 *
 * Behaviors are like states in a state machine, but can be happening
 * sequentially and independently. You may notice that behaviors, unlike actions,
 * do not have a way to tell you if they're done. This is because behaviors must
 * stop themselves or be stopped externally. In order to write a self-stopping
 * behavior, you must keep track of the controller and applied ID passed to the
 * Init () call in the behavior when it is added to the controller.
 *
 * Methods:
 *
 * 	virtual void Init ( BehaviorController * Controller, const char * AppliedID )
 * 	--------------------------------------------------------------------------------
 * 	Called to initialize the behavior. This happens when the behavior is added to
 * 	the BehaviorController. It supplies a pointer to the controller and the ID of
 * 	this behavior.
 *
 * 	virtual void Destroy ()
 * 	--------------------------------------------------------------------------------
 * 	Called to deinitialize the behavior. This method is called when the behavior is
 * 	removed from the BehaviorController.
 *
 * 	virtual void Start ()
 * 	--------------------------------------------------------------------------------
 * 	Called to start the behavior. This tells the behavior that it has begun being
 * 	active and will receive Update () calls until it is stopped.
 *
 * 	virtual void Stop ()
 * 	--------------------------------------------------------------------------------
 * 	Called to stop the behavior. This tells the behavior to finish up anything that
 * 	it was doing and that it will no longer receive Update () calls until it is
 * 	started again, if ever.
 *
 * 	virtual void Update ()
 * 	--------------------------------------------------------------------------------
 * 	Called periodically while the behavior is active. ( Here is where you should be
 * 	doing a majority of the work of the behavior ) As with IAction, it is a bad idea
 * 	to block for long periods or do other waiting inside this function, as this will
 * 	stall the thread and prevent other behaviors from operating.
 *
 */

class IBehavior
{
public:
	
	virtual ~IBehavior () {};
	
	virtual void Init ( BehaviorController * Controller, const char * AppliedID ) = 0;
	virtual void Destroy () = 0;
	
	virtual void Start () = 0;
	virtual void Stop () = 0;
	
	virtual void Update () = 0;
	
};

#endif
