#ifndef LARUL_QUATERNION_H
#define LARUL_QUATERNION_H

class Vector3;

class Quaternion
{
public:
	
	explicit Quaternion ( double X = 0.0, double Y = 0.0, double Z = 0.0, double W = 0.0 );
	~Quaternion ();
	
	static void Add ( Quaternion & A, Quaternion & B );
	static void Add ( Quaternion & A, Quaternion & B, Quaternion & Result );
	static void Subtract ( Quaternion & A, Quaternion & B );
	static void Subtract ( Quaternion & A, Quaternion & B, Quaternion & Result );
	
	static void Multiply ( Quaternion & A, double Scalar );
	static void Multiply ( Quaternion & A, double Scalar, Quaternion & Result );
	static void Multiply ( Quaternion & A, Quaternion & B );
	static void Multiply ( Quaternion & A, Quaternion & B, Quaternion & Result );
	
	static void Conjugate ( Quaternion & A );
	static void Conjugate ( Quaternion & A, Quaternion & Result );
	
	static void InterpolateSLERP ( Quaternion & A, Quaternion & B, double Fraction );
	static void InterpolateSLERP ( Quaternion & A, Quaternion & B, double Fraction, Quaternion & Result );
	
	static void FromYPR ( double Yaw, double Pitch, double Roll, Quaternion & Result );
	static void FromAxisAngle ( Vector3 & Axis, double Angle, Quaternion & Result );
	
	static void Normalise ( Quaternion & A );
	
	static double GetNorm ( Quaternion & A );
	
	static double GetYaw ( Quaternion & A );
	static double GetPitch ( Quaternion & A );
	static double GetRoll ( Quaternion & A );
	
	static void GetAxis ( Quaternion & A, Vector3 & Result );
	static double GetAngle ( Quaternion & A );

	double X;
	double Y;
	double Z;
	double W;
	
};

#endif
