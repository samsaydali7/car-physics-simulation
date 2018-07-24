#define _CRT_NONSTDC_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS

#include "mainwindow.h"
#include <QApplication>
#include "movement.h"
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    myThread *mt=new myThread(&w);
    w.show();
    mt->start();
    return a.exec();
}
