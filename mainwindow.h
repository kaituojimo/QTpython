#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Python.h>
#include "cmydm.h"
#include "get_hwnd.h"
#include <QScreen>
#include <QDir>
#include "global.h"
#include <qprocess.h>
#include "ctask_parent.h"
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
private slots:
    void Result();

    void on_pushButton_clicked();
    void on_startButton_clicked();
};

#endif // MAINWINDOW_H
