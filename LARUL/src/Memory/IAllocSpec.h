#ifndef LARUL_IALLOCSPEC_H
#define LARUL_IALLOCSPEC_H

#include <stddef.h>

/*
* IAllocSpec is an interface for single-purpose allocators. It defines the size and alignment of a type.
*/

class IAllocSpec
{
public:
	
	virtual size_t GetSize () = 0;
	virtual size_t GetAlign () = 0;
	
	~IAllocSpec () {};
	
};

#endif
