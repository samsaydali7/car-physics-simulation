#include "RoadCut.h"


RoadCut::RoadCut(double x, double y, double z, double height, double width) :StaticObject(x,y,z,height,width)
{
	
}


RoadCut::~RoadCut()
{
}

void RoadCut::Drow()
{
	glPushMatrix();
	glTranslated(position._x(), position._y(), position._z());
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(1, 1);
	glVertex3d(position._x() + 0.5*width, 0, position._z() + 0.5*width);
	glTexCoord2d(1, 0);
	glVertex3d(position._x() + 0.5*width, 0, position._z() - 0.5*width);
	glTexCoord2d(0, 0);
	glVertex3d(position._x() - 0.5*width, 0, position._z() - 0.5*width);
	glTexCoord2d(0, 1);
	glVertex3d(position._x() - 0.5*width, 0, position._z() + 0.5*width);
	glEnd();
	glPopMatrix();
}

void RoadCut::LoadTextures()
{
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\RoadCut.bmp");
}