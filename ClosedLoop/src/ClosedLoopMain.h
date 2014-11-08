#ifndef CLOSEDLOOP_MAIN_H
#define CLOSEDLOOP_MAIN_H

#include <stdint.h>
#include <WPILib.h>

#include "NumericStepper.h"

class ClosedLoopMain : public IterativeRobot
{
public:
	
	ClosedLoopMain ();
	~ClosedLoopMain ();
	
	void TeleopInit ();
	void TeleopPeriodic ();
	
	void DisabledInit ();
	
private:
	
	Encoder MotorRate;
	Talon MotorOut;
	PIDController MotorController;
	
	Joystick Joy;
	
	NumericStepper Step;
	
	uint32_t Counter;
	
	DriverStationLCD * LCD;
	
};

#endif
