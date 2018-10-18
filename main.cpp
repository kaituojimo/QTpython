#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QApplication>
#include <QDir>
#include <QProcess>
#include <qdebug.h>
#include <qmessagebox.h>
#include <qstring.h>
#include "dm.h"
using namespace Dm;

#pragma execution_character_set("utf-8")
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     Q_INIT_RESOURCE(qtrcs);
//    Idmsoft*  m_DM = new Idmsoft;
//    // 实例化COM组件对象
//    QString path;
//    bool rst = m_DM->setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
//    if (!rst)
//    {
//        // COM组件还未在系统注册，注册dm.dll，需要当前exe程序以管理员权限运行
//        qDebug("Reg dm.dll");


//        QDir dir;
//        path=dir.currentPath();
//        QString cmdStr = "Regsvr32 " + path + "/dm.dll /s";
//        QProcess p(0);
//        p.start("cmd", QStringList() << "/c" << cmdStr);
//        p.waitForStarted();
//        p.waitForFinished();

//        rst = m_DM->setControl("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}");
//        if (!rst)
//        {

//        }
//        else
//        {

//        }
//    }
//    else
//    {

//    }
//    path = m_DM->Ver();
//    qDebug()<<path;
    MainWindow w;
    w.show();

    return a.exec();
}
