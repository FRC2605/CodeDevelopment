#ifndef LARUL_CANJAGUARMECANUMDRIVEBASE_H
#define LARUL_CANJAGUARMECANUMDRIVEBASE_H

#include <WPILib.h>

#include "../Motors/CANJaguarConfiguration.h"

class CANJaguarMecanumDriveBase
{
	
	typedef enum
	{
		
		kMecanumMotor_FL = 0,
		kMecanumMotor_FR = 1,
		kMecanumMotor_RL = 2,
		kMecanumMotor_RR = 3
		
	} MecanumMotor;
	
	CANJaguarMecanumDriveBase ( uint8_t CAN_ID_FL, uint8_t CAN_ID_FR, uint8_t CAN_ID_RL, uint8_t CAN_ID_RR, CANJaguarConfiguration Config );
	~CANJaguarMecanumDriveBase ();
	
	// HWSystem interface
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	// IPowerScalable interface
	
	
	void SetMotor ( MecanumMotor Motor, double Value );
	
};

#endif
