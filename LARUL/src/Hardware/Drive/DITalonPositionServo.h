/*
 * DITalonPositionServo.h
 *
 *  Created on: Feb 14, 2015
 *      Author: bmck
 */

#ifndef HARDWARE_DRIVE_DITALONPOSITIONSERVO_H_
#define HARDWARE_DRIVE_DITALONPOSITIONSERVO_H_

#include <wpilib.h>

#include "../../Motion/IPositionDrive.h"

class DITalonPositionServo : public IPositionDrive
{
public:
	DITalonPositionServo(
		uint32_t motorChannel, uint32_t encoderCh1, uint32_t encoderCh2
	);
	DITalonPositionServo(
		uint32_t motorChannel, uint32_t encoderCh1, uint32_t encoderCh2,
		float kp, float ki, float kd
	);

	void SetPosition(double position);
	double GetPosition();

	void SetTarget(double target);
	double GetTarget();

	void Enable();
	void Disable();
	bool GetEnabled();

	virtual ~DITalonPositionServo();
private:
	Talon Motor;
	Encoder Feedback;
	PIDController Controller;

	double Target;

	bool Enabled;
};

#endif /* HARDWARE_DRIVE_DITALONPOSITIONSERVO_H_ */
