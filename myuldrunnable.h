#ifndef MYULDRUNNABLE_H
#define MYULDRUNNABLE_H
#include <QObject>
#include <QAbstractVideoFilter>
#include <QVideoFilterRunnable>

class MyUldFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    
    QVideoFilterRunnable *createFilterRunnable(void) Q_DECL_OVERRIDE;
    
signals:
    void finished(QObject * result);
    
};



class MyUldRunnable : public QVideoFilterRunnable
{
public:
    QVideoFrame run(QVideoFrame * input, const QVideoSurfaceFormat & sFormat, RunFlags flags) Q_DECL_OVERRIDE;
    void setFilter(MyUldFilter*f);
private:
    MyUldFilter * m_f;
    bool isRunning;
};

        
#endif // MYULDRUNNABLE_H
