#ifndef LARUL_DSPFILTER_H
#define LARUL_DSPFILTER_H

/* DSPFilter_x_x: A digital signal processing filter. These are x-in x-out filters for arbitrary use.
* The first number in the name denotes the quantity of inputs, and the second of outputs.
*
* These are only abstract classes for ease of plug-and-play use.
*
* Compute: The actual work of the filter is done here. Data is fed in a stream to this function.
*
* Read(A/B): The output of the filter. Typically this is called once each after compute, although
*	it is not atypical to have read called more than once, so it is advised to do calculation in Compute
*	and just store the value for subsequent reading.
*
* Reset: Resets the filter to a defined initial state. Again, entirely up to you.
*/

class DSPFilter_1_1
{
public:	
	
	virtual void Compute ( double Feed ) = 0;
	virtual double Read () = 0;
	
	virtual void Reset () = 0;
	
	virtual ~DSPFilter_1_1 () {};
	
};

class DSPFilter_2_1
{
public:	
	
	virtual void Compute ( double FeedA, double FeedB ) = 0;
	virtual double Read () = 0;
	
	virtual void Reset () = 0;
	
	virtual ~DSPFilter_2_1 () {};
	
};

class DSPFilter_1_2
{
public:	
	
	virtual void Compute ( double Feed ) = 0;
	virtual double ReadA () = 0;
	virtual double ReadB () = 0;
	
	virtual void Reset () = 0;
	
	virtual ~DSPFilter_1_2 () {};
	
};

class DSPFilter_2_2
{
public:	
	
	virtual void Compute ( double FeedA, double FeedB ) = 0;
	virtual double ReadA () = 0;
	virtual double ReadB () = 0;
	
	virtual void Reset () = 0;
	
	virtual ~DSPFilter_2_2 () {};
	
};

#endif
