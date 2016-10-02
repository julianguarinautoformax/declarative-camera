#ifndef MYULDRUNNABLE_H
#define MYULDRUNNABLE_H
#include <QObject>
#include <QAbstractVideoFilter>
#include <QVideoFilterRunnable>

class MyUldFilterHelper{
    
public:
    static bool savevideoframe(QVideoFrame * pf, const QVideoSurfaceFormat &sf);
};

class MyUldFilter : public QAbstractVideoFilter
{
    Q_OBJECT
public:
    
    QVideoFilterRunnable *createFilterRunnable(void) Q_DECL_OVERRIDE;
    Q_INVOKABLE void rawSave();     
    bool isFrameForSaving();

signals:
    void started(QObject * result);
    
private:
    bool m_save;
    
};



class MyUldRunnable : public QVideoFilterRunnable
{
public:
    QVideoFrame run(QVideoFrame * input, const QVideoSurfaceFormat & sFormat, RunFlags flags) Q_DECL_OVERRIDE;
    void setFilter(MyUldFilter*f);
    void commitFrame();
private:
    MyUldFilter * m_f;
    bool isRunning;
    QVideoFrame * m_tmpVideoFrame;
    
};

        
#endif // MYULDRUNNABLE_H
