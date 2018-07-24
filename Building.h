#pragma once
#include "StaticObject.h"

class Building :
	public StaticObject
{
private:
	double scale;
	double angel;
	Model_3DS model;

public:
	Building(double,double,double,double,double);
	void Drow();
	void Init();
	void LoadTextures();
	~Building();
};

