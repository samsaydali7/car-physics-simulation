#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>
#include"mainwindow.h"
#include "movement.h"

class myThread: public QThread
{
private:
    MainWindow* mw;
public:
    myThread(MainWindow*);
    void run();
};

#endif // MYTHREAD_H
