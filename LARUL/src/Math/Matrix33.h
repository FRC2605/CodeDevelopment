#ifndef LARUL_MATRIX33_H
#define LARUL_MATRIX33_H

class Quaternion;
class Vector3;

class Matrix33
{
public:
	
	explicit Matrix33 ( double A, double B = 0, double C = 0, double D = 0, double E = 1, double F = 0, double G = 0, double H = 0, double I = 1 );
	Matrix33 ();
	~Matrix33 ();
	
	static void Identity ( Matrix33 & Result );

	static void Add ( Matrix33 & A, Matrix33 & B );
	static void Add ( Matrix33 & A, Matrix33 & B, Matrix33 & Result );
	static void Add ( Matrix33 & A, double B );
	static void Add ( Matrix33 & A, double B, Matrix33 & Result );
	static void Subtract ( Matrix33 & A, Matrix33 & B );
	static void Subtract ( Matrix33 & A, Matrix33 & B, Matrix33 & Result );
	static void Subtract ( Matrix33 & A, double B );
	static void Subtract ( Matrix33 & A, double B, Matrix33 & Result );
	
	static void Multiply ( Matrix33 & A, Matrix33 & B );
	static void Multiply ( Matrix33 & A, Matrix33 & B, Matrix33 & Result );
	static void Multiply ( Matrix33 & A, double B );
	static void Multiply ( Matrix33 & A, double B, Matrix33 & Result );
	
	static void Cofactor ( Matrix33 & A );
	static void Cofactor ( Matrix33 & A, Matrix33 & Result );
	
	static void Transpose ( Matrix33 & A );
	static void Transpose ( Matrix33 & A, Matrix33 & Result );
	
	static void Adjoint ( Matrix33 & A );
	static void Adjoint ( Matrix33 & A, Matrix33 & Result );
	
	static bool Invert ( Matrix33 & A );
	static bool Invert ( Matrix33 & A, Matrix33 & Result );
	
	static double GetDeterminate ( Matrix33 & A );
	
	static void SetRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation );
	
	static void AppendRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation );
	static void AppendRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation, Matrix33 & Result );
	static void PrependRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation );
	static void PrependRotationFromQuaternion ( Matrix33 & A, Quaternion & Rotation, Matrix33 & Result );
	
	static void SetSkew ( Matrix33 & A, Vector3 & Skew );
	
	static void AppendSkew ( Matrix33 & A, Vector3 & Skew );
	static void AppendSkew ( Matrix33 & A, Vector3 & Skew, Matrix33 & Result );
	static void PrependSkew ( Matrix33 & A, Vector3 & Skew );
	static void PrependSkew ( Matrix33 & A, Vector3 & Skew, Matrix33 & Result );
	
	double Elements [ 3 ][ 3 ];
	
	const static Matrix33 IDENTITY;
	
};

#endif
