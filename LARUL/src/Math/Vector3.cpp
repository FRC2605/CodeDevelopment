#include "Vector3.h"

Vector3 :: Vector3 ( double X, double Y, double Z ):
	X ( X ),
	Y ( Y ),
	Z ( Z )
{
};

Vector3 :: ~Vector3 ()
{
};

void SetX ( double X )
{
	
	this -> X = X;
	
};

void SetY ( double Y )
{
	
	this -> Y = Y;
	
};

void SetZ ( double Z )
{
	
	this -> Z = Z;
	
};

double GetX ()
{
	
	return X;
	
};

double GetY ()
{
	
	return Y;
	
};

double GetZ ()
{
	
	return Z;
	
};
