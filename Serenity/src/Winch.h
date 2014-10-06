#ifndef WINCH_H
#define WINCH_H

#include <WPILib.h>

class WinchConfig;

class Winch
{
public:
	
	friend class WinchConfig;
	
	Winch ( AnalogChannel * Angle, SpeedController * WinchMotor );
	~Winch ();
	
	void SetInverted ( bool Inverted );
	
	void SetAngleScale ( double Scale );
	double GetAngleScale ();
	
	void SetAngleOffset ( double Offset );
	double GetAngleOffset ();
	
	void CalibrateLowAngle ();
	void CalibrateHighAngle ();
	
	void SetDriveScale ( double Scale );
	void SetDrive ( double Drive, bool Limit = true );
	
	void Enable ();
	void Disable ();
	
private:
	
	AnalogChannel * Angle;
	SpeedController * WinchMotor;
	
	double DriveScale;
	bool Inverted;
	
	bool Enabled;
	
	double HighLimit;
	double LowLimit;
	
	double Scale;
	double Offset;
	
};

#endif
