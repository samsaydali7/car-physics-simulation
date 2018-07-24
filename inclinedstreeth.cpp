#include "inclinedstreeth.h"

inclinedStreetH::inclinedStreetH(double a, double b, double c, double d,double* tet)
{
    x1=a;
    x2=b;
    z1=c;
    z2=d;
    this->tet = tet;
}
void inclinedStreetH::LoadTextures(){
    texture = LoadTexture("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\textures\\street.bmp");
}
void inclinedStreetH::Drow(){
    double h1=(z1-400) * sin(((*tet)*3.14) / 180), h2 = (z2-400) * sin(((*tet)*3.14) / 180);

    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    int repeat = (x2 - x1) / 10;
    //cos(((*tet)*3.14) / 180)
    glBegin(GL_QUADS);
    glTexCoord2d(0, 0);
    glVertex3d(x2, h2 + 0.08, 400+(z2-400)*cos(((*tet)*3.14) / 180));
    glTexCoord2d(1, 0);
    glVertex3d(x2, h1 + 0.08, 400+(z1-400)*cos(((*tet)*3.14) / 180));
    glTexCoord2d(1, repeat);
    glVertex3d(x1,  h1+ 0.08, 400+(z1-400)*cos(((*tet)*3.14) / 180));
    glTexCoord2d(0, repeat);
    glVertex3d(x1, h2 + 0.08, 400+(z2-400)*cos(((*tet)*3.14) / 180));

    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
}
