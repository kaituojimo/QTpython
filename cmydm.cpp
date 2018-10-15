
#include "cmydm.h"
#include <QMessageBox>
#include <QDir>
#include <QProcess>
#include <QAxWidget>  //需在Pro文件中添加
#include <qdebug.h>
#include <QtWidgets/QApplication>

#pragma execution_character_set("utf-8")

Idmsoft* m_DM;
bool m_bNeedClear;

CMyDM::CMyDM()
{
    m_DM = NULL;
    m_bNeedClear = false;
}

CMyDM::~CMyDM()
{
    deInit();
}

Idmsoft* CMyDM::GetIns()
{
    if (m_DM == NULL)
    {
        m_DM = new Idmsoft();
        init();
    }
    return m_DM;
}

void CMyDM::init() {
    // 实例化COM组件对象
    bool rst = m_DM->setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
    if (!rst) {
        // COM组件还未在系统注册，注册dm.dll，需要当前exe程序以管理员权限运行
        qDebug("Reg dm.dll");

        RegDllByCmd("dm.dll");
        rst = m_DM->setControl("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}");
        if (!rst) {

        }
    }
    m_bNeedClear = true;
}

int CMyDM::deInit() {

    if (m_bNeedClear)
    {
        m_DM->clear();
        m_DM->destroyed();
        m_DM = NULL;
        return 0;
    }
    return -1;
}


void CMyDM::RegDllByCmd(QString dllName)
{
    QString path;
    path = QCoreApplication::applicationDirPath();//获取程序运行路径
    QString cmdStr = "Regsvr32 " + path + "/dm.dll /s";
    QProcess p(0);
    p.start("cmd", QStringList() << "/c" << cmdStr);
    p.waitForStarted();
    p.waitForFinished();
}
