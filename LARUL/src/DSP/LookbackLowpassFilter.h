#ifndef LARUL_LookbackLowpassFilter_H
#define LARUL_LookbackLowpassFilter_H

#include <stdint.h>

#include "DSPFilter.h"

#include "../LARULTuning.h"

/* LookbackLowpassFilter: A lowpass filter which averages a defined number of previous values and computes
* a maximum value within the set slew rate. If the supplied value is outside of this rate, it is clipped to
* the maximum allowed slew.
*
* This filter has three modes. The first is BypassNoCompute, skipping computation. The second is BypassCompute,
* which still bypasses operation on the data, but the filter keeps updating the lookback store for future operation.
* The third and most useful mode is the Compute mode, where the filter actively comuptes and operates on received 
* data.
*/

class LookbackLowpassFilter : public DSPFilter_1_1
{
public:
	
	typedef enum
	{
		
		kMode_BypassNoCompute,
		kMode_BypassCompute,
		kMode_ComputeSlew
		
	} LookbackLowpassFilterMode;
	
	LookbackLowpassFilter ( double MaximumSlew, uint32_t LookbackSize = FILTER_LOOKBACK_SIZE_DEFAULT, LookbackLowpassFilterMode Mode = kMode_ComputeSlew );
	~LookbackLowpassFilter ();
	
	// Compute data.
	void Compute ( double Feed );
	// Read computed data.
	double Read ();
	// Reset the filter.
	void Reset ();
	
	// Set the number of averaging values.
	void SetLookbackSize ( uint32_t LookbackSize );
	// Set the maximum slew rate relative to lookback average. ( n Per compute )
	void SetMaximumSlewrate ( double MaxSlew );
	// Set the mode.
	void SetFilterMode ( LookbackLowpassFilterMode Mode );
	
private:
	
	uint32_t LookbackSize;
	double MaxSlew;
	LookbackLowpassFilterMode Mode;
	
	uint32_t Offset;
	
	double * Lookback;
	
};

#endif
