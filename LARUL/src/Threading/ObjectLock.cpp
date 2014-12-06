#include "ObjectLock.h"

Vector <ObjectLock :: LockRecord> ObjectLock :: ActiveLocks = Vector <ObjectLock :: LockRecord> ();
Mutex ObjectLock :: ListSync = Mutex ();

void ObjectLock :: Lock ( void * Object )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < ActiveLocks.Length (); i ++ )
	{
		
		if ( ActiveLocks [ i ].Object == Object )
		{
			
			if ( ActiveLocks [ i ].Owner == Thread :: GetCurrentThread () )
			{
				
				ActiveLocks [ i ].Count ++;
				
				ListSync.Unlock ();
				
				return;
				
			}
			else
			{
				
				if ( ActiveLocks [ i ].WaitCond == NULL )
					ActiveLocks [ i ].WaitCond = new Condition ();
				
				Condition * TActive = ActiveLocks [ i ].WaitCond;
				
				ListSync.Unlock ();
				
				TActive -> LockWait ();
				TActive -> Reset ();
				
				ListSync.Lock ();
				
				TActive -> Unlock ();
				
			}
			
			ActiveLocks [ i ].Owner = Thread :: GetCurrentThread ();
			
			ListSync.Unlock ();
			
			return;
			
		}
		
	}
	
	LockRecord NewRecord;
	
	NewRecord.Object = Object;
	NewRecord.WaitCond = NULL;
	NewRecord.Count = 0;
	NewRecord.Owner = Thread :: GetCurrentThread ();
	
	ActiveLocks.Push ( NewRecord );
	
	ListSync.Unlock ();
	
};

bool ObjectLock :: TryLock ( void * Object )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < ActiveLocks.Length (); i ++ )
	{
		
		if ( ActiveLocks [ i ].Object == Object )
		{
			
			if ( ActiveLocks [ i ].Owner == Thread :: GetCurrentThread () )
			{
				
				ListSync.Unlock ();
				
				return true;
				
			}
			else
			{
				
				ListSync.Unlock ();
				
				return false;
				
			}
			
		}
		
	}
	
	LockRecord NewRecord;
	
	NewRecord.Object = Object;
	NewRecord.WaitCond = NULL;
	NewRecord.Count = 0;
	NewRecord.Owner = Thread :: GetCurrentThread ();
	
	ActiveLocks.Push ( NewRecord );
	
	ListSync.Unlock ();
	
	return true;
	
};

void ObjectLock :: Unlock ( void * Object, bool ClearCondition )
{
	
	ListSync.Lock ();
	
	for ( uint32_t i = 0; i < ActiveLocks.Length (); i ++ )
	{
		
		if ( ActiveLocks [ i ].Object == Object )
		{
			
			if ( ActiveLocks [ i ].Owner != Thread :: GetCurrentThread () )
				THROW_ERROR ( "Attempt to unlock an object not already owned by the unlocking thread!" );
			
			if ( ActiveLocks [ i ].Count != 0 )
			{
				
				ActiveLocks [ i ].Count --;
				
				ListSync.Unlock ();
				
				return;
				
			}
			
			if ( ActiveLocks [ i ].WaitCond != NULL )
			{
				
				ActiveLocks [ i ].WaitCond -> Signal ();
				
				ListSync.Unlock ();
				
				return;
				
			}
			else
			{
				
				ActiveLocks.Remove ( i, 1 );
				
				ListSync.Unlock ();
				
				return;
				
			}
			
		}
		
	}
	
	THROW_ERROR ( "Attempt to unlock an object not already owned by the unlocking thread!" );
	
};
