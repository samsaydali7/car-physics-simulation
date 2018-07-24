#include "Tree.h"


Tree::Tree(double x, double y, double z, double scale) :StaticObject(x, y, z)
{
	this->scale = scale;

}

void Tree::LoadTextures(){
    model.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\Models\\Tree2.3ds");
    model.Materials[1].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\TreeR3.tga");//leaves
    model.Materials[0].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood9.tga");
}

void Tree::Drow(){
	model.Draw();
}
void Tree::Init(){
	model.pos.x = this->_position()._x();
	model.pos.z = this->_position()._z();
	model.pos.y = this->_position()._y();

	model.scale = this->scale;
}

Tree::~Tree()
{
}
