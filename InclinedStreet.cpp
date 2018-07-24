#include "InclinedStreet.h"


InclinedStreet::InclinedStreet(double x1, double x2, double z1, double *tet){
	this->x1 = x1;
	this->x2 = x2;
	this->z1 = z1;
	this->tet = tet;
}
void InclinedStreet::LoadTextures(){
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\street.bmp");
}

void InclinedStreet::Drow(){
	glPushMatrix();
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	int repeat = (z1 + (1000 - z1) * cos(((*tet)*3.14) / 180) - z1) / 10;

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
    glVertex3d(x1, 0 + 0.06, z1);
	glTexCoord2d(1, 0);
    glVertex3d(x2, 0 + 0.06, z1);
	glTexCoord2d(1, repeat);
    glVertex3d(x2, (1000 - z1) * sin(((*tet)*3.14) / 180) + 0.06, z1 + (1000 - z1) * cos(((*tet)*3.14) / 180));
	glTexCoord2d(0, repeat);
    glVertex3d(x1, (1000 - z1) * sin(((*tet)*3.14) / 180) + 0.06, z1 + (1000 - z1) * cos(((*tet)*3.14) / 180));

	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

InclinedStreet::~InclinedStreet()
{
	
}
