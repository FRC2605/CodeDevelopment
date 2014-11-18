#include "Vector3.h"

Vector3 :: UP = Vector3 ( 0, 0, 1 );
Vector3 :: DOWN = Vector3 ( 0, 0, - 1 );
Vector3 :: LEFT = Vector3 ( 0, - 1, 0 );
Vector3 :: RIGHT = Vector3 ( 0, 1, 0 );
Vector3 :: FORWARD = Vector3 ( 1, 0, 0 );
Vector3 :: BACKWARD = Vector3 ( - 1, 0, 0 );
Vector3 :: IDENTITY = Vector3 ( 1, 1, 1 );
Vector3 :: ZERO = Vector3 ( 0, 0, 0 );

Vector3 :: Vector3 ( double X, double Y, double Z ):
	X ( X ),
	Y ( Y ),
	Z ( Z )
{
};

Vector3 :: ~Vector3 ()
{
};

double Vector3 :: DotProduct ( Vector3 & A, Vector3 & B )
{
	
	return A.X * B.X + A.Y * B.Y + A.Z + B.Z;
	
};

void Vector3 :: CrossProduct ( Vector3 & A, Vector3 & B, Vector3 & Result )
{
	
	Result.X = A.Y * B.Z - A.Z * B.Y;
	Result.Y = A.Z * B.X - A.X * B.Z;
	Result.Z = A.X * B.Y - A.Y * B.X;
	
};

void Vector3 :: CrossProduct ( Vector3 & A, Vector3 & B )
{
	
	float X = A.Y * B.Z - A.Z * B.Y;
	float Y = A.Z * B.X - A.X * B.Z;
	A.Z = A.X * B.Y - A.Y * B.X;
	A.X = X;
	A.Y = Y;
	
};

void Vector3 :: Multiply ( Vector3 & A, double B )
{
	
	A.X *= B;
	A.Y *= B;
	A.Z *= B;
	
};

void Multiply ( Vector3 & A, double B, Vector3 & Result )
{
	
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	
};

void Add ( Vector3 & A, Vector3 & B, Vector3 & Result )
{
	
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	
};

void Add ( Vector3 & A, Vector3 & B )
{
	
	A.X += B.X;
	A.Y += B.Y;
	A.Z += B.Z;
	
};

void Subtract ( Vector3 & A, Vector3 & B, Vector3 & Result )
{
	
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	
};

void Subtract ( Vector3 & A, Vector3 & B )
{
	
	A.X -= B.X;
	A.Y -= B.Y;
	A.Z -= B.Z;
	
};

void Normalize ( Vector3 & A )
{
	
	Multiply ( A, 1 / Length ( A ) );
	
};

void Normalize ( Vector3 & A, Vector3 & Result )
{
	
	Multiply ( A, 1 / Length ( A ), Result );
	
};

double Length ( Vector3 & A )
{
	
	return sqrt ( A.X * A.X + A.Y * A.Y + A.Z * A.Z );
	
};

double LengthSquared ( Vector3 & A )
{
	
	return A.X * A.X + A.Y * A.Y + A.Z * A.Z;
	
};

double AngleBetween ( Vector3 & A, Vector3 & B )
{
	
	return acos ( DotProduct ( A, B ) / ( Length ( A ) * Length ( B ) ) );
	
};
