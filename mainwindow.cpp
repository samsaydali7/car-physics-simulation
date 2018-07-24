#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "movement.h"
#include "QKeyEvent"
#include "string.h"
#include <sstream>  // for string streams

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch ( event->key() ) {
    case Qt::Key_4:
        movement::keys[VK_NUMPAD4]=true;
        break;
    case Qt::Key_6:
        movement::keys[VK_NUMPAD6]=true;
        break;
    case Qt::Key_8:
        movement::keys[VK_NUMPAD8]=true;
        break;
    case Qt::Key_5:
        movement::keys[VK_NUMPAD5]=true;
        break;
    case Qt::Key_S:
        movement::keys['S']=true;
        break;
    case Qt::Key_W:
        movement::keys['W']=true;
        break;
    case Qt::Key_A:
        movement::keys['A']=true;
        break;
    case Qt::Key_D:
        movement::keys['D']=true;
        break;
    case Qt::Key_Space:
        movement::keys[VK_SPACE]=true;
        break;
    default:
        break;
    }

}
void MainWindow::rep(){
    vChange(movement::v);
    aChange(movement::a);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    switch ( event->key() ) {
    case Qt::Key_4:
        movement::keys[VK_NUMPAD4]=false;
        break;
    case Qt::Key_6:
        movement::keys[VK_NUMPAD6]=false;
        break;
    case Qt::Key_8:
        movement::keys[VK_NUMPAD8]=false;
        break;
    case Qt::Key_5:
        movement::keys[VK_NUMPAD5]=false;
        break;
    case Qt::Key_S:
        movement::keys['S']=false;
        break;
    case Qt::Key_W:
        movement::keys['W']=false;
        break;
    case Qt::Key_A:
        movement::keys['A']=false;
        break;
    case Qt::Key_D:
        movement::keys['D']=false;
        break;
    case Qt::Key_Space:
        movement::keys[VK_SPACE]=false;
        break;
    default:
        break;
    }
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    movement::ta = value*1.0;
    ui->label->setText("Turning Angle " + QString::number(value));
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    movement::tet = value*1.0;
    ui->label_12->setText("Ground Angel " + QString::number(value));

}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    movement::movingForce = arg1;
}

void MainWindow::on_doubleSpinBox_editingFinished()
{
    movement::movingForce = ui->doubleSpinBox->value();
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    movement::mass = arg1;
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
    movement::uk=arg1;
}

void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    movement::us=arg1;
}

void MainWindow::on_doubleSpinBox_9_valueChanged(double arg1)
{
    movement::ge = arg1;
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
    movement::dragEfficien = arg1;
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
    movement::area = arg1;
}

void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
    movement::p=arg1;
}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
    movement::deltaTime=arg1;
}

void MainWindow::on_doubleSpinBox_10_valueChanged(double arg1)
{
    movement::k=arg1;
}

void MainWindow::vChange(double d){
    if(fabs(d)<0.9){
        d=0;
        movement::ok=true;
    }
    else{
        movement::ok = false;
    }
    ui->vLabel->setText("v: " + QString::number(d));
}

void MainWindow::aChange(double d){
    if(fabs(d)<0.001 || movement::ok)
        d=0;
    ui->alabel->setText("a: " + QString::number(d));
}
void MainWindow::acChange(double d){

    ui->alabel_2->setText("ac: " + QString::number(d));
}
