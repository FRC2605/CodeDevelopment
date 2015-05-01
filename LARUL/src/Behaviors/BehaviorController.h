#ifndef LARUL_BEHAVIORCONTROLLER_H
#define LARUL_BEHAVIORCONTROLLER_H

#include <string.h>

#include "../Behaviors/IBehavior.h"
#include "../Threading/Mutex.h"

#include "../Util/Vector.h"

/* BehaviorController: A controller object to manage the simultaneous execution of
 * behaviors. ( Behaviors being any instance of a class that implements the IBehavior
 * interface. )
 *
 * Methods:
 *
 * 	void AddBehavior ( IBehavior * NewBehavior, const char * Name )
 * 	---------------------------------------------------------------------------------
 * 	Adds a behavior to the internal map with a specific name. This name becomes the
 * 	unique identifier for this behavior, and is used to manipulate it's state through
 * 	the controller.
 *
 *	void RemoveBehavior ( const char * Name )
 * 	---------------------------------------------------------------------------------
 * 	Removes the behavior with the specified name. If it does not exist, nothing
 * 	happens. Any running behavior removed will first be stopped.
 *
 *	void StartBehavior ( const char * Name )
 * 	---------------------------------------------------------------------------------
 * 	Starts a behavior with the given name. If none with this name exists, nothing
 * 	happens. A behavior which is already running will not be re-started.
 *
 *	void StopBehavior ( const char * Name )
 * 	---------------------------------------------------------------------------------
 * 	Stops a behavior with the given name. If none with this name exists, nothing
 * 	happens. A behavior which is not running will not be re-stopped.
 *
 *	void Update ()
 * 	---------------------------------------------------------------------------------
 * 	Updates the controller's active behaviors. This should be called periodically so
 * 	long as any of the controller's behaviors are expected to be active.
 *
 */

class BehaviorController
{
public:
	
	BehaviorController ();
	~BehaviorController ();
	
	void AddBehavior ( IBehavior * NewBehavior, const char * Name );
	void RemoveBehavior ( const char * Name );
	
	void StartBehavior ( const char * Name );
	void StopBehavior ( const char * Name );
	
	void Update ();
	
private:
	
	typedef enum
	{
		
		kBehaviorState_Stopped,
		kBehaviorState_Running,
		
	} BehaviorState;
	
	typedef struct
	{
		
		IBehavior * Behavior;
		BehaviorState State;
		
		const char * Name;
		
	} BehaviorRecord;
	
	BehaviorRecord * GetBehavior ( const char * Name );
	
	Vector <BehaviorRecord> Behaviors;
	Mutex ListSync;
	
};

#endif
