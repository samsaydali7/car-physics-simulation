#include "Building2.h"


Building2::Building2(double x, double y, double z, double scale, double angel) :StaticObject(x, y, z)
{

	this->scale = scale;
	this->angel = angel;
}

void Building2::LoadTextures(){
	model.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\Models\\House.3ds");
	model.Materials[0].tex.BuildColorTexture(12, 12, 12);//outer window
    model.Materials[1].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood5.tga");//dark green
	model.Materials[2].tex.BuildColorTexture(35, 35, 35);// ?
    model.Materials[3].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood5.tga");//dark green
    model.Materials[4].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\steel1.tga");//dark Blue
    model.Materials[8].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood9.tga");//dark Blue
	model.Materials[7].tex.BuildColorTexture(204, 193, 179);// windows
    model.Materials[9].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood5.tga");//dark green
    model.Materials[10].tex.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\wood9.tga");//dark Blue
}

void Building2::Drow(){
	model.Draw();

}
void Building2::Init(){

	model.pos.x = this->_position()._x();
	model.pos.z = this->_position()._z();
	model.pos.y = this->_position()._y();
	model.rot.y = this->angel;
	model.scale = this->scale;
}

Building2::~Building2()
{
}
