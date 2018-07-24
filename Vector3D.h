#pragma once
class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double a, double b, double c);
	~Vector3D();
	Vector3D inverse();
	double _x();
	double _y();
	double _z();
	Vector3D operator +(Vector3D other);
	Vector3D operator *(double value);
	double  mult(Vector3D);
	double magnitude();
};


