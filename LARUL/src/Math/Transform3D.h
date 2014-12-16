#ifndef LARUL_TRANSFORM3D_H
#define LARUL_TRANSFORM3D_H

class Vector3;
class Quaternion;
class Matrix33;

class Transform3D
{
public:
	
	Transform3D ();
	~Transform3D ();
	
	
	
	Matrix33 Rotation;
	Vector3 Translation;
	
};

#endif
