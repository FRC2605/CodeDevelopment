#ifndef LARUL_IMUTEX_H
#define LARUL_IMUTEX_H

class IMutex
{
public:
	
	virtual ~IMutex () = 0;
	
	virtual void Lock () = 0;
	virtual void Unlock () = 0;
	virtual bool TryLock () = 0;
	
};

#endif
