#ifndef SHS_2605_NUMERIC_STEPPER_H
#define SHS_2605_NUMERIC_STEPPER_H

#include "WPILib.h"

#include <stdint.h>

/*
* (WPILib specific.)
* NumericStepper is literally just that. You feed it an HID device and two button indexes and it will keep track of a counted value based on button presses.
* Note that Update () should be called every time there is new DS data, which should be taken care of in your main robot loop.
*/

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
