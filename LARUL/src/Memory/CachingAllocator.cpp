#include "CachingAllocator.h"

CachingAllocator :: CachingAllocator ( IAllocSpec * Spec, uint32_t CacheSize, uint32_t PreFill ):
	AllocSize ( Spec -> GetSize () ),
	AllocAlign ( Spec -> GetAlign () ),
	CacheSync (),
	CacheSize ( CacheSize ),
	CacheUsed ( PreFill )
{
	
	Cache = reinterpret_cast <void **> ( malloc ( sizeof ( void * ) * CacheSize ) );
	
	if ( Cache == NULL )
		THROW_ERROR ( "Failed to allocate cache!" );
	
	if ( PreFill > CacheSize )
	{
		
		CacheUsed = CacheSize;
		PreFill = CacheSize;
		
	}
	
	if ( AllocAlign < sizeof ( void * ) )
		AllocAlign = sizeof ( void * );
	
	for ( uint32_t i = 0; i < PreFill; i ++ )
	{
		
		int ErrorCode = posix_memalign ( & Cache [ i ], AllocAlign, AllocSize );
		
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
		
	}
};

CachingAllocator :: ~CachingAllocator ()
{
	
	for ( uint32_t i = 0; i < CacheUsed; i ++ )
		free ( Cache [ i ] );
	
};

void CachingAllocator :: Alloc ( void ** Memory )
{
	
	CacheSync.Lock ();
	
	if ( CacheUsed != 0 )
	{
		
		CacheUsed --;
		* Memory = Cache [ CacheUsed ];
		
		CacheSync.Unlock ();
		
		return;
		
	}
	
	CacheSync.Unlock ();
	
	int ErrorCode = posix_memalign ( Memory, AllocAlign, AllocSize );
		
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
	
};

void CachingAllocator :: Free ( void ** Memory )
{
	
	CacheSync.Lock ();
	
	if ( CacheUsed < CacheSize )
	{
		
		Cache [ CacheUsed ] = * Memory;
		CacheUsed ++;
		
		CacheSync.Unlock ();
		
		* Memory = NULL;
		
		return;
		
	}
	
	CacheSync.Unlock ();
	
	free ( * Memory );
	* Memory = NULL;
	
};
