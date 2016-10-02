#ifndef NV21UTILS_H
#define NV21UTILS_H
#include <qglobal.h>
#include <qsize.h>
#include <QVideoFrame>
QT_BEGIN_NAMESPACE

// return the index of the closest value to <value> in <list>
// (binary search)
int qt_findClosestValue(const QList<int> &list, int value);

bool qt_sizeLessThan(const QSize &s1, const QSize &s2);

void qt_convert_BGR32_to_ARGB32(const uchar *rgbin, uchar *rgbout, int width, int height);
void qt_convert_NV21_to_ARGB32(const uchar *yuv, quint32 *rgb, int width, int height);

typedef void(*qt_convert_fp)(const uchar *, void *, int, int);

typedef struct QVideoFrameToQImageConversor{
    
    qt_convert_fp conversionFunction;
    
}QVideoFrameToQImageConversor;

void selectConversionFunction(QVideoFrame * fp, QVideoFrameToQImageConversor conversor);

    


QT_END_NAMESPACE

#endif // NV21UTILS_H
