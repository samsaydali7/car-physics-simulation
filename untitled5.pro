#-------------------------------------------------
#
# Project created by QtCreator 2015-07-20T15:15:29

# need the following libs GLAUX.lib GLU32.lib glut.lib glut32.lib OPENGL32.lib
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test2
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    oglwidget.cpp \
    movement.cpp \
    Building.cpp \
    Ground.cpp \
    InclinedGround.cpp \
    InclinedStreet.cpp \
    Object3D.cpp \
    RoadCut.cpp \
    Skybox.cpp \
    StaticObject.cpp \
    Street.cpp \
    texture.cpp \
    Vector3D.cpp \
    GLTexture.cpp \
    Model_3DS.cpp \
    Tree.cpp \
    Building2.cpp \
    mythread.cpp \
    inclinedstreeth.cpp


HEADERS  += mainwindow.h \
    oglwidget.h \
    movement.h \
    Building.h \
    Ground.h \
    InclinedGround.h \
    InclinedStreet.h \
    Object3D.h \
    RoadCut.h \
    Skybox.h \
    StaticObject.h \
    Street.h \
    Vector3D.h \
    GLTexture.h \
    Model_3DS.h \
    Tree.h \
    Building2.h \
    mythread.h \
    inclinedstreeth.h

FORMS    += mainwindow.ui

LIBS += opengl32.lib

LIBS += "C:\Users\Samer2\Documents\CarSimulation\libs\Glaux.lib"

LIBS += "C:\Users\Samer2\Documents\CarSimulation\libs\glut32.lib"

LIBS += "C:\Users\Samer2\Documents\CarSimulation\libs\glui32.lib"

