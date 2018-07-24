#include "Vector3D.h"
#include <math.h>


Vector3D::Vector3D(){
	x = 0;
	y = 0;
	z = 0;
}

Vector3D::Vector3D(double a, double b, double c){
	x = a;
	y = b;
	z = c;
}

Vector3D::~Vector3D()
{
}

Vector3D Vector3D::inverse(){
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

double Vector3D::_x(){
	return x;
}
double Vector3D::_y(){
	return y;
}
double Vector3D::_z(){
	return z;
}
Vector3D Vector3D::operator +(Vector3D other){
	x = x + other.x;
	y = y + other.y;
	z = z + other.z;
	return *this;
}
Vector3D Vector3D::operator *(double value){
	Vector3D temp;
	temp.x = x * value;
	temp.y = y * value;
	temp.z = z * value;
	return temp;
}
double Vector3D::mult(Vector3D a)
{
	double b;
	b = x*a.x + y*a.y + z*a.z;
	return b;
}
double Vector3D::magnitude(){
	return sqrt(x*x + y*y + z*z);
}
