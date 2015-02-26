#ifndef LARUL_ANGULARROTATIONTRACKER_H
#define LARUL_ANGULARROTATIONTRACKER_H

#include "IAngularInput.h"

class AngularRotationTracker
{
public:
	
	typedef enum
	{
		
		kUnit_Rotations,
		kUnit_Radians,
		kUnit_Degrees
		
	} Unit;
	
	AngularRotationTracker ( IAngularInput * Input );
	~AngularRotationTracker ();
	
	double Get ();
	void Set ( double Value );
	
	void SyncAngle ();
	
	void SetOutputUnit ( Unit OutputUnit );
	
	void Update ();
	
private:
	
	IAngularInput * Input;
	
	Unit OutputUnit;
	
	double Last;
	double Elapsed;
	
};

#endif
