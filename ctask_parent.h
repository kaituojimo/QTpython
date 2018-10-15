#ifndef CTASK_PARENT_H
#define CTASK_PARENT_H
#include "dm.h"
using namespace Dm;
class CTaskParent
{
public:
    CTaskParent();
    void findpic(QString sPicPath,int &x,int &y);
    void movemouse(int &x,int &y);
    void clickeys();
    void clickmouse();
    void setDM(Idmsoft* mDM);
    Idmsoft* getDM( );
protected:
    Idmsoft* DM;

};

#endif // CTASK_PARENT_H
