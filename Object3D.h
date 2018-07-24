#pragma once
#include "Vector3D.h"
#include <windows.h>		// Header File For Windows
#include <gl.h>			// Header File For The OpenGL32 Library
#include <glu.h>			// Header File For The GLu32 Library
#include <glaux.h>		// Header File For The Glaux Library
#include <cmath>
#include<fstream>
#include<texture.h>
#include <Model_3DS.h>

using namespace std;
class Object3D
{
protected:
	double height, width;
	Vector3D position;
	int texture;
    Model_3DS model;
public:
	void virtual Drow(){
		return;
	};
	void virtual Init(){
		return;
	};
	void virtual LoadTextures(){
		return;
	}

	double _height();
	double _width();
	Vector3D _position();
	int _texture();
    Model_3DS _model();

	void set_height(double);
	void set_width(double);
	void set_position(Vector3D);
	void set_textures(int);
    void set_model(Model_3DS);
	Object3D();
	Object3D(double, double, double);
	Object3D(double, double, double, double, double);
	Object3D(double, double, double, double, double,int);
	~Object3D();
};

