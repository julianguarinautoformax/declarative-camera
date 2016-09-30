#include "myuldrunnable.h"
#include <QDebug>





QVideoFilterRunnable * MyUldFilter::createFilterRunnable(){
    qDebug()<<"Seems like a thread will start soon!";
    MyUldRunnable * r = new MyUldRunnable;
    r -> setFilter(this);
    return r;
}


void MyUldRunnable::setFilter(MyUldFilter*f){
    isRunning = false;
    m_f = f;
}



QVideoFrame MyUldRunnable::run(QVideoFrame * input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags){
    
    Q_UNUSED(surfaceFormat);
    Q_UNUSED(flags);
    QObject * flt = new QObject;
    if(!isRunning){
        emit m_f->finished(flt);
        isRunning = true;
    }
    
    return * input;
    
}


