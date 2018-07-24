#include "movement.h"

movement::movement()
{
    x=0;
}
bool movement::ok =true;
double movement::tet = 0;//Ground Angel
double movement::ac=0;

//physics

double movement::mass = 700, movement::ge = -9.8, movement::movingForce = 4000;

//fk fs
double movement::uk = 0.016,movement::us = 0.7;

// -kv
double movement::k = 231;

//0.5 dragEfficien area
double movement::dragEfficien = 0.5, movement::area = 2, movement::p = 1.293;

double movement::time = 0, movement::deltaTime = 0.0333,movement::ta=40;//ta dirkisune

double movement::tt = 0 , movement::cameraShift = 0,movement::cameraDistance = 0;

double movement::a = 0, movement::v = 0;

Model_3DS movement::car;

bool movement::keys[256]={false};
