#pragma once
#include "Object3D.h"
class MotorObject : public Object3D {
protected:
	Vector3D prev_Position;
	Vector3D velocity;
	Vector3D acceleration;

	Vector3D TForce;

	double ta; //turn angle

	double a; //direction angle
	double central_acceleration;
	double angular_velocity;

	double ir; //inverse turning radious




	double inverseMass;
	double ra; //upDown angle
public:
	MotorObject();
	MotorObject(Vector3D position);
	~MotorObject();

	void virtual update(double time, double deltaTime);
	void addForce(Vector3D f);

	Vector3D _velocity();
	Vector3D _acceleration();
	Vector3D _prev_position();

	Vector3D _TForce();

	double _ra();
	double _area();
	double _Mass();

	double _ta();

	double _a();
	double _central_acceleration();
	double _angular_velocity();
	double _ir();



	void set_Mass(double);
	void set_TForce(Vector3D);
	void set_ra(double a);
	void set_prevPosition(Vector3D);

	void set_velocity(Vector3D v);
	void set_acceleration(Vector3D a);

	void set_ta(double);

	void set_a(double);
	void set_central_acceleration(double);
	void set_angular_velocity(double);
	void set_ir(double);
};

