#ifndef OGLWIDGET_H
#define OGLWIDGET_H

#include <QWidget>
#include <QOpenGLWidget>
#include<GL/GLU.h>
#include<GL/GL.h>
#include "glut.h"
#include "movement.h"
#include "Ground.h"
#include "Model_3DS.h"
#include "Skybox.h"
#include "Street.h"
#include "RoadCut.h"
#include "InclinedStreet.h"
#include "InclinedGround.h"
#include "Building.h"
#include "Tree.h"
#include "Building2.h"
#include  <QThread>
#include "mainwindow.h"
#include"mythread.h"
#include "inclinedstreeth.h"
class OGLWidget : public QOpenGLWidget
{
public:
    OGLWidget(QWidget *parent = 0);
    ~OGLWidget();
        movement m;
        MainWindow *mw;
        myThread *mt;
private:

        Ground g;
        Skybox s;
        Street* streets[8];
        Street* Streets2[16];
        Street t=Street(0, 40, -1980, 1980);
        RoadCut* roadCuts[14][8];
        RoadCut*roadcuts1[14];
        Tree* Tree1[15];
        Tree* Tree2[15];
        Tree* Tree3[15];
        Tree* Tree4[15];
        int list;
        InclinedStreet inStreet = InclinedStreet(135, 175, 400, &movement::tet);
        InclinedStreet inStreet2 = InclinedStreet(-125, -165, 400, &movement::tet);
        InclinedGround inGround = InclinedGround(&movement::tet);
        inclinedStreetH inStreetH = inclinedStreetH(-125,135,810,850,&movement::tet);
        Building* buildings1[5];
        Building* buildings2[5];
        Building* buildings3[4];
        Building* buildings4[4];
        Building2*buildings5[6];
        Building2*buildings6[6];

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void chequeKeyboard();
};

#endif // OGLWIDGET_H
