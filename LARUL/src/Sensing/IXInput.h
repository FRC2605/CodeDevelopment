#ifndef LARUL_IXINPUT_H
#define LARUL_IXINPUT_H

class IXInput
{
public:
	
	virtual ~IXInput () {};
	
	virtual double GetX () = 0;
	
	virtual double GetScale () = 0;
	
};

#endif
