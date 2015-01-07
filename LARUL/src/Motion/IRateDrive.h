#ifndef LARUL_IRATEDRIVE_H
#define LARUL_IRATEDRIVE_H

class IRateDrive
{
public:
	
	virtual void DriveRate ( double Rate ) = 0;
	
	virtual void SetRateScale ( double RateScale ) = 0;
	virtual double GetRateScale () = 0;
	
};

#endif
