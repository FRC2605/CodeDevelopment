#ifndef FRC2605_SERENITY_H
#define FRC2605_SERENITY_H

#include <WPILib.h>

#include "MecanumDrive.h"
#include "Winch.h"
#include "ShooterTrigger.h"

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
	
	ConfigFile Config;
	
	Talon WheelFL, WheelFR, WheelRL, WheelRR;
	MecanumDrive Drive;
	
	Talon TriggerMotor, FlyWheel;
	
	Encoder FlyWheelEncoder;
	DigitalInput TriggerSwitch;
	AnalogChannel AngleInput;
	
	PIDController FlyWheelController;
	ShooterTrigger TriggerController;
	Winch WinchController;
	
	Talon WinchMotor;
	
	Joystick JoyStrafe;
	Joystick JoyRotate;
	
	NumericStepper FlyWheelSpeed;
	ButtonMonitor FlyWheelToggle;
	ButtonMonitor Trigger;
	
	bool FlyWheelEnabled;
	
	DriverStationLCD * LCD;
	
};

#endif
