#ifndef LARUL_IALLOCSPEC_H
#define LARUL_IALLOCSPEC_H

#include <stddef.h>

class IAllocSpec
{
public:
	
	size_t GetSize () = 0;
	size_t GetAlign () = 0;
	
	~IAllocSpec () {};
	
};

#endif
