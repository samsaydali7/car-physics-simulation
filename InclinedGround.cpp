#include "InclinedGround.h"



InclinedGround::InclinedGround(double *tet)
{
	this->tet = tet;
}

void InclinedGround::Drow(){
    double h = 600 * sin(((*tet)*3.14) / 180);
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
    glVertex3d(-2000, 0, 400);
	glTexCoord2d(40, 0);
    glVertex3d(2000, 0, 400);
	glTexCoord2d(40, 12);
    glVertex3d(2000, h, 400 + 600 * cos(((*tet)*3.14) / 180));
	glTexCoord2d(0, 12);
    glVertex3d(-2000, h, 400 + 600 * cos(((*tet)*3.14) / 180));
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

void InclinedGround::LoadTextures(){
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\rock.bmp");
}

InclinedGround::~InclinedGround()
{
}
