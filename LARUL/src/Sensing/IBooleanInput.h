#ifndef LARUL_IBOOLEANINPUT_H
#define LARUL_IBOOLEANINPUT_H

#include "../CPP/Virtual.h"

class IBooleanInput
{
public:
	
	VIRTUAL_CLASS ( IBooleanInput );
	
	virtual bool GetBoolean () = 0;
	
};

#endif
