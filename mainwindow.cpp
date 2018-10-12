#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initform();
    //Py_SetPythonHome((wchar_t*)(L"C:/Users/xing/AppData/Local/Programs/Python/Python36-32"));
    Py_Initialize();
    if ( !Py_IsInitialized() )
    {
        return ;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"/waigua/\")");
    PyObject* pModule = PyImport_ImportModule("findpic");
    //PyObject* pModule = PyImport_ImportModule("findpic");
    if (!pModule)
    {
        qDebug()<<"Cant open python file!\n";
        return ;
    }
    //获取test模块中的hello函数
    PyObject* pFunhello= PyObject_GetAttrString(pModule,"hello");

    if(!pFunhello)
    {
        qDebug()<<"Get function hello failed";
        return ;
    }
    //调用hello函数
    PyObject_CallFunction(pFunhello,NULL);
    //结束，释放python
    //Py_SetPythonHome("C:/Users/xing/AppData/Local/Programs/Python/Python36-32");
    Py_Finalize();
    dm = new CMyDM();

    Idmsoft* m_DM = dm->GetIns();
    QString dmversion = m_DM->Ver();
    m_DM->MoveTo(200,200);
    qDebug()<<dmversion;

}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::initform()
{
    tasklist.append("捉鬼");
    ui->comboBox->addItems(tasklist);
    return true;
}
