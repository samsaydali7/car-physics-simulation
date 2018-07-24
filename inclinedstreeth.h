#ifndef INCLINEDSTREETH_H
#define INCLINEDSTREETH_H
#include "StaticObject.h"

class inclinedStreetH : public StaticObject
{
private:
    double x1,x2,z1,z2;
    double *tet;
public:
    inclinedStreetH(double a, double b, double c, double d,double *tet);
    void Drow();

    void LoadTextures();
};

#endif // INCLINEDSTREETH_H
