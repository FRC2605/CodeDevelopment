#ifndef LARUL_IPOSITIONDRIVE_H
#define LARUL_IPOSITIONDRIVE_H

class IPositionDrive : public IActuatorDrive
{
public:
	
	virtual void DrivePosition ( double Position ) = 0;
	
	virtual void SetPositionScale ( double PositionScale ) = 0;
	virtual double GetPositionScale () = 0;
	
};

#endif
