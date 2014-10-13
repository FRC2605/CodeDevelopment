#ifndef BUSYBOXMAIN_H
#define BUSYBOXMAIN_H

#include <WPILib.h>

#include "NumericStepper.h"

class BusyBoxMain : public IterativeRobot
{
public:
	
	BusyBoxMain ();
	~BusyBoxMain ();
	
	void TeleopInit ();
	void TeleopPeriodic ();
	
	void DisabledInit ();
	
private:
	
	Talon Motor1;
	Talon Motor2;
	Talon Motor3;
	Talon Motor4;
	Talon Motor5;
	Talon Motor6;
	Talon Motor7;
	Talon Motor8;
	Talon Motor9;
	Talon Motor10;
	
	Servo Servo1;
	Servo Servo2;
	
	Joystick JoystickA;
	Joystick JoystickB;
	
	NumericStepper Step1;
	NumericStepper Step2;
	
	DriverStationLCD * LCD;
	
	int Counter;
	
};

#endif
