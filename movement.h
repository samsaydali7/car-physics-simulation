#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "Model_3DS.h"

class movement
{
public:
    movement();
    double x;
    static bool ok;

    static double tet;

    //physics

    static double mass, ge, movingForce;

    //fk fs
    static double uk,us;

    // -kv
    static double k;

    //0.5 dragEfficien area
    static double dragEfficien, area, p;

    static double time, deltaTime,ac,ta;//ta dirkisune


    static double a, v;


    //util
    static double tt, cameraShift,cameraDistance;

    static Model_3DS car;
    static bool	keys[256];

};

#endif // MOVEMENT_H
