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
	
	Talon WheelFL;
	Talon WheelFR;
	Talon WheelRL;
	Talon WheelRR;
	
	Talon Flywheel;
	Talon Trigger;
	
	Talon WinchMotor;
	
	AnalogChannel WinchAngle;
	
	DigitalInput TriggerSwitch;
	
	Joystick JoyStrafe;
	Joystick JoyRotate;
	NumericStepper ShooterSpeed;
	ButtonMonitor TriggerMonitor;
	ButtonMonitor ToggleMonitor;
	
	MecanumDrive Drive;
	Winch ShooterWinch;
	Shooter DiscShooter;
	
	ConfigFile Config;
	
	WinchConfig WinchConfiguration;
	
};

#endif
