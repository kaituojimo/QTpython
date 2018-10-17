#include "c_myadmin.h"

Cmyadmin::Cmyadmin()
{

}
bool Cmyadmin::MakeShiMen()
{

    QString path=dir.currentPath()+"/pic/shimen/";
    QVariant x,y;
    if(findpic(path+"shimen1.bmp",x,y)){//查找师门任务
        DM->MoveTo(x.toInt(),y.toInt());
        //判断任务详情
        if(findpic(path+"use.bmp",x,y)){
            movemouse(x.toInt(),y.toInt());
            clickmouseleft();
            qDebug()<<"使用一个物品";
        }
    }
    return true;
}
