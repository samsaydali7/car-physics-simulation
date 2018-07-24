#pragma once
#include "StaticObject.h"
class InclinedStreet :
	public StaticObject
{
private:
	double x1, x2, z1;
	double *tet;


public:
	InclinedStreet(double x1, double x2, double x3, double *tet);
	void Drow();

	void LoadTextures();
	~InclinedStreet();
};
