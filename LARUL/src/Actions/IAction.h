#ifndef LARUL_IACTION_H
#define LARUL_IACTION_H

class IAction
{
public:
	
	virtual ~IAction () {};
	
	virtual void Reset () = 0;
	
	virtual void Start () = 0;
	virtual bool IsComplete () = 0;
	virtual void Stop () = 0;
	
	virtual void Update () = 0;
	
};


#endif
