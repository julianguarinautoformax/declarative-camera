TEMPLATE=app
TARGET=declarative-camera

QT += quick qml multimedia

SOURCES += qmlcamera.cpp \
    myuldrunnable.cpp \
    peek-a-boo-lib/peekaboolib.cpp \
    nv12.cpp \
    nv21utils.cpp
RESOURCES += declarative-camera.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/multimedia/declarative-camera
INSTALLS += target

HEADERS += \
    myuldrunnable.h \
    peek-a-boo-lib/peekaboolib.h \
    nv21utils.h

DISTFILES +=

