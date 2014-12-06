#ifndef LARUL_ALIGNOF_H
#define LARUL_ALIGNOF_H

#ifndef alignof
	#define alignof(x) ( sizeof ( struct ___AlignmentTestStruct___<x> ) - sizeof ( x ) )
#endif

/*
* This utility header is for alignof. Most compilers don't provide a mechanism for determining natural alignment of data types, so this serves as a workaround.
* NOTE: this will only work on a compiler that has alignment optimization enabled, which is really the only place it's useful anyway.
*/

template <class AlignedType>
struct ___AlignmentTestStruct___
{
	
	char C;
	AlignedType A;
	
};

#endif
