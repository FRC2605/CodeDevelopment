#ifndef LARUL_SINGLEALLOCSPEC_H
#define LARUL_SINGLEALLOCSPEC_H

#include "IAllocSpec.h"
#include "AlignOf.h"

/*
* SingleAllocSpec defines a template class that implements IAllocSpec. It derives this spec from the natural size and alignment of the supplied type.
*/

template <class AllocType>
class SingleAllocSpec : public IAllocSpec
{
public:
	
	SingleAllocSpec ()
	{
		
		AllocSize = sizeof ( AllocType );
		AllocAlign = alignof ( AllocType );
		
	};
	
	size_t GetSize ()
	{
		
		return AllocSize;
		
	};
	
	size_t GetAlign ()
	{
		
		return AllocAlign;
		
	};
	
private:
	
	size_t AllocSize;
	size_t AllocAlign;
	
};

#endif
