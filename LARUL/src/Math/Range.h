#ifndef LARUL_RANGE_H
#define LARUL_RANGE_H

class Range
{
public:
	
	Range ( double Low = 0.0, double High = 0.0 );
	~Range ();
	
	void Set ( double Low = 0.0, double High = 0.0 );
	
	void Reverse ();
	void Invert ();
	
	double Low;
	double High;
	
};

#endif
