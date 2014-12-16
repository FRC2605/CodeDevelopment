#ifndef LARUL_QUATERNION_H
#define LARUL_QUATERNION_H;

class Vector3;

class Quaternion
{
public:
	
	Quaternion ( double X = 0.0, double Y = 0.0, double Z = 0.0, double W = 0.0 );
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
	static void FromDirectionRotation ( Vector3 & Direction, double Rotation, Quaternion & Result );
	
	static double GetYaw ( Quaternion & A );
	static double GetPitch ( Quaternion & A );
	static double GetRoll ( Quaternion & A );
	
	double X;
	double Y;
	double Z;
	double W;
	
private:
	
};

#endif
