#pragma once
#include "StaticObject.h"
class RoadCut :
	public StaticObject
{
public:
	RoadCut(double, double, double, double, double);
	~RoadCut();
	void Drow();
	void LoadTextures();
};

