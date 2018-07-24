#pragma once
#include "Object3D.h"
class StaticObject : public Object3D {
public:
	
	StaticObject();
	~StaticObject();
	StaticObject(double x, double y, double z);
	StaticObject(double x, double y, double z, double heigth, double width);
	StaticObject(double x, double y, double z, double heigth, double width, int texture);
};

