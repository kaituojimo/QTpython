#-------------------------------------------------
#
# Project created by QtCreator 2018-10-12T09:19:53
#
#-------------------------------------------------

QT       += core gui
QT +=  axcontainer
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTpython
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    cmydm.cpp \
    dm.cpp

HEADERS += \
        mainwindow.h \
    cmydm.h \
    dm.h

FORMS += \
        mainwindow.ui


win32: LIBS += -LC:/Users/xing/AppData/Local/Programs/Python/Python36-32/libs/ -lpython36

INCLUDEPATH += C:/Users/xing/AppData/Local/Programs/Python/Python36-32/include
DEPENDPATH += C:/Users/xing/AppData/Local/Programs/Python/Python36-32/include

win32:!win32-g++: PRE_TARGETDEPS += C:/Users/xing/AppData/Local/Programs/Python/Python36-32/libs/python36.lib
else:win32-g++: PRE_TARGETDEPS += C:/Users/xing/AppData/Local/Programs/Python/Python36-32/libs/libpython36.a
