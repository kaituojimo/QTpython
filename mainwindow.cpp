#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QWindow>
#include <QDateTime>
#include <QSettings>
#include "get_hwnd_by_formname.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initform();//初始化窗口
    initpython();

//    QString dmversion = m_DM->Ver();
//    qDebug()<<dmversion;

    //oGethwnd =new CGetHwnd();
//    SetHwnd = oGethwnd->GetHwnd("mymain.exe");
    QTime startTime,endTime;
    QScreen *screen = QGuiApplication::primaryScreen();
    HWND pWnd = first_window(INCLUDE_MINIMIZED);

    QString appName = QString::fromLocal8Bit("《梦幻西游》手游");
    while(pWnd != NULL)
    {
        pWnd = next_window(pWnd,INCLUDE_MINIMIZED);
        QString appstr  =  get_window_title(pWnd);
        if(appstr.compare(appName) == 0){
            SetHwnd.insert(pWnd);
            dm = new CMyDM();
            Idmsoft* mDM = dm->GetIns();
            qMapDm[pWnd] = mDM;

            //int i = mDM->BindWindowEx((int)pWnd, "dx3", "windows", "windows", "dx.public.active.api",0);
            //int i = mDM->BindWindowEx((int)pWnd, "dx3", "windows", "windows", "dx.public.active.api",0);
            int hwnd = (int)pWnd;
            int dm_ret = mDM->BindWindowEx(hwnd,"dx2","windows3","windows","",0);
            dm_ret = mDM->GetLastError();
            //            QVariant x,y;
//            mDM->FindPic(0,0,2000,2000,"D:\\python\\QTpython\\pic\\actions.bmp","000000",0.8,0,x,y);
//            int a=0;
        }
    }
    int nThreads = 2;//获取线程数量
    if (nThreads<1 || nThreads>64)
        return;
    bool bKeepFifo = true;//

    QSettings settings("goldenhawking club","QTpython",this);
    settings.setValue("threads",nThreads);
    settings.setValue("fifokeep",bKeepFifo);
    settings.setValue("Payload",100);
    m_pMyItem = new MyTaskItem(this);
    m_pEngine = new QGHThreadEngine(this,m_pMyItem,nThreads,bKeepFifo);
    connect(this,SIGNAL(maketask(QObject*,QByteArray)),m_pEngine,SLOT(append_new(QObject*,QByteArray)));
//    /*qint32 npicnum= 0;//调用python脚本找图，速度太慢遂放弃
//    for(auto i = SetHwnd.begin();i != SetHwnd.end();i++){
//        QPixmap map = screen->grabWindow((WId)((HWND)*i));
//        QDir dir;
//        QString OBS_SCREEN_PATH=dir.currentPath() + "/imgsrc"+ QString::number(npicnum,10) +".jpg";
//        map.save(QString(OBS_SCREEN_PATH),"JPG");
//        npicnum++;
//    }
//    endTime = QTime::currentTime();
//    int b =startTime.msecsTo(endTime);
//    caller = new QProcess(this);//创建对象，指定父类指针
//    QString path;
//    QDir dir;
//    path=dir.currentPath()+ "/Debug/test.exe";;
//    //path= path + "//test.exe";//  D:\python\waigua\pic\test.jpg D:\python\waigua\pic\fighting.jpg 0.8";
//    QStringList str;
//    str<<"D:\\python\\waigua\\pic\\test.jpg"<<"D:\\python\\waigua\\pic\\fighting.jpg"<<"0.8";
//    startTime = QTime::currentTime();
//    QProcess * po2 = new QProcess(this);
//    //添加后续参数
//    po2->start(path,str);
//    po2->waitForStarted();
//    //等待结束
//    po2->waitForFinished();
//    //获取结果
//    QString strTemp=QString::fromLocal8Bit(po2->readAllStandardOutput());
//    endTime = QTime::currentTime();
//    b =startTime.msecsTo(endTime);*/








//    caller->start(path,str);//启动程序并传入参数
//    connect(this->caller, SIGNAL(readChannelFinished()),this,SLOT(Result()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::initform()
{
    tasklist.append(QString::fromLocal8Bit("捉鬼"));
    tasklist.append(QString::fromLocal8Bit("主线"));
    ui->comboBox->addItems(tasklist);
    return true;
}
void MainWindow::Result()
{
    QProcess *process = (QProcess*)sender();
//        QByteArray res = caller->readAllStandardOutput(); //获取标准输出
    QString result_str = QString::fromLocal8Bit(process->readAll());
}


bool MainWindow::initpython()
{
    //Py_SetPythonHome((wchar_t*)(L"C:/Users/xing/AppData/Local/Programs/Python/Python36-32"));
    Py_Initialize();//初始化调用python脚本功能
    if ( !Py_IsInitialized() )
    {
        return false;
    }
    PyRun_SimpleString("import sys");
    PyRun_SimpleString("sys.path.append(\"/waigua/\")");
    PyObject* pModule = PyImport_ImportModule("findpic");
    if (!pModule)
    {
        qDebug()<<"Cant open python file!\n";
        return false;
    }
    //获取test模块中的hello函数

    PyObject* pFunhello= PyObject_GetAttrString(pModule,"hello");

    if(!pFunhello)
    {
        qDebug()<<"Get function hello failed";
        return false;
    }
    //调用hello函数
    PyObject_CallFunction(pFunhello,NULL);
    //结束，释放python
    Py_Finalize();
    return true;
}

void MainWindow::on_startButton_clicked()
{
    Idmsoft* mDM;
    for(auto i = qMapDm.begin();i!=qMapDm.end();i++)
    {
        mDM = (Idmsoft*)i.value();
        Cmyadmin *task = new Cmyadmin();
        task->setDM(mDM);
        //c_dm->dm = task->getDM();
        QByteArray a;
        a.append("010203");
        emit maketask(task,a);
//        QVariant x,y;
//        task->findpic("D:\\bag.bmp",x,y);
    }
//    QVariant x,y;
//    mDM->FindPic(0,0,2000,2000,"D:\\shimen.bmp","000000",0.7,0,x,y);
}
