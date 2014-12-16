#include "Vector3.h"

#include "Quaternion.h"

#include <math.h>

const Vector3 Vector3 :: UP ( 0, 0, 1 );
const Vector3 Vector3 :: DOWN ( 0, 0, - 1 );
const Vector3 Vector3 :: LEFT ( 0, - 1, 0 );
const Vector3 Vector3 :: RIGHT ( 0, 1, 0 );
const Vector3 Vector3 :: FORWARD ( 1, 0, 0 );
const Vector3 Vector3 :: BACKWARD ( - 1, 0, 0 );
const Vector3 Vector3 :: IDENTITY ( 1, 1, 1 );
const Vector3 Vector3 :: ZERO ( 0, 0, 0 );

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

void Vector3 :: Multiply ( Vector3 & A, double B, Vector3 & Result )
{
	
	Result.X = A.X * B;
	Result.Y = A.Y * B;
	Result.Z = A.Z * B;
	
};

void Vector3 :: Add ( Vector3 & A, Vector3 & B, Vector3 & Result )
{
	
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	
};

void Vector3 :: Add ( Vector3 & A, Vector3 & B )
{
	
	A.X += B.X;
	A.Y += B.Y;
	A.Z += B.Z;
	
};

void Vector3 :: Subtract ( Vector3 & A, Vector3 & B, Vector3 & Result )
{
	
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	
};

void Vector3 :: Subtract ( Vector3 & A, Vector3 & B )
{
	
	A.X -= B.X;
	A.Y -= B.Y;
	A.Z -= B.Z;
	
};

void Vector3 :: Normalize ( Vector3 & A )
{
	
	Multiply ( A, 1 / Length ( A ) );
	
};

void Vector3 :: Normalize ( Vector3 & A, Vector3 & Result )
{
	
	Multiply ( A, 1 / Length ( A ), Result );
	
};

double Vector3 :: Length ( Vector3 & A )
{
	
	return sqrt ( A.X * A.X + A.Y * A.Y + A.Z * A.Z );
	
};

double Vector3 :: LengthSquared ( Vector3 & A )
{
	
	return A.X * A.X + A.Y * A.Y + A.Z * A.Z;
	
};

double Vector3 :: AngleBetween ( Vector3 & A, Vector3 & B )
{
	
	return acos ( DotProduct ( A, B ) / ( Length ( A ) * Length ( B ) ) );
	
};

void Vector3 :: Interpolate ( Vector3 & A, Vector3 & B, double Fraction )
{
	
	Vector3 Tem;
	
	Multiply ( A, Fraction );
	Multiply ( B, 1 - Fraction, Tem );
	Add ( A, Tem );
	
};

void Vector3 :: Interpolate ( Vector3 & A, Vector3 & B, double Fraction, Vector3 & Result )
{
	
	Vector3 Tem;
	
	Multiply ( Result, Fraction );
	Multiply ( B, 1 - Fraction, Tem );
	Add ( Result, Tem );
	
};

void Vector3 :: Rotate ( Vector3 & A, Quaternion & Rotation )
{
	
	Vector3 Dir ( Rotation.X, Rotation.Y, Rotation.Z );
	Vector3 ACross;
	Vector3 BCross;
	
	CrossProduct ( Temp, A, ACross );
	Multiply ( ACross, 2.0 );
	CrossProduct ( ACross, Dir, BCross );
	
	A.X += T.X * Rotation.W + BCross.X;
	A.Y += T.Y * Rotation.W + BCross.Y;
	A.Z += T.Z * Rotation.W + BCross.Z;
	
};

void Vector3 :: Rotate ( Vector3 & A, Quaternion & Rotation, Vector3 & Result )
{
	
	Vector3 Dir ( Rotation.X, Rotation.Y, Rotation.Z );
	Vector3 ACross;
	Vector3 BCross;
	
	CrossProduct ( Temp, A, ACross );
	Multiply ( ACross, 2.0 );
	CrossProduct ( ACross, Dir, BCross );
	
	Result.X = A.X + T.X * Rotation.W + BCross.X;
	Result.Y = A.Y + T.Y * Rotation.W + BCross.Y;
	Result.Z = A.Z + T.Z * Rotation.W + BCross.Z;
	
};

