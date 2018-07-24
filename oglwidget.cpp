#include "oglwidget.h"
#include <windows.h>		// Header File For Windows

OGLWidget::OGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{

}

OGLWidget::~OGLWidget()
{

}

void OGLWidget::initializeGL()
{
    glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
    glClearDepth(1.0f);									// Depth Buffer Setup
    glEnable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);							// Enables? Depth Testing
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);          // The Type Of Depth Testing To Do
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
    glEnable(GL_TEXTURE_2D);

    g.LoadTextures();
    s.LoadTextures();
    inStreet.LoadTextures();
    inStreet2.LoadTextures();
    inGround.LoadTextures();
    inStreetH.LoadTextures();

    //Init Streets
    for (int i = 0; i < 8; i++){
        streets[i] = new Street(i*279,i*279+40,-1960,1960);
        streets[i]-> LoadTextures();
    }
    for (int i = 0; i < 14; i++)
    {
        if (i == 7 || i == 6)
        {
            Streets2[i] = new Street(0 + i * 300 - 1965, 40 + i * 300 - 1965, -1980, 400);
            Streets2[i]->LoadTextures();
        }
        else
        {
            Streets2[i] = new Street(0 + i * 300 - 1965, 40 + i * 300 - 1965, -1980, 360);
            Streets2[i]->LoadTextures();
        }

    }
    t.LoadTextures();
    //Init ROADCUTS
    for (int i = 0; i < 14; i++){
        roadcuts1[i] = new RoadCut(-972.5 + (i * 150), 0.2, 175, 40, 40);
        roadcuts1[i]->LoadTextures();

        for (int j = 0; j < 8; j++)
        {
            roadCuts[i][j] = new RoadCut(-972.5+(i*150), 0.2, -10+(-j*139.5), 40, 40);
            roadCuts[i][j]->LoadTextures();

        }
    }

    //Init Buildings1
    for (int i = 0; i < 5; i++){
        buildings1[i] = new Building(104.5, 0.05, i*60 +30, 3,0);
        buildings1[i]->LoadTextures();
        buildings1[i]->Init();

    }

    //Init Buildings2
    for (int i = 0; i < 5; i++){
        buildings2[i] = new Building(205.5, 0.05,  i*60+30, 3, 180);
        buildings2[i]->LoadTextures();
        buildings2[i]->Init();

    }
    //Init Buildings3
    for (int i = 0; i < 3; i++){
        buildings3[i] = new Building(-60*i+45, 0.05, 30, 3,90);
        buildings3[i]->LoadTextures();
        buildings3[i]->Init();

    }
    //Init Buildings4
    for (int i = 0; i < 4; i++){
        buildings4[i] = new Building(-60*i+105, 0.05, -70, 3,270);
        buildings4[i]->LoadTextures();
        buildings4[i]->Init();

    }
    //Init	Buildings5+6
    for (int i = 0; i < 6; i++)
    {
        buildings5[i] = new Building2(-700+i*300+100, 0, -1200 , 5, 0);
        buildings6[i] = new Building2(-700 + i * 300+100, 0, -670, 5, 0);
        buildings5[i]->LoadTextures();
        buildings5[i]->Init();
        buildings6[i]->LoadTextures();
        buildings6[i]->Init();
    }
    //Init Trees1
    for (int i = 0; i < 6; i++)
    {
        Tree1[i] = new Tree(110 , 0,-30*i-110,5);
        Tree1[i]->LoadTextures();
        Tree1[i]->Init();

    }
    for (int i = 0; i < 8; i++)
    {
        Tree2[i] = new Tree(190 , 0,-30*i-60,5);
        Tree2[i]->LoadTextures();
        Tree2[i]->Init();
    }
    /*  for (int i = 0; i < 6; i++)
    {
        Tree3[i] = new Tree(30*i+255 , 0,10,5);
        Tree3[i]->LoadTextures();
        Tree3[i]->Init();
}
    for (int i = 0; i < 8; i++)
    {
        Tree4[i] = new Tree(30*i+195 , 0,-50,5);
        Tree4[i]->LoadTextures();
        Tree4[i]->Init();
}*/
    //car
    movement::car.Load("C:\\Users\\Samer2\\Documents\\CarSimulation\\UML\\Models\\Car\\Car2.3ds");
    movement::car.pos.x = 20;
    movement::car.pos.z = -20;
    movement::car.pos.y = 4.8;
    movement::car.rot.y = 90;
    movement::car.scale = 5;
    movement::car.Materials[0].tex.BuildColorTexture(51, 51, 51);//car nom sides
    movement::car.Materials[1].tex.BuildColorTexture(32, 43, 51);//new Window
    movement::car.Materials[2].tex.BuildColorTexture(35, 35, 35);// new Inner Dolab
    movement::car.Materials[3].tex.BuildColorTexture(81, 9, 9);//new back Lights
    movement::car.Materials[4].tex.BuildColorTexture(226, 216, 174);//new front lights
    movement::car.Materials[5].tex.BuildColorTexture(0, 0, 0);//?
    movement::car.Materials[6].tex.BuildColorTexture(204, 204, 204);//new logo
    movement::car.Materials[7].tex.BuildColorTexture(35, 35, 35);// new elsageh
    movement::car.Materials[8].tex.BuildColorTexture(255, 255, 255);//new Car Nom.
    movement::car.Materials[9].tex.BuildColorTexture(76, 76, 76);// new hbashat
    movement::car.Materials[10].tex.BuildColorTexture(25, 25, 25);// new wheels
    movement::car.Materials[11].tex.BuildColorTexture(219, 219, 219);// new Body
}
void OGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(movement::car.pos.x - (40 + movement::cameraDistance) * cos(((movement::tt + movement::cameraShift)*3.14) / 180), movement::car.pos.y + 5.2, movement::car.pos.z + (40 + movement::cameraDistance) * sin(((movement::tt + movement::cameraShift)*3.14) / 180), movement::car.pos.x, movement::car.pos.y + 5.2, movement::car.pos.z, 0, 1, 0);

    //Skybox
    glPushMatrix();
    glTranslated(movement::car.pos.x - (40 + movement::cameraDistance) * cos(((movement::tt + movement::cameraShift)*3.14) / 180), movement::car.pos.y + 5.2, movement::car.pos.z + (40 + movement::cameraDistance) * sin(((movement::tt + movement::cameraShift)*3.14) / 180));
    s.Drow();
    glPopMatrix();

    //Ground
    g.Drow();

    //Inclided Ground
    inGround.Drow();

    //Inclided Street
    inStreet.Drow();
    inStreet2.Drow();
    inStreetH.Drow();

    //Streets Drow
    glPushMatrix();
    glRotated(90, 0, 1, 0);
    for (int i = 0; i < 8; i++){
        streets[i]->Drow();

    }
    //draw street
    glPopMatrix();
    glPushMatrix();
    glTranslated(0, 0, 370);
    glRotated(90, 0, 1, 0);
    t.Drow();
    glPopMatrix();
    //Streets2 Drow
    for (int i = 0; i <14; i++){
        Streets2[i]->Drow();
    }
    //RoadCuts
    for (int i = 0; i < 14; i++){
        roadcuts1[i]->Drow();
        for (int j = 0; j < 8;j++)
            roadCuts[i][j]->Drow();
    }


    //Building1
    for (int i = 0; i < 5; i++){
        buildings1[i]->Drow();
    }
    //Building2
    for (int i = 0; i < 5; i++){
        buildings2[i]->Drow();
    }
    //Building3
    for (int i = 0; i < 3; i++){
        buildings3[i]->Drow();
    }
    //Building4
    for (int i = 0; i < 4; i++){
        buildings4[i]->Drow();
    }
    //building5+6
    for (int i = 0; i < 6; i++)
    {
        buildings5[i]->Drow();
        buildings6[i]->Drow();
    }
    //Tree1
    for (int i = 0; i < 6; i++)
    {
        Tree1[i]->Drow();

    }
    for (int i = 0; i < 8; i++)
    {
        Tree2[i]->Drow();

    }
    /*    for (int i = 0; i < 6; i++)
        {
            Tree3[i]->Drow();

        }
        for (int i = 0; i < 8; i++)
        {
            Tree4[i]->Drow();

        }*/
    //Car :)
    movement::car.Draw();

    chequeKeyboard();
    update();
    // parentWidget()->repaint();
}

void OGLWidget::resizeGL(int w, int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 1500.0f);
    //gluPerspective(45, (float)w/h, 0.01, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);

}

void OGLWidget::chequeKeyboard(){
    if(movement::keys[VK_NUMPAD4]){
        movement::cameraShift -= 1;
    }
    if(movement::keys[VK_NUMPAD5]){
        if (movement::cameraDistance < 20)
            movement::cameraDistance += 1;
    }
    if(movement::keys[VK_NUMPAD6]){
        movement::cameraShift += 1;
    }
    if(movement::keys[VK_NUMPAD8]){
        if (movement::cameraDistance > 0)
            movement::cameraDistance -= 1;
    }
    if (movement::keys['A'])
    {
        double ir = (tan((movement::ta * 3.14) / 180)) / 4;
        movement::ac = movement::v*movement::v*ir;
        double angular_velocity = fabs(movement::v) * ir;
        movement::tt += angular_velocity*movement::deltaTime;
        movement::car.rot.y = 90 + movement::tt;
    }
    else if (movement::keys['D'])
    {
        double ir = (tan((movement::ta * 3.14) / 180)) / 4;
        movement::ac = movement::v*movement::v*ir;
        double angular_velocity = fabs(movement::v) * ir;
        movement::tt -= angular_velocity*movement::deltaTime;
        movement::car.rot.y = 90 + movement::tt;
    }
    else{
        movement::ac = 0;
    }
    if(movement::keys[VK_SPACE]){
        movement::v=0;
    }
    if (movement::car.pos.z < 397.5){
        movement::car.rot.x = 0;
        movement::car.pos.y = 4.8;
        if (movement::keys['W'])
        {
            if ((movement::movingForce < ( movement::us *  movement::mass * fabs( movement::ge))) &&  movement::v == 0){
                double f = 0;
            }
            else{
                double f = movement::movingForce;
                if (movement::v>0){
                    f -= movement::k*fabs(movement::v);
                    f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f -= movement::uk*movement::mass*fabs(movement::ge);
                }
                else{
                    f += movement::k*fabs(movement::v);
                    f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f += movement::uk*movement::mass*fabs(movement::ge);
                }
                movement::a = f / movement::mass;
                movement::v += movement::a*movement::deltaTime;
                movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*movement::deltaTime;
                movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*movement::deltaTime;
            }

        }
        else if (movement::keys['S'])
        {
            if ((movement::movingForce < (movement::us * movement::mass * fabs(movement::ge))) && movement::v == 0){
                double f = 0;
            }
            else
            {
                double f = movement::movingForce;
                if (movement::v < 0){
                    f -= movement::k*fabs(movement::v);
                    f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f -= movement::uk*movement::mass*fabs(movement::ge);
                }
                else{
                    f += movement::k*fabs(movement::v);
                    f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f += movement::uk*movement::mass*fabs(movement::ge);
                }
                movement::a = f / movement::mass;
                movement::v -= movement::a*movement::deltaTime;
                movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*movement::deltaTime;
                movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*movement::deltaTime;
            }
        }
        else {
            double f = 0;

            if (movement::v > 0){
                f -= movement::k*fabs(movement::v);
                f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f -= movement::uk*movement::mass*fabs(movement::ge);
            }
            else if(movement::v<0){
                f += movement::k*fabs(movement::v);
                f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f += movement::uk*movement::mass*fabs(movement::ge);
            }
            movement::a = f / movement::mass;
            movement::v += movement::a*movement::deltaTime;

            movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*movement::deltaTime;
            movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*movement::deltaTime;
        }


    }
    if (movement::car.pos.z >= 397.5){

        movement::car.rot.x = -movement::tet;
        if (movement::keys['W']){

            double f = movement::movingForce - (movement::mass * fabs(movement::ge) * sin((movement::tet*3.14) / 180))*sin((-movement::tt*3.14) / 180);
            if ((f < (movement::us * movement::mass * fabs(movement::ge))) && movement::v == 0){
                double f = 0;
            }
            else
            {
                if (movement::v>0){
                    f -= movement::k*fabs(movement::v);
                    f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f -= movement::uk*movement::mass*fabs(movement::ge);
                }
                else{
                    f += movement::k*fabs(movement::v);
                    f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                    f += movement::uk*movement::mass*fabs(movement::ge);
                }
                movement::a = f / movement::mass;
                movement::v += movement::a*movement::deltaTime;
                movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
                movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
                movement::car.pos.y -= movement::v*sin((movement::tt*3.14) / 180)*sin((movement::tet*3.14) / 180)*movement::deltaTime; //
            }
        }

        else if (movement::keys['S'])
        {

            double f = movement::movingForce + (movement::mass * fabs(movement::ge) * sin((movement::tet*3.14) / 180))*sin((-movement::tt*3.14) / 180);
            if (movement::v<0){
                f -= movement::k*fabs(movement::v);
                f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f -= movement::uk*movement::mass*fabs(movement::ge);
            }
            else{
                f += movement::k*fabs(movement::v);
                f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f += movement::uk*movement::mass*fabs(movement::ge);
            }
            movement::a = f / movement::mass;
            movement::v -= movement::a*movement::deltaTime;
            movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
            movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
            movement::car.pos.y -= movement::v*sin((movement::tt*3.14) / 180)*sin((movement::tet*3.14) / 180)*movement::deltaTime; //
        }
        else{
            double f = -movement::mass * fabs(movement::ge) * sin((movement::tet*3.14) / 180)*sin((-movement::tt*3.14) / 180);
            if (movement::v > 0){
                f -= movement::k*fabs(movement::v);
                f -= 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f -= movement::uk*movement::mass*fabs(movement::ge);
            }
            else if (movement::v<0){
                f += movement::k*fabs(movement::v);
                f += 0.5*movement::p*movement::dragEfficien*movement::area*movement::v*movement::v;
                f += movement::uk*movement::mass*fabs(movement::ge);
            }
            movement::a = f / movement::mass;
            movement::v += movement::a*movement::deltaTime;

            movement::car.pos.z -= movement::v*sin((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
            movement::car.pos.x += movement::v*cos((movement::tt*3.14) / 180)*cos((movement::tet*3.14) / 180)*movement::deltaTime; //
            movement::car.pos.y -= movement::v*sin((movement::tt*3.14) / 180)*sin((movement::tet*3.14) / 180)*movement::deltaTime; //

        }

    }
}
