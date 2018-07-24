#include "Building.h"


Building::Building(double x, double y, double z, double scale,double angel) :StaticObject(x,y,z)
{
	this->scale = scale;
	this->angel = angel;
}

void Building::LoadTextures(){
	model.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\Models\\Tree\\Building.3ds");
    model.Materials[0].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\sand.tga");
	model.Materials[1].tex.BuildColorTexture(32, 43, 51);//window
    model.Materials[2].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood5.tga");//dark green
    model.Materials[3].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\blocks5.tga");//dark Blue
    model.Materials[4].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood4.tga");//oily ground
	model.Materials[5].tex.BuildColorTexture(0, 40, 40);

}

void Building::Drow(){
	model.Draw();
}
void Building::Init(){
	model.pos.x = this->_position()._x();
	model.pos.z = this->_position()._z();
	model.pos.y = this->_position()._y();
	model.rot.y = this->angel;
	model.scale = this->scale;
}

Building::~Building()
{
}
