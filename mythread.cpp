#include "mythread.h"

myThread::myThread(MainWindow* mw)
{
    this->mw = mw;
}

void myThread::run(){
    while(true){
        mw->vChange(movement::v);
        mw->aChange(movement::a);
        mw->acChange(movement::ac);
        sleep(1);
    }
}

