#ifndef LARUL_TUNING_H
#define LARUL_TUNING_H

// The default amount of vector elements allocated.
#define VECTOR_DEFAULT_SIZE 32

// The default minimum vector growth padding.
#define VECTOR_MINIMUM_GROWTHPAD 5

/* 
* In the event of an allocation error, the allocation is checked for sanity by comparing with this define.
* Currently, 512KB is considered a sane limit, given the application. 
* 
* NOTE: allocations greater than this can be made normally. This is just for error condition recovery.
*/
#define OVERSIZED_DATA_ALLOCATION 0x80000

// Default size for lookback buffers in filters
#define FILTER_LOOKBACK_SIZE_DEFAULT 16

// Whether or not we are building with WPILib
//#define NO_WPILIB

#endif
