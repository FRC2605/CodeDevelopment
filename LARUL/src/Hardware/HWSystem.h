#ifndef LARUL_HWSYSTEM_H
#define LARUL_HWSYSTEM_H

class HWSystem
{
public:
	
	virtual ~HWSystem () {};
	
	virtual void Disable () = 0;
	virtual void Enable () = 0;
	
	virtual bool GetEnabled () = 0;
	
};

#endif
