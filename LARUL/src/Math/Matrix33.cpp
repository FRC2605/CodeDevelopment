#include "Matrix33.h"

#include "Vector3.h"
#include "Quaternion.h"

#include <math.h>

const Matrix33 Matrix33 :: IDENTITY ();

Matrix33 :: Matrix33 ( double A, double B, double C, double D, double E, double F, double G, double H, double I )
{
	
	Elements [ 0 ][ 0 ] = A;
	Elements [ 0 ][ 1 ] = B;
	Elements [ 0 ][ 2 ] = C;
	Elements [ 1 ][ 0 ] = D;
	Elements [ 1 ][ 1 ] = E;
	Elements [ 1 ][ 2 ] = F;
	Elements [ 2 ][ 0 ] = G;
	Elements [ 2 ][ 1 ] = H;
	Elements [ 2 ][ 2 ] = I;
	
};

Matrix33 :: Matrix33 () {};

Matrix33 :: ~Matrix33 ();

void Matrix33 :: Add ( Matrix33 & A, Matrix33 & B )
{
	
	A.Elements [ 0 ] += B.Elements [ 0 ];
	A.Elements [ 1 ] += B.Elements [ 1 ];
	A.Elements [ 2 ] += B.Elements [ 2 ];
	A.Elements [ 3 ] += B.Elements [ 3 ];
	A.Elements [ 4 ] += B.Elements [ 4 ];
	A.Elements [ 5 ] += B.Elements [ 5 ];
	A.Elements [ 6 ] += B.Elements [ 6 ];
	A.Elements [ 7 ] += B.Elements [ 7 ];
	A.Elements [ 8 ] += B.Elements [ 8 ];
	
};

void Matrix33 :: Add ( Matrix33 & A, Matrix33 & B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ] = A.Elements [ 0 ] + B.Elements [ 0 ];
	Result.Elements [ 1 ] = A.Elements [ 1 ] + B.Elements [ 1 ];
	Result.Elements [ 2 ] = A.Elements [ 2 ] + B.Elements [ 2 ];
	Result.Elements [ 3 ] = A.Elements [ 3 ] + B.Elements [ 3 ];
	Result.Elements [ 4 ] = A.Elements [ 4 ] + B.Elements [ 4 ];
	Result.Elements [ 5 ] = A.Elements [ 5 ] + B.Elements [ 5 ];
	Result.Elements [ 6 ] = A.Elements [ 6 ] + B.Elements [ 6 ];
	Result.Elements [ 7 ] = A.Elements [ 7 ] + B.Elements [ 7 ];
	Result.Elements [ 8 ] = A.Elements [ 8 ] + B.Elements [ 8 ];
	
};

void Matrix33 :: Add ( Matrix33 & A, double B )
{
	
	A.Elements [ 0 ] += B;
	A.Elements [ 1 ] += B;
	A.Elements [ 2 ] += B;
	A.Elements [ 3 ] += B;
	A.Elements [ 4 ] += B;
	A.Elements [ 5 ] += B;
	A.Elements [ 6 ] += B;
	A.Elements [ 7 ] += B;
	A.Elements [ 8 ] += B;
	
};

void Matrix33 :: Add ( Matrix33 & A, double B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ] = A.Elements [ 0 ] + B;
	Result.Elements [ 1 ] = A.Elements [ 1 ] + B;
	Result.Elements [ 2 ] = A.Elements [ 2 ] + B;
	Result.Elements [ 3 ] = A.Elements [ 3 ] + B;
	Result.Elements [ 4 ] = A.Elements [ 4 ] + B;
	Result.Elements [ 5 ] = A.Elements [ 5 ] + B;
	Result.Elements [ 6 ] = A.Elements [ 6 ] + B;
	Result.Elements [ 7 ] = A.Elements [ 7 ] + B;
	Result.Elements [ 8 ] = A.Elements [ 8 ] + B;
	
};

void Matrix33 :: Subtract ( Matrix33 & A, Matrix33 & B )
{
	
	A.Elements [ 0 ] -= B.Elements [ 0 ];
	A.Elements [ 1 ] -= B.Elements [ 1 ];
	A.Elements [ 2 ] -= B.Elements [ 2 ];
	A.Elements [ 3 ] -= B.Elements [ 3 ];
	A.Elements [ 4 ] -= B.Elements [ 4 ];
	A.Elements [ 5 ] -= B.Elements [ 5 ];
	A.Elements [ 6 ] -= B.Elements [ 6 ];
	A.Elements [ 7 ] -= B.Elements [ 7 ];
	A.Elements [ 8 ] -= B.Elements [ 8 ];
	
};

void Matrix33 :: Subtract ( Matrix33 & A, Matrix33 & B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ] = A.Elements [ 0 ] - B.Elements [ 0 ];
	Result.Elements [ 1 ] = A.Elements [ 1 ] - B.Elements [ 1 ];
	Result.Elements [ 2 ] = A.Elements [ 2 ] - B.Elements [ 2 ];
	Result.Elements [ 3 ] = A.Elements [ 3 ] - B.Elements [ 3 ];
	Result.Elements [ 4 ] = A.Elements [ 4 ] - B.Elements [ 4 ];
	Result.Elements [ 5 ] = A.Elements [ 5 ] - B.Elements [ 5 ];
	Result.Elements [ 6 ] = A.Elements [ 6 ] - B.Elements [ 6 ];
	Result.Elements [ 7 ] = A.Elements [ 7 ] - B.Elements [ 7 ];
	Result.Elements [ 8 ] = A.Elements [ 8 ] - B.Elements [ 8 ];
	
};

void Matrix33 :: Subtract ( Matrix33 & A, double B )
{
	
	A.Elements [ 0 ] -= B;
	A.Elements [ 1 ] -= B;
	A.Elements [ 2 ] -= B;
	A.Elements [ 3 ] -= B;
	A.Elements [ 4 ] -= B;
	A.Elements [ 5 ] -= B;
	A.Elements [ 6 ] -= B;
	A.Elements [ 7 ] -= B;
	A.Elements [ 8 ] -= B;
	
};

void Matrix33 :: Subtract ( Matrix33 & A, double B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ] = A.Elements [ 0 ] - B;
	Result.Elements [ 1 ] = A.Elements [ 1 ] - B;
	Result.Elements [ 2 ] = A.Elements [ 2 ] - B;
	Result.Elements [ 3 ] = A.Elements [ 3 ] - B;
	Result.Elements [ 4 ] = A.Elements [ 4 ] - B;
	Result.Elements [ 5 ] = A.Elements [ 5 ] - B;
	Result.Elements [ 6 ] = A.Elements [ 6 ] - B;
	Result.Elements [ 7 ] = A.Elements [ 7 ] - B;
	Result.Elements [ 8 ] = A.Elements [ 8 ] - B;
	
};

void Matrix33 :: Multiply ( Matrix33 & A, Matrix33 & B )
{
	
	double ETemp [ 3 ][ 3 ];
	
	ETemp [ 0 ][ 0 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	ETemp [ 0 ][ 1 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	ETemp [ 0 ][ 2 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	ETemp [ 1 ][ 0 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	ETemp [ 1 ][ 1 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	ETemp [ 1 ][ 2 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	ETemp [ 2 ][ 0 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	ETemp [ 2 ][ 1 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	A.Elements [ 2 ][ 2 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	
	A.Elements [ 0 ][ 0 ] = ETemp [ 0 ] [ 0 ];
	A.Elements [ 0 ][ 1 ] = ETemp [ 0 ] [ 1 ];
	A.Elements [ 0 ][ 2 ] = ETemp [ 0 ] [ 2 ];
	A.Elements [ 1 ][ 0 ] = ETemp [ 1 ] [ 0 ];
	A.Elements [ 1 ][ 1 ] = ETemp [ 1 ] [ 1 ];
	A.Elements [ 1 ][ 2 ] = ETemp [ 1 ] [ 2 ];
	A.Elements [ 2 ][ 0 ] = ETemp [ 2 ] [ 0 ];
	A.Elements [ 2 ][ 1 ] = ETemp [ 2 ] [ 1 ];
	
};

void Matrix33 :: Multiply ( Matrix33 & A, Matrix33 & B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ][ 0 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	Result.Elements [ 0 ][ 1 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	Result.Elements [ 0 ][ 2 ] = A.Elements [ 0 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 0 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	Result.Elements [ 1 ][ 0 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	Result.Elements [ 1 ][ 1 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	Result.Elements [ 1 ][ 2 ] = A.Elements [ 1 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 1 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 1 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	Result.Elements [ 2 ][ 0 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 0 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 0 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 0 ];
	Result.Elements [ 2 ][ 1 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 1 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 1 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 1 ];
	Result.Elements [ 2 ][ 2 ] = A.Elements [ 2 ][ 0 ] * B.Elements [ 0 ][ 2 ] + A.Elements [ 2 ][ 1 ] * B.Elements [ 1 ][ 2 ] + A.Elements [ 2 ][ 2 ] * B.Elements [ 2 ][ 2 ];
	
};

void Matrix33 :: Multiply ( Matrix33 & A, double B )
{
	
	A.Elements [ 0 ] *= B;
	A.Elements [ 1 ] *= B;
	A.Elements [ 2 ] *= B;
	A.Elements [ 3 ] *= B;
	A.Elements [ 4 ] *= B;
	A.Elements [ 5 ] *= B;
	A.Elements [ 6 ] *= B;
	A.Elements [ 7 ] *= B;
	A.Elements [ 8 ] *= B;
	
};

void Matrix33 :: Multiply ( Matrix33 & A, double B, Matrix33 & Result )
{
	
	Result.Elements [ 0 ] = A.Elements [ 0 ] * B;
	Result.Elements [ 1 ] = A.Elements [ 1 ] * B;
	Result.Elements [ 2 ] = A.Elements [ 2 ] * B;
	Result.Elements [ 3 ] = A.Elements [ 3 ] * B;
	Result.Elements [ 4 ] = A.Elements [ 4 ] * B;
	Result.Elements [ 5 ] = A.Elements [ 5 ] * B;
	Result.Elements [ 6 ] = A.Elements [ 6 ] * B;
	Result.Elements [ 7 ] = A.Elements [ 7 ] * B;
	Result.Elements [ 8 ] = A.Elements [ 8 ] * B;
	
};

void Matrix33 :: Cofactor ( Matrix33 & A )
{
	
	double ETemp [ 3 ][ 3 ];
	
	ETemp [ 0 ][ 0 ] = A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	ETemp [ 0 ][ 1 ] = - A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 0 ][ 2 ] = A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 1 ] - A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 1 ][ 0 ] = - A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	ETemp [ 1 ][ 1 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 1 ][ 2 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 1 ] + A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 2 ][ 0 ] = A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 1 ];
	ETemp [ 2 ][ 1 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 0 ];
	
	A.Elements [ 2 ][ 2 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 1 ] - A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 0 ];
	
	A.Elements [ 0 ][ 0 ] = ETemp [ 0 ][ 0 ];
	A.Elements [ 0 ][ 1 ] = ETemp [ 0 ][ 1 ];
	A.Elements [ 0 ][ 2 ] = ETemp [ 0 ][ 2 ];
	A.Elements [ 1 ][ 0 ] = ETemp [ 1 ][ 0 ];
	A.Elements [ 1 ][ 1 ] = ETemp [ 1 ][ 1 ];
	A.Elements [ 1 ][ 2 ] = ETemp [ 1 ][ 2 ];
	A.Elements [ 2 ][ 0 ] = ETemp [ 2 ][ 0 ];
	A.Elements [ 2 ][ 1 ] = ETemp [ 2 ][ 1 ];
	
};

void Matrix33 :: Cofactor ( Matrix33 & A, Matrix33 & Result )
{
	
	Result.Elements [ 0 ][ 0 ] = A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	Result.Elements [ 0 ][ 1 ] = - A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 0 ][ 2 ] = A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 1 ] - A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 1 ][ 0 ] = - A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	Result.Elements [ 1 ][ 1 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 1 ][ 2 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 1 ] + A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 2 ][ 0 ] = A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 1 ];
	Result.Elements [ 2 ][ 1 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 0 ];
	Result.Elements [ 2 ][ 2 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 1 ] - A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 0 ];
	
};

void Matrix33 :: Transpose ( Matrix33 & A )
{
	
	double Temp;
	
	Temp = A.Elements [ 0 ][ 1 ];
	A.Elements [ 0 ][ 1 ] = A.Elements [ 1 ][ 0 ];
	E.Elements [ 1 ][ 0 ] = A.Elements [ 0 ][ 1 ];
	
	Temp = A.Elements [ 0 ][ 2 ];
	A.Elements [ 0 ][ 2 ] = A.Elements [ 2 ][ 0 ];
	E.Elements [ 2 ][ 0 ] = A.Elements [ 0 ][ 2 ];
	
	Temp = A.Elements [ 1 ][ 2 ];
	A.Elements [ 1 ][ 2 ] = A.Elements [ 2 ][ 1 ];
	E.Elements [ 2 ][ 1 ] = A.Elements [ 1 ][ 2 ];
	
};

void Matrix33 :: Transpose ( Matrix33 & A, Matrix33 & Result )
{
	
	Result.Elements [ 0 ][ 0 ] = A.Elements [ 0 ][ 0 ];
	Result.Elements [ 0 ][ 1 ] = A.Elements [ 1 ][ 0 ];
	Result.Elements [ 0 ][ 2 ] = A.Elements [ 2 ][ 0 ];
	Result.Elements [ 1 ][ 0 ] = A.Elements [ 0 ][ 1 ];
	Result.Elements [ 1 ][ 1 ] = A.Elements [ 1 ][ 1 ];
	Result.Elements [ 1 ][ 2 ] = A.Elements [ 2 ][ 1 ];
	Result.Elements [ 2 ][ 0 ] = A.Elements [ 0 ][ 2 ];
	Result.Elements [ 2 ][ 1 ] = A.Elements [ 1 ][ 2 ];
	Result.Elements [ 2 ][ 2 ] = A.Elements [ 2 ][ 2 ];
	
};

void Matrix33 :: Adjoint ( Matrix33 & A )
{
	
	ETemp [ 0 ][ 0 ] = A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	ETemp [ 0 ][ 1 ] = - A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 0 ][ 2 ] = A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 1 ] - A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 1 ][ 0 ] = - A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	ETemp [ 1 ][ 1 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 1 ][ 2 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 1 ] + A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	ETemp [ 2 ][ 0 ] = A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 1 ];
	ETemp [ 2 ][ 1 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 0 ];
	
	A.Elements [ 2 ][ 2 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 1 ] - A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 0 ];
	
	A.Elements [ 0 ][ 0 ] = ETemp [ 0 ][ 0 ];
	A.Elements [ 1 ][ 0 ] = ETemp [ 0 ][ 1 ];
	A.Elements [ 2 ][ 0 ] = ETemp [ 0 ][ 2 ];
	A.Elements [ 0 ][ 1 ] = ETemp [ 1 ][ 0 ];
	A.Elements [ 1 ][ 1 ] = ETemp [ 1 ][ 1 ];
	A.Elements [ 2 ][ 1 ] = ETemp [ 1 ][ 2 ];
	A.Elements [ 0 ][ 2 ] = ETemp [ 2 ][ 0 ];
	A.Elements [ 1 ][ 2 ] = ETemp [ 2 ][ 1 ];
	
};

void Matrix33 :: Adjoint ( Matrix33 & A, Matrix33 & Result )
{
	
	Result.Elements [ 0 ][ 0 ] = A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	Result.Elements [ 1 ][ 0 ] = - A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 2 ][ 0 ] = A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 1 ] - A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 0 ][ 1 ] = - A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 1 ];
	Result.Elements [ 1 ][ 1 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 2 ][ 1 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 2 ][ 1 ] + A.Elements [ 0 ][ 1 ] * A.Elements [ 2 ][ 0 ];
	Result.Elements [ 0 ][ 2 ] = A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 2 ] - A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 1 ];
	Result.Elements [ 1 ][ 2 ] = - A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 2 ] + A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 0 ];
	Result.Elements [ 2 ][ 2 ] = A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 1 ] - A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 0 ];
	
};

bool Matrix33 :: Invert ( Matrix33 & A )
{
	
	double Determinate = GetDeterminate ( A );
	
	if ( Determinate == 0.0 )
		return false;
	
	Adjoint ( A );
	Multiply ( A, 1.0 / Determinate );
	
	return true;
	
};

bool Matrix33 :: Invert ( Matrix33 & A, Matrix33 & Result )
{
	
	double Determinate = GetDeterminate ( A );
	
	if ( Determinate == 0.0 )
		return false;
	
	Adjoint ( A, Result );
	Multiply ( Result, 1.0 / Determinate );
	
	return true;
	
};

double Matrix33 :: GetDeterminate ( Matrix33 & A )
{
	
	return ( A.Elements [ 0 ][ 0 ] * A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 2 ] + A.Elements [ 1 ][ 0 ] * A.Elements [ 2 ][ 1 ] * A.Elements [ 0 ][ 2 ] + A.Elements [ 2 ][ 0 ] * A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 2 ] ) - ( A.Elements [ 0 ][ 2 ] * A.Elements [ 1 ][ 1 ] * A.Elements [ 2 ][ 0 ] + A.Elements [ 1 ][ 2 ] * A.Elements [ 2 ][ 1 ] * A.Elements [ 0 ][ 0 ] + A.Elements [ 2 ][ 2 ] * A.Elements [ 0 ][ 1 ] * A.Elements [ 1 ][ 0 ] );
	
};

void SetRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation )
{
	
	double WX, WY, WZ, XX, XY, XZ, YY, YZ, ZZ;
	
	if ( Quaternion :: GetNorm ( Rotation ) == 0.0 )
		WX = WY = WZ = XX = XY = XZ = YY = YZ = ZZ = 0.0;
	else
	{
		
		WX = 2.0 * Rotation.W * Rotation.X;
		WY = 2.0 * Rotation.W * Rotation.Y;
		WZ = 2.0 * Rotation.W * Rotation.Z;
		XX = 2.0 * Rotation.X * Rotation.X;
		XY = 2.0 * Rotation.X * Rotation.Y;
		XZ = 2.0 * Rotation.X * Rotation.Z;
		YY = 2.0 * Rotation.Y * Rotation.Y;
		YZ = 2.0 * Rotation.Y * Rotation.Z;
		ZZ = 2.0 * Rotation.Z * Rotation.Z;
		
	}
	
	A.Elements [ 0 ][ 0 ] = 1.0 - ( YY + ZZ );
	A.Elements [ 0 ][ 1 ] = XY - WZ;
	A.Elements [ 0 ][ 2 ] = XZ + WY;
	A.Elements [ 1 ][ 0 ] = XY + WZ;
	A.Elements [ 1 ][ 1 ] = 1.0 - ( XX + ZZ );
	A.Elements [ 1 ][ 2 ] = YZ - WX;
	A.Elements [ 2 ][ 0 ] = XZ - WY;
	A.Elements [ 2 ][ 1 ] = YZ + WX;
	A.Elements [ 2 ][ 2 ] = 1.0 - ( XX + YY );
	
};

void AppendRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation )
{
	
	Matrix33 Temp;
	
	SetRotationFromQuaternion ( Temp, Rotation );
	Multiply ( A, Temp );
	
};

void AppendRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation, Matrix33 & Result )
{
	
	Matrix33 Temp;
	
	SetRotationFromQuaternion ( Temp, Rotation );
	Multiply ( A, Temp, Result );
	
};

void PrependRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation )
{
	
	Matrix33 Temp = A;
	
	SetRotationFromQuaternion ( A, Rotation );
	Multiply ( A, Temp );
	
};

void PrependRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation, Matrix33 & Result )
{
	
	SetRotationFromQuaternion ( Result, Rotation );
	Multiply ( Result, A );
	
};

void SetSkew ( Matrix33 & A, Vector3 & Skew )
{
	
	A.Elements [ 0 ][ 0 ] = Skew.X;
	A.Elements [ 0 ][ 1 ] = 0.0;
	A.Elements [ 0 ][ 2 ] = 0.0;
	A.Elements [ 1 ][ 0 ] = 0.0;
	A.Elements [ 1 ][ 1 ] = Skew.Y;
	A.Elements [ 1 ][ 2 ] = 0.0;
	A.Elements [ 2 ][ 0 ] = 0.0;
	A.Elements [ 2 ][ 1 ] = 0.0;
	A.Elements [ 2 ][ 2 ] = Skew.Z;
	
};

void AppendSkew ( Matrix33 & A, Vector3 & Skew )
{
	
	Matrix33 Temp;
	
	SetSkew ( Temp, Skew );
	Multiply ( A, Temp );
	
};

void AppendSkew ( Matrix33 & A, Vector3 & Skew, Matrix33 & Result )
{
	
	Matrix33 Temp;
	
	SetSkew ( Temp, Skew );
	Multiply ( A, Temp, Result );
	
};

void PrependSkew ( Matrix33 & A, Vector3 & Skew )
{
	
	Matrix33 Temp = A;
	
	SetSkew ( A, Skew );
	Multiply ( A, Temp );
	
};

void PrependSkew ( Matrix33 & A, Vector3 & Skew, Matrix33 & Result )
{
	
	SetSkew ( Result, Skew );
	Multiply ( Result, A );
	
};


