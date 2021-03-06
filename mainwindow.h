﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Python.h>
#include "cmydm.h"
#include "get_hwnd.h"
#include <QScreen>
#include <QDir>
#include "global.h"
#include <qprocess.h>
#include <MakeTask/ctask_parent.h>
#include <Thread/mytaskitem.h>
#include <Thread/qghthreadengine.h>
#include <MakeTask/c_myadmin.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    CGetHwnd *oGethwnd;
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private:
    bool initform();
    bool initpython();
    CMyDM *dm;
    QList<QString> tasklist;
    QProcess* caller;
    QMap<HWND,Idmsoft*> qMapDm;
    QGHThreadEngine * m_pEngine;
    MyTaskItem * m_pMyItem;
private slots:
    void Result();
    void on_startButton_clicked();
signals:
    void maketask(QObject * ,const QByteArray &  );
};

#endif // MAINWINDOW_H
