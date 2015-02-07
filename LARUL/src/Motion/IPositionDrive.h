#ifndef LARUL_IPOSITIONDRIVE_H
#define LARUL_IPOSITIONDRIVE_H

class IPositionDrive : public IActuatorDrive
{
public:
	
	virtual ~IPositionDrive () {};
	
	virtual void SetPosition ( double Position ) = 0;
	virtual double GetPosition () = 0;
	
	virtual void SetTarget ( double Position ) = 0;
	virtual double GetTarget () = 0;
	
};

#endif
