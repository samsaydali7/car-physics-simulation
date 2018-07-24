#pragma once
#include "StaticObject.h"
#include "Model_3DS.h"

class Building2 :
	public StaticObject
{
private:
	double scale;
	double angel;
	Model_3DS model;


public:
	Building2(double, double, double, double, double);
	void Drow();
	void Init();
	void LoadTextures();
	~Building2();
};