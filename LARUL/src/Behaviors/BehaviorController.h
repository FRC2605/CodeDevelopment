#ifndef LARUL_BEHAVIORCONTROLLER_H
#define LARUL_BEHAVIORCONTROLLER_H

#include <string.h>

#include "../Behaviors/IBehavior.h"
#include "../Threading/Mutex.h"

#include "../Util/Vector.h"

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
