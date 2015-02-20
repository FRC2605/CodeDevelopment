#ifndef LARUL_IBOOLEANINDICATOR_H
#define LARUL_IBOOLEANINDICATOR_H

class IBooleanIndicator
{
public:
	
	virtual ~IBooleanIndicator () {};
	
	virtual void Set ( bool Indication ) = 0;
	
};


#endif
