#ifndef LARUL_VXWORKSMEMALIGNPATCH_H
#define LARUL_VMWORKSMEMALIGNPATCH_H

#include <memLib.h>

int posix_memalign ( void ** MemPtr, size_t Align, size_t Size )
{
	
	* MemPtr = memalign ( Align, Size );
	
	if ( MemPtr == NULL )
		return errno;
	
	return 0;
	
};

#endif
