
#include "StaticObject.h"
#include "Model_3DS.h"
class Tree :public StaticObject
	
{
private:
	double scale;
	Model_3DS model;

public:
	Tree(double, double, double, double);
	void Drow();
	void Init();
	void LoadTextures();
	~Tree();
};