#include "ctask_parent.h"
#include <QTime>
#include <QCoreApplication>
#include <QDateTime>
CTaskParent::CTaskParent(QObject *parent) : QObject(parent)
{

}
int CTaskParent::findpic(QString sPicPath,QVariant &x,QVariant &y)
{
    DM->FindPic(0,0,2000,2000,sPicPath,"000000",0.6,0,x,y);
    if(x.Int>0 && y.Int>0)
        return 1;
    else
        return 0;
}
void CTaskParent::movemouse(int x,int y)
{
    DM->MoveTo(x,y);
}
QString CTaskParent::getcurrentTime()
{
    return QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
}
void CTaskParent::keydown(QString& key_str)
{
    DM->KeyDownChar(key_str);
}
void CTaskParent::keyup(QString& key_str)
{
    DM->KeyUpChar(key_str);
}
void CTaskParent::keypress(QString& key_str)
{
    DM->KeyDownChar(key_str);
    QTime t;
    t.start();
    while(t.elapsed()<200)
        QCoreApplication::processEvents();
    DM->KeyUpChar(key_str);
}
void CTaskParent::clickmouseleft()
{
    DM->LeftClick();
}
void CTaskParent::clickmouseright()
{
    DM->RightClick();
}
void CTaskParent::downmouseleft()
{
    DM->LeftDown();
}
void CTaskParent::upmouseleft()
{
    DM->LeftUp();
}
void CTaskParent::setDM(Idmsoft* mDM)
{
    DM = mDM;
}
Idmsoft* CTaskParent::getDM()
{
    return DM;
}
void CTaskParent::sleep(int mSec)
{
    QTime dieTime = QTime::currentTime().addMSecs(mSec);
    while( QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    ;
}
