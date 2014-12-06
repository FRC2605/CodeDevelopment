#ifndef LARUL_IEVENT_H
#define LARUL_IEVENT_H

class IEvent
{
public:
	
	 virtual ~IEvent () = 0;
	
	virtual void Trigger () = 0;
	virtual const char * GetType () = 0;
	
};

#endif
