#ifndef LARUL_IEVENT_H
#define LARUL_IEVENT_H

class IEvent
{
public:
	
	~IEvent () {};
	
	void Trigger () = 0;
	const char * GetType () = 0;
	
};

#endif
