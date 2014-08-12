#ifndef LARUL_VECTOR_H
#define LARUL_VECTOR_H

#include <stdlib.h>

#include "Error.h"

#include "../LARULTuning.h"

template <typename T>
class Vector
{
public:
	
	Vector ()
	{
		
		Elements = reinterpret_cast <T *> ( malloc ( sizeof ( T ) * VECTOR_DEFAULT_SIZE ) );
		
		Allocated = VECTOR_DEFAULT_SIZE;
		Used = 0;
		
	};
	
	~Vector ()
	{
		
		free ( Elements );
		
	};
	
	inline T & operator[] ( size_t Index )
	{
		
		return & Elements [ Index ];
		
	};
	
	inline size_t Length ()
	{
		
		return Used;
		
	};
	
	inline void Push ( T Element )
	{
		
		if ( Used + 1 == Allocated )
			Grow ( 1 );
		
		Elements [ Used ] = Element;
		Used ++;
		
	};
	
	inline T Pop ()
	{
		
		if ( Used == 0 )
			THROW_ERROR ( "OUT OF BOUNDS ERROR (EMPTY)" );
		
		Used --;
		
		return Elements [ Used ];
		
	};
	
private:
	
	void Grow ( size_t Minimum )
	{
		
		size_t GrownSize = Allocated * 2;
		
		void * Elements = realloc ( Elements, GrownSize * sizeof ( T ) );
		
		if ( Elements == NULL )
		{
			
			if ( GrownSize * sizeof ( T ) > OVERSIZED_DATA_ALLOCATION )
			{
				
				GrownSize = Allocated + Minimum + VECTOR_MINIMUM_GROWTHPAD;
				
				Elements = realloc ( Elements, GrownSize * sizeof ( T ) );
				
				if ( Elements == NULL )
				{
					
					THROW_ERROR ( "ALLOCATION ERROR (FAILED)" );
					
					return;
					
				}
				
				this -> Elements = reinterpret_cast <T *> ( Elements );
				this -> Allocated = GrownSize;
				
			}
			
			THROW_ERROR ( "ALLOCATION ERROR (FAILED)" );
			
		}
		
		this -> Elements = reinterpret_cast <T *> ( Elements );
		this -> Allocated = GrownSize;
		
	};
	
	T * Elements;
	
	size_t Allocated;
	size_t Used;
	
};

#endif