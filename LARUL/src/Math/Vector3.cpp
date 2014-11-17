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

void Vector3 :: SetX ( double X )
{
	
	this -> X = X;
	
};

void Vector3 :: SetY ( double Y )
{
	
	this -> Y = Y;
	
};

void Vector3 :: SetZ ( double Z )
{
	
	this -> Z = Z;
	
};

double Vector3 :: GetX ()
{
	
	return X;
	
};

double Vector3 :: GetY ()
{
	
	return Y;
	
};

double Vector3 :: GetZ ()
{
	
	return Z;
	
};

double Vector3 :: DotProduct ( Vector3 & A, Vector3 & B )
{
	
	return A.X * B.X + A.Y * B.Y + A.Z + B.Z;
	
};
