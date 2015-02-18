/*
 * DITalonPositionServo.cpp
 *
 *  Created on: Feb 14, 2015
 *      Author: bmck
 */

#include <Hardware/Drive/DITalonPositionServo.h>

DITalonPositionServo::DITalonPositionServo(
		uint32_t motorChannel,
		uint32_t encoderCh1,
		uint32_t encoderCh2) :
		Motor(motorChannel),
		Feedback(encoderCh1, encoderCh2),
		Controller(0.0, 0.0, 0.0, &Feedback, &Motor),
		Target(0),
		Enabled(false)
{
	Feedback.SetDistancePerPulse(1.0);
}
DITalonPositionServo::DITalonPositionServo(
		uint32_t motorChannel,
		uint32_t encoderCh1,
		uint32_t encoderCh2,
		float kp, float ki, float kd) :
		Motor(motorChannel),
		Feedback(encoderCh1, encoderCh2),
		Controller(kp, ki, kd, &Feedback, &Motor),
		Target(0),
		Enabled(false)
{
	Feedback.SetDistancePerPulse(1.0);
}

void DITalonPositionServo::SetPosition(double position) {
	Feedback.Reset();
}

double DITalonPositionServo::GetPosition() {
	return Feedback.GetDistance();
}

void DITalonPositionServo::SetTarget(double target) {
	Target = target;
	if (Controller.GetSetpoint() != target) {
		Controller.SetSetpoint(target);
	}
}

double DITalonPositionServo::GetTarget() {
	return Target;
}

void DITalonPositionServo::Enable() {
	if ( Enabled )
		return;

	Controller.SetSetpoint(Target);

	Enabled = true;
}

void DITalonPositionServo::Disable() {
	if ( !Enabled )
		return;

	Enabled = false;
}

bool DITalonPositionServo::GetEnabled() {
	return Enabled;
}

DITalonPositionServo :: ~DITalonPositionServo() {
}

