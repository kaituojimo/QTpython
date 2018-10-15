#include "ctask_parent.h"
#include <QTime>
#include <QCoreApplication>
CTaskParent::CTaskParent()
{

}
void CTaskParent::findpic(QString sPicPath,QVariant &x,QVariant &y)
{
    DM->FindPic(0,0,2000,2000,sPicPath,"000000",0.6,0,x,y);
    int a =2;
}
void CTaskParent::movemouse(int x,int y)
{
    DM->MoveTo(x,y);
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
