#include "AsyncAllocator.h"

// NOT DONE!!!!

AsyncAllocator :: AsyncAllocator ( IAllocSpec Spec, uint32_t MinimumBatch, uint32_t MaximumBatch ):
	Mode ( kAllocationMode_AsyncCaching ),
	Spec ( Spec ),
	Minimum ( MinimumBatch ),
	Maximum ( MaximumBatch ),
	TaskClosure ( this, & AsyncAllocator :: AllocationTask ),
	AllocationThread ( & TaskClosure, true ),
	AllocSignal ( true ),
	GeneralSync (),
	TimeSync (),
	ModeSync (),
	AllocationSlots ( NULL ),
	CurrentSlots ( 0 ),
	Running ( false )
{	
};

void AsyncAllocator :: SetMode ( AllocationMode Mode )
{
	
	Synchronized Sync ( & GeneralSync );
	Synchronized Sync ( & ModeSync );
	
	this -> Mode = Mode;
	
};

void AsyncAllocator :: Start ()
{
	
	Synchronized Sync ( & GeneralSync );
	
	if ( Running )
		return;
	
	AllocationThread.Start ();
	
};

void AsyncAllocator :: Alloc ( void ** Memory )
{
	
	ModeSync.Lock ();
	AllocationMode CurrentMode = Mode;
	ModeSync.Unlock ();
	
	switch ( CurrentMode )
	{
		
	case kAllocationMode_AsyncCaching:
		
		
	
		break;
		
	case kAllocationMode_AsyncNoCache:
		
		
		
		break;
		
	case kAllocationMode_SyncCaching:
		
		GeneralSync.Lock ();
		
		if ( CurrentSlots != 0 )
		{
			
			CurrentSlots --;
			* Memory = AllocationSlots [ CurrentSlots ];
			
			GeneralSync.Unlock ();
			
			return;
			
		}
		
		GeneralSync.Unlock ();
		
		int ErrorCode = posix_memalign ( Memory, Spec.GetAlign (), Spec.GetSize () );
		
		switch ( ErrorCode )
		{
			
		case 0:
			break;
			
		case ENOMEM:
			THROW_ERROR ( "Out of memory!" );
			
		case EINVAL:
			THROW_ERROR ( "Invalid alignment for allocation!" );
			
		default:
			THROW_ERROR ( "Unspecified error allocating memory!" );
			
		}
		
		break;
		
	case kAllocationMode_SyncNoCache:
		
		int ErrorCode = posix_memalign ( Memory, Spec.GetAlign (), Spec.GetSize () );
		
		switch ( ErrorCode )
		{
			
		case 0:
			break;
			
		case ENOMEM:
			THROW_ERROR ( "Out of memory!" );
			
		case EINVAL:
			THROW_ERROR ( "Invalid alignment for allocation!" );
			
		default:
			THROW_ERROR ( "Unspecified error allocating memory!" );
			
		}
		
		break;
		
	}
	
};
