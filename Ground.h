#pragma once
#include "StaticObject.h"
class Ground :
	public StaticObject
{
public:
	Ground();
	~Ground();
	void Drow();
	void Init();
	void LoadTextures();
};

