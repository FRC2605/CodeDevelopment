#ifndef LARUL_ALIGNOF_H
#define LARUL_ALIGNOF_H

#ifndef alignof
	#define alignof ( x ) ( sizeof ( ___AlignmentTestStruct___<x> ) - sizeof ( x ) )
#endif

template <class AlignedType>
typedef struct
{
	
	char C;
	AlignedType A;
	
} ___AlignmentTestStruct___;

#endif
