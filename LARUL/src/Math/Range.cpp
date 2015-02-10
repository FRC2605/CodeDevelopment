#include "Range.h"

Range :: Range ( double Low, double High ):
	Low ( Low ),
	High ( High )
{
};

Range :: ~Range ()
{
};

void Range :: Set ( double Low, double High )
{
	
	this -> High = High;
	this -> Low = Low;
	
};

void Range :: Reverse ()
{
	
	double Temp = Low;
	Low = High;
	High = Temp;
	
};

void Range :: Invert ()
{
	
	Low = - Low;
	High = - High;
	
};
