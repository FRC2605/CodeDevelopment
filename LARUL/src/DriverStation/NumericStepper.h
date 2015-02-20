#ifndef LARUL_NUMERICSTEPPER_H
#define LARUL_NUMERICSTEPPER_H

#include <stdint.h>

#include "../LARULTuning.h"

#ifndef NO_WPILIB
#include <WPILib.h>

class NumericStepper
{
public:

	NumericStepper ( GenericHID * Device, uint32_t UpButton, uint32_t DownButton );
	~NumericStepper ();

	// Set the maximum/minimum of the counter.
	void SetRange ( int32_t Min, int32_t Max );
	// Set the increment.
	void SetStep ( int32_t Step );

	// Get the current value.
	int32_t Get ();
	// Set the current value.
	void Set ( int32_t Value );

	// Update the monitor.
	void Update ();

private:

	GenericHID * Device;

	uint32_t UpButton;
	uint32_t DownButton;

	int32_t Value;

	int32_t Max;
	int32_t Min;
	
	int32_t Step;

	bool UpButtonState;
	bool DownButtonState;

};

#endif

#endif
