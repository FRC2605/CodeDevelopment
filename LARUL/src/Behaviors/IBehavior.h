#ifndef LARUL_IBEHAVIOR_H
#define LARUL_IBEHAVIOR_H

class IBehavior
{
public:
	
	virtual ~IBehavior () {};
	
	virtual void Init () = 0;
	virtual void Destroy () = 0;
	
	virtual void Start () = 0;
	virtual void Stop () = 0;
	
	virtual void Update () = 0;
	
};

#endif
