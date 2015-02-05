#ifndef LARUL_CANJAGUARMECANUMDRIVEBASE_H
#define LARUL_CANJAGUARMECANUMDRIVEBASE_H

#include <WPILib.h>

#include "../Motors/CANJaguarConfiguration.h"

class CANJaguarQuadDriveBase
{
	
	typedef enum
	{
		
		kMotorPosition_FL = 0,
		kMotorPosition_FR = 1,
		kMotorPosition_RL = 2,
		kMotorPosition_RR = 3
		
	} MotorPosition;
	
	CANJaguarQuadDriveBase ( uint8_t CAN_ID_FL, uint8_t CAN_ID_FR, uint8_t CAN_ID_RL, uint8_t CAN_ID_RR, CANJaguarConfiguration Config );
	~CANJaguarQuadDriveBase ();
	
	void SetInversion ( bool Fl, bool FR, bool RL, bool RR );
	
	void SetMotor ( MotorPosition Motor, double Value );
	
	// HWSystem interface
	void Enable ();
	void Disable ();
	
	bool GetEnabled ();
	
	// IPowerScalable interface
	
	PowerProfile * GetProfile ();
	PowerUsageSpec * GetSpec ();
		
	void SetPowerScale ( double Scale );
	
private:
	
	
	
};

#endif
