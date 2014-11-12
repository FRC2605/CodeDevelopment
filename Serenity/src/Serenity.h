#ifndef SERENITY_H
#define SERENITY_H

#include <WPILib.h>

#include "MecanumDrive.h"
#include "Shooter.h"
#include "Winch.h"

#include "ButtonMonitor.h"
#include "NumericStepper.h"

#include "ConfigFile.h"
#include "WinchConfig.h"

class Serenity : public IterativeRobot
{
public:	
	
	Serenity ();
	~Serenity ();
	
	void TeleopInit ();
	void TeleopPeriodic ();
	
	void TestInit ();
	void TestPeriodic ();
	
	void DisabledInit ();
	
private:
	
	Talon WheelFL, WheelFR, WheelRL, WheelRR;
	MecanumDrive Drive;
	
	Talon TriggerMotor, FlyWheel;
	Encoder FlyWheelEncoder;
	PIDController FlyWheelController;
	
	Talon WinchMotor;
	
	Joystick JoyStrafe;
	Joystick JoyRotate;
	
	NumericStepper FlyWheelSpeed;
	ButtonMonitor FlyWheelToggle;
	
	bool FlyWheelEnabled;
	
	DriverStationLCD * LCD;
	
};

#endif
