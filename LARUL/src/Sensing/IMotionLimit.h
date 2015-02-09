#ifndef LARUL_IMOTIONLIMIT_H
#define LARUL_IMOTIONLIMIT_H

class IMotionLimit
{
public:
	
	typedef enum
	{
		
		kLimitBounding_High,
		kLimitBounding_Low,
		kLimitBounding_HighLow
		
	} LimitBounding;
	
	virtual ~IMotionLimit () {};
	
	virtual LimitBounding GetBounding () = 0;
	
	virtual bool GetHighLimit () = 0;
	virtual bool GetLowLimit () = 0;
	
};

#endif
