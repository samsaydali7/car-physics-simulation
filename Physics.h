#include "Vector3D.h"
#pragma once
class Physics
{
private:
	double g;
	double movingForce;
	double uk, us, usmax;
	double k, dragEfficien, p;

	double teta;

	Vector3D TForce;
	double mass;
	double acceleration;
public:
	Physics();
	~Physics();
	//Functions
	void updatePhysics();
	double _g();
	double _movingForce();
	double _uk();
	double _us();
	double _usmax();
	double _k();
	double _dragEfficien();
	double _p();
	double _tet();
	double _mass();
	double _acceleration();
	void set_k(double);
	void set_dragEfficien(double);
	void set_p(double);
	void set_g(double);
	void set_movingForce(double);
	void set_uk(double);
	void set_us(double);
	void set_usmax(double);
	void set_tet(double);
	void set_mass(double);
	void set_acceleration(double);
};

