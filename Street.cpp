#include "Street.h"


Street::Street(double a, double b , double c, double d)
{
	x1 = a;
	x2 = b;
	z1 = c;
	z2 = d;
}
void Street::Drow()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	int repeat = (z2 - z1) / 10;

	glBegin(GL_QUADS);
	glTexCoord2d(0, 0);
    glVertex3d(x1, 0.06, z1);
	glTexCoord2d(1, 0);
    glVertex3d(x2, 0.06, z1);
	glTexCoord2d(1, repeat);
    glVertex3d(x2, 0.06, z2);
	glTexCoord2d(0, repeat);
    glVertex3d(x1, 0.06, z2);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void Street::LoadTextures()
{
	texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\street.bmp");
}

Street::~Street()
{
}
