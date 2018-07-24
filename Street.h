#pragma once
#include "StaticObject.h"
class Street :
	public StaticObject
{
private:
	double x1, x2,z1,z2;

	
public:
	Street(double, double, double, double);
	void Drow();

	void LoadTextures();
	~Street();
};

