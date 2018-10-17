#ifndef CTASK_PARENT_H
#define CTASK_PARENT_H
#include "dm.h"
using namespace Dm;
class CTaskParent: public QObject//实现大漠在主线程与子线程直接的信号槽连接
{
    Q_OBJECT
public:
    explicit CTaskParent(QObject *parent = nullptr);
    bool findpic(QString sPicPath,QVariant &x,QVariant &y);
    void movemouse(int x,int y);
    void keydown(QString& key_str);\
    void keyup(QString& key_str);
    void keypress(QString& key_str);
    void clickmouseleft();
    void clickmouseright();
    void downmouseleft();
    void upmouseleft();
    void setDM(Idmsoft* mDM);
    Idmsoft* getDM( );
protected:
    Idmsoft* DM;

};

#endif // CTASK_PARENT_H
