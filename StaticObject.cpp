#include "StaticObject.h"


StaticObject::StaticObject() : Object3D()
{
}


StaticObject::~StaticObject()
{
}
StaticObject::StaticObject(double x, double y, double z) :Object3D(x, y, z){

}
StaticObject::StaticObject(double x, double y, double z, double heigth, double width) :Object3D(x, y, z, heigth, width){

}
StaticObject::StaticObject(double x, double y, double z, double heigth, double width, int texture) : Object3D(x, y, z, heigth, width,texture){

}