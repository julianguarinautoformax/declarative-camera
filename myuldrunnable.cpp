#include "myuldrunnable.h"
#include <QDebug>


void MyUldFilter::rawSave(){
    m_save = true;
}
bool MyUldFilter::isFrameForSaving(){
    if (m_save){
        m_save = false;
        return true;
    }
    return false;
}


void MyUldRunnable::setFilter(MyUldFilter*f){
    isRunning = false;
    m_f = f;
            
}



QVideoFilterRunnable * MyUldFilter::createFilterRunnable(){
    qDebug()<<"Seems like a thread will start soon!";
    MyUldRunnable * r = new MyUldRunnable;
    r -> setFilter(this);
    return r;
}


QVideoFrame MyUldRunnable::run(QVideoFrame * input, const QVideoSurfaceFormat &surfaceFormat, RunFlags flags){
    
    Q_UNUSED(surfaceFormat);
    Q_UNUSED(flags);
    QObject * flt = new QObject;
    
    if(!isRunning){
        qDebug()<<QVideoFrame::imageFormatFromPixelFormat(input->pixelFormat());
        qDebug()<<input->pixelFormat();
        emit m_f->started(flt);
        isRunning = true;
    }
    
    if (m_f->isFrameForSaving()){
        qDebug()<<"Saving";
        input->map(QAbstractVideoBuffer::ReadOnly);
        input->unmap();
        qDebug()<<"Save done";
    }
    
    return * input;
    
}


