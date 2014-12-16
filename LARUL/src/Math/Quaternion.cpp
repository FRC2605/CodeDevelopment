#include "Quaternion.h"

#include "Vector3.h"

#include <math.h>

Quaternion :: Quaternion ( double X = 0.0, double Y = 0.0, double Z = 0.0, double W = 0.0 ):
	X ( X ),
	Y ( Y ),
	Z ( Z ),
	W ( W )
{
};

Quaternion :: ~Quaternion ()
{
};

void Quaternion :: Add ( Quaternion & A, Quaternion & B )
{
	
	A.X += B.X;
	A.Y += B.Y;
	A.Z += B.Z;
	A.W += B.W;
	
};

void Quaternion :: Add ( Quaternion & A, Quaternion & B, Quaternion & Result )
{
	
	Result.X = A.X + B.X;
	Result.Y = A.Y + B.Y;
	Result.Z = A.Z + B.Z;
	Result.W = A.W + B.W;
	
};

void Quaternion :: Subtract ( Quaternion & A, Quaternion & B )
{
	
	A.X -= B.X;
	A.Y -= B.Y;
	A.Z -= B.Z;
	A.W -= B.W;
	
};

void Quaternion :: Subtract ( Quaternion & A, Quaternion & B, Quaternion & Result );
{
	
	Result.X = A.X - B.X;
	Result.Y = A.Y - B.Y;
	Result.Z = A.Z - B.Z;
	Result.W = A.W - B.W;
	
	NormalizeV3 ( A.X, A.Y, A.Z );
	
};

void Quaternion :: Multiply ( Quaternion & A, double Scalar )
{
	
	A.X *= Scalar;
	A.Y *= Scalar;
	A.Z *= Scalar;
	
};

void Quaternion :: Multiply ( Quaternion & A, double Scalar, Quaternion & Result )
{
	
	Result.X = A.X * Scalar;
	Result.Y = A.Y * Scalar;
	Result.Z = A.Z * Scalar;
	Result.W = A.W;
	
};

void Quaternion :: Multiply ( Quaternion & A, Quaternion & B )
{
	
	double X;
	double Y;
	double Z;
	
	X = A.W * B.X + B.W * A.X + A.Y * B.Z - A.Z * B.Y;
	Y = A.W * B.Y + B.W * A.Y + A.Z * B.X - A.X * B.Z;
	Z = A.W * B.Z + B.W * A.Z + A.X * B.Y - A.Y * B.X;
	
	A.W = A.W * B.W - A.X * B.X - A.Y * B.Y - A.Z * B.Z;
	
	A.X = X;
	A.Y = Y;
	A.Z = Z;
	
};

void Quaternion :: Multiply ( Quaternion & A, Quaternion & B, Quaternion & Result )
{
	
	Result.X = A.W * B.X + B.W * A.X + A.Y * B.Z - A.Z * B.Y;
	Result.Y = A.W * B.Y + B.W * A.Y + A.Z * B.X - A.X * B.Z;
	Result.Z = A.W * B.Z + B.W * A.Z + A.X * B.Y - A.Y * B.X;
	Result.W = A.W * B.W - A.X * B.X - A.Y * B.Y - A.Z * B.Z;
	
};

void Quaternion :: Conjugate ( Quaternion & A )
{
	
	A.X = - A.X;
	A.Y = - A.Y;
	A.Z = - A.Z;
	
};

void Quaternion :: Conjugate ( Quaternion & A, Quaternion & Result )
{
	
	Result.X = - A.X;
	Result.Y = - A.X;
	Result.Z = - A.X;
	Result.W = A.W;
	
};

void Quaternion :: InterpolateSLERP ( Quaternion & A, Quaternion & B, double Fraction )
{
	
	double Theta = acos ( A.X * B.X + A.Y + B.Y + A.Z * B.Z + A.W + B.W );
	
	if ( Theta < 0.0 )
		Theta = - Theta;
	
	double ST = sin ( Theta );
	double SU = sin ( Fraction * Theta ) / ST;
	double SO = sin ( ( 1 - Fraction ) * Theta ) / ST;
	
	A.X = A.X * SO + B.X * SU;
	A.Y = A.Y * SO + B.Y * SU;
	A.Z = A.Z * SO + B.Z * SU;
	A.W = A.W * SO + B.W * SU;
	
};

void Quaternion :: InterpolateSLERP ( Quaternion & A, Quaternion & B, double Fraction, Quaternion & Result )
{
	
	double Theta = acos ( A.X * B.X + A.Y + B.Y + A.Z * B.Z + A.W + B.W );
	
	if ( Theta < 0.0 )
		Theta = - Theta;
	
	double ST = sin ( Theta );
	double SU = sin ( Fraction * Theta ) / ST;
	double SO = sin ( ( 1 - Fraction ) * Theta ) / ST;
	
	Result.X = A.X * SO + B.X * SU;
	Result.Y = A.Y * SO + B.Y * SU;
	Result.Z = A.Z * SO + B.Z * SU;
	Result.W = A.W * SO + B.W * SU;
	
};

void Quaternion :: FromYPR ( double Yaw, double Pitch, double Roll, Quaternion & Result )
{
	
	double YCos = cos ( Yaw / 2 );
	double YSin = sin ( Yaw / 2 );
	double PCos = cos ( Pitch / 2 );
	double PSin = sin ( Pitch / 2 );
	double RCos = cos ( Roll / 2 );
	double RSin = sin ( Roll / 2 );
	
	A.W = RCos * PCos * YCos + RSin * PSin * YSin;
	A.X = RSin * PCos * YCos - RCos * PSin * YSin;
	A.Y = RCos * PSin * YCos + RSin * PCos * YSin;
	A.Z = RCos * PCos * YSin - RSin * PSin * YCos;
	
};

void Quaternion :: FromAxisAngle ( Vector3 & Axis, double Angle, Quaternion & Result );
{
	
	double RSin = sin ( Angle / 2 );
	
	A.W = cos ( Angle / 2 );
	A.X = RSin * cos ( Axis.X );
	A.Y = RSin * cos ( Axis.Y );
	A.Z = RSin * cos ( Axis.Z );
	
};

void Quaternion :: Normalise ( Quaternion & A )
{
	
	Multiply ( A, 1.0 / GetNorm ( A ) );
	
};

double Quaternion :: GetNorm ( Quaternion & A )
{
	
	return sqrt ( A.X * A.X + A.Y * A.Y + A.Z * A.Z + A.W * A.W );
	
};

double Quaternion :: GetYaw ( Quaternion & A )
{
	
	return atan2 ( 2.0 * ( A.W * A.Z + A.X * A.Y ), 1.0 - 2.0 * ( A.Y * A.Y + A.Z * A.Z ) );
	
};

double Quaternion :: GetPitch ( Quaternion & A )
{
	
	return asin ( 2.0 * ( A.W * A.Y - A.X * A.Z ) );
	
};

double Quaternion :: GetRoll ( Quaternion & A )
{
	
	return atan2 ( 2.0 * ( A.W * A.X + A.Y * A.Z ), 1.0 - 2.0 * ( A.X * A.X + A.Y * A.Y ) );
	
};

void Quaternion :: GetAxis ( Quaternion & A, Vector3 & Result )
{
	
	double Div = sqrt ( 1.0 - A.W * A.W );
	
	Result.X = A.X / Div;
	Result.Y = A.Y / Div;
	Result.Z = A.Z / Div;
	
};

double Quaternion :: GetAngle ( Quaternion & A )
{
	
	return 2.0 * acos ( A.W );
	
};
