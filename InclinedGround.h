#pragma once
#include "StaticObject.h"
class InclinedGround :
	public StaticObject
{
private: 
	double *tet;
public:
	InclinedGround(double*);
	void Drow();
	void LoadTextures();
	~InclinedGround();
};

