#ifndef CTASK_PARENT_H
#define CTASK_PARENT_H
#include "dm.h"
#include <QCoreApplication>
using namespace Dm;
class CTaskParent: public QObject//实现大漠在主线程与子线程直接的信号槽连接
{
    Q_OBJECT
public:
    explicit CTaskParent(QObject *parent = nullptr);
    int findpic(QString sPicPath,QVariant &x,QVariant &y);
    void movemouse(int x,int y);
    void keydown(QString& key_str);\
    void keyup(QString& key_str);
    void keypress(QString& key_str);
    void clickmouseleft();
    void clickmouseright();
    void downmouseleft();
    void upmouseleft();
    QString getcurrentTime();
    void setDM(Idmsoft* mDM);
    Idmsoft* getDM( );
    void sleep(int mSec);
protected:
    Idmsoft* DM;

};

#endif // CTASK_PARENT_H
