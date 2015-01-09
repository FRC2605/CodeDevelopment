#ifndef LARUL_HWSYSTEM_H
#define LARUL_HWSYSTEM_H

class HWSystem
{
public:
	
	virtual ~HWSystem () {};
	
	virtual void Disable ();
	virtual void Enable ();
	
	virtual void GetEnabled ();
	
};

#endif
