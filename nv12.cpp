#include "nv21utils.h"
#include "myuldrunnable.h"
#include <QDebug>
#include <QByteArray>


void toBGR32(QVideoFrame * fp){
    
    int width = fp->width();
    int height = fp->height();
    
    /* Calculate size for 4 bytes per pixel */
    QByteArray rgbBuffer(width*height*4,0);
    
    /* Get YUV frame */
    const uchar * pyuv = fp->bits();
    
    /* rgbBufferPointer */
    quint32 * prgb = reinterpret_cast<quint32*>(rgbBuffer.data()); 
    
    qt_convert_NV21_to_ARGB32(pyuv,prgb,width,height);
    uchar*puc = reinterpret_cast<uchar*>(prgb);
    
    
    /* Create QImage */
    QImage img = QImage(puc,width,height,QImage::Format_ARGB32);
    img.save("test","PNG",100);
    
}

bool MyUldFilterHelper::savevideoframe(QVideoFrame  * fp, const QVideoSurfaceFormat &sf ){
    
    if (fp->isMapped()==false) {
        qDebug()<<"Frame is not mapped.... silently dropped";
        return false;
    }
    qDebug()<<"SURFACE FORMAT";
    qDebug()<<"--------------";
    qDebug()<<"Frame Width:"<<sf.frameWidth();
    qDebug()<<"Frame Height:"<<sf.frameHeight();
    qDebug()<<"Video Handle Type:"<<sf.handleType();
    qDebug()<<"Pixel Aspect Ratio:"<<sf.pixelAspectRatio();
    qDebug()<<"Pixel Format:"<<sf.pixelFormat();
    qDebug()<<"Color Space:"<<sf.yCbCrColorSpace();
    qDebug()<<"Properties:"<<sf.propertyNames();
    qDebug()<<"Scan Line Direction:"<<sf.scanLineDirection();
    qDebug()<<"Viewport Size:"<<sf.sizeHint();
    qDebug()<<"Viewport Rect:"<<sf.viewport();
    
    qDebug()<<"VIDEO FRAME INFO";
    qDebug()<<"----------------";
    qDebug()<<"MetaData:"<<fp->availableMetaData();
    qDebug()<<"Mapped Bytes:"<<fp->mappedBytes();
    qDebug()<<"Planes:"<<fp->planeCount();
    qDebug()<<"Size:"<<fp->size();
    qDebug()<<"StartTime:"<<fp->startTime();
    qDebug()<<"Bytes Per Line Plane 0 :"<<fp->bytesPerLine(0);
    qDebug()<<"Bytes Per Line Plane 1 :"<<fp->bytesPerLine(1);
    qDebug()<<"Address 0:"<<reinterpret_cast<qint64>(fp->bits(0));
    qDebug()<<"Address 1:"<<reinterpret_cast<qint64>(fp->bits(1));
    
    toBGR32(fp);
            
    return true;
    
    
    
}
