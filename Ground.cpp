#include "Ground.h"
#include<texture.h>


Ground::Ground()
{
}


Ground::~Ground()
{
}

void Ground::Drow(){

	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
	glVertex3d(-2000, 0, -2000);
	glTexCoord2d(80, 0);
	glVertex3d(2000, 0, -2000);
	glTexCoord2d(80, 24);
	glVertex3d(2000, 0, 400);
	glTexCoord2d(0, 24);
	glVertex3d(-2000, 0, 400);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void Ground::Init(){
	
}
void Ground::LoadTextures(){
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\grass.bmp");
}

