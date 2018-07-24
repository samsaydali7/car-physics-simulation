#include "Object3D.h"



Object3D::Object3D()
{
}



Object3D::~Object3D()
{
}
Object3D::Object3D(double x, double y, double z){
	this->position = Vector3D(x, y, z);
}

Object3D::Object3D(double x, double y, double z, double heigth, double width){
	this->height = height;
	this->width = width;
	this->position = Vector3D(x,y,z);
}
Object3D::Object3D(double x, double y, double z, double heigth, double width, int texture){
	this->height = height;
	this->width = width;
	this->position = Vector3D(x, y, z);
	this->texture = texture;
}

Vector3D Object3D::_position(){
	return position;
}

Model_3DS Object3D::_model(){
	return model;
}

void Object3D::set_model(Model_3DS m){
	model = m;
}

int Object3D::_texture(){
	return this->texture;
}

void Object3D::set_textures(int texture){
	this->texture = texture;
}
