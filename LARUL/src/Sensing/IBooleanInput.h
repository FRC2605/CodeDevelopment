#ifndef LARUL_IBOOLEANINPUT_H
#define LARUL_IBOOLEANINPUT_H

class IBooleanInput
{
public:
	
	virtual ~IBooleanInput () {};
	
	virtual bool GetBoolean () = 0;
	
};

#endif
