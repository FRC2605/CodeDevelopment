#include "Clock.h"

#include <time.h>
#include <sys/types.h>

#include "../Util/LError.h"

#ifndef __VXWORKS__
	#include <sys/time.h>
#else
	#include <timers.h>
#endif

uint64_t Clock :: GetTimeMonotonicMS ()
{
	
	uint64_t TimeMS;
	
#if (defined(_POSIX_TIMERS) && (_POSIX_TIMERS+0 > 0)) || defined(__VXWORKS__)
	
	struct timespec Time;
	clock_gettime ( CLOCK_MONOTONIC, & Time );
	
	TimeMS = Time.tv_nsec / 1000000;
	TimeMS += Time.tv_sec * 1000;
	
#else
	
	/* Note: This solution is vounerable to NTP jumps and should probably be fixed at some point.
	* On any real target of LARUL, posix timers are expected to be implemented, but we have this
	* here for development purposes. This is not monotonic.
	*/
	
	// TODO: test for and implement platform specific monotoinc clocks.
	
	struct timeval TimeV;
	
	if ( gettimeofday ( & TimeV, NULL ) == -1 )
		THROW_ERROR ( "Unspecified error getting time!" );
	
	TimeMS = TimeV.tv_usec / 1000;
	TimeMS += TimeV.tv_sec * 1000;
	
#endif
	
	return TimeMS;
	
};

uint64_t Clock :: GetTimeSystemMS ()
{
	
	uint64_t TimeMS;
	
#if (defined(_POSIX_TIMERS) && (_POSIX_TIMERS+0 > 0)) || defined(__VXWORKS__)
	
	struct timespec Time;
	clock_gettime ( CLOCK_REALTIME, & Time );
	
	TimeMS = Time.tv_nsec / 1000000;
	TimeMS += Time.tv_sec * 1000;
	
#else
	
	struct timeval TimeV;
	
	if ( gettimeofday ( & TimeV, NULL ) == -1 )
		THROW_ERROR ( "Unspecified error getting time!" );
	
	TimeMS = TimeV.tv_usec / 1000;
	TimeMS += TimeV.tv_sec * 1000;
	
#endif
	
	return TimeMS;
	
};
