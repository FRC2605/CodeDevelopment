#ifndef LARUL_VEC3_H
#define LARUL_VEC3_H

class Vector3
{
public:
	
	Vector3 ( double X = 0.0, double Y = 0.0, double Z = 0.0 );
	~Vector3 ();
	
	void SetX ( double X );
	void SetY ( double Y );
	void SetZ ( double Z );
	
	double GetX ();
	double GetY ();
	double GetZ ();
	
private:
	
	double X;
	double Y;
	double Z;
	
};

#endif
