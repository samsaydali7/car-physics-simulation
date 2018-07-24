#pragma once
#include "StaticObject.h"
class Skybox :
	public StaticObject
{


public:
	
	Skybox();
	~Skybox();
	void Drow();

	void LoadTextures();
};

