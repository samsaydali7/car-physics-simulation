#include "Skybox.h"


Skybox::Skybox()
{
}

void Skybox::Drow(){
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBegin(GL_QUADS);


	//front
	glTexCoord2d(0.25, 0.33);
	glVertex3d(-1, -1, -1);
	glTexCoord2d(0.25, 0.66);
	glVertex3d(-1, 1, -1);
	glTexCoord2d(0.5, 0.66);
	glVertex3d(1, 1, -1);
	glTexCoord2d(0.5, 0.33);
	glVertex3d(1, -1, -1);

	//right
	glTexCoord2d(0.5, 0.33);
	glVertex3d(1, -1, -1);
	glTexCoord2d(0.5, 0.66);
	glVertex3d(1, 1, -1);
	glTexCoord2d(0.75, 0.66);
	glVertex3d(1, 1, 1);
	glTexCoord2d(0.75, 0.33);
	glVertex3d(1, -1, 1);

	//back
	glTexCoord2d(0.75, 0.33);
	glVertex3d(1, -1, 1);
	glTexCoord2d(0.75, 0.66);
	glVertex3d(1, 1, 1);
	glTexCoord2d(1, 0.66);
	glVertex3d(-1, 1, 1);
	glTexCoord2d(1, 0.33);
	glVertex3d(-1, -1, 1);

	//left
	glTexCoord2d(0, 0.33);
	glVertex3d(-1, -1, 1);
	glTexCoord2d(0, 0.66);
	glVertex3d(-1, 1, 1);
	glTexCoord2d(0.25, 0.66);
	glVertex3d(-1, 1, -1);
	glTexCoord2d(0.25, 0.33);
	glVertex3d(-1, -1, -1);

	//up
	glTexCoord2d(0.25, 0.66);
	glVertex3d(-1, 1, -1);
	glTexCoord2d(0.25, 1);
	glVertex3d(-1, 1, 1);
	glTexCoord2d(0.5, 1);
	glVertex3d(1, 1, 1);
	glTexCoord2d(0.5, 0.66);
	glVertex3d(1, 1, -1);

	//down
	glTexCoord2d(0.25, 0);
	glVertex3d(-1, -1, 1);
	glTexCoord2d(0.25, 0.33);
	glVertex3d(-1, -1, 1);
	glTexCoord2d(0.5, 0.33);
	glVertex3d(1, -1, 1);
	glTexCoord2d(0.5, 0);
	glVertex3d(1, -1, -1);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
}
void Skybox::LoadTextures(){
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\skybox5.bmp");

}


Skybox::~Skybox(){

}
