#include "c_myadmin.h"
#include "QDebug"

#include <qimage.h>
Cmyadmin::Cmyadmin()
{

}
bool Cmyadmin::MakeShiMen()
{

    bool finished = true;
    while (finished) {

        QString path=dir.currentPath()+"/pic/shimen/";

        if(findClick(path+"shimen2.bmp"))
            continue;
        else if(findClick(path+"use.bmp"))
            continue;
        else if(findClick(path+"use2.bmp"))
            continue;
        else if(findClick(path+"push.bmp"))
            continue;
        else if(findClick(path+"fighting.bmp"))
            continue;
        else if(findClick(path+"buy.bmp"))
            continue;
        else if(findClick(path+"shimen1.bmp"))
            continue;
        else
            break;

    }
    return true;
}
bool Cmyadmin::MakeBaotu()
{
    bool finished = true;
    while (finished) {

        QString path=dir.currentPath()+"/pic/baotu/";

        if(findClick(path+"use.bmp"))
            continue;
        else if(findClick(path+"use2.bmp"))
            continue;
        else if(findClick(path+"push.bmp"))
            continue;
        else if(findClick(path+"fighting.bmp"))
            continue;
        else if(findClick(path+"buy.bmp"))
            continue;
        else if(findClick(path+"baotu.bmp"))
            continue;
        else
            break;

    }
    return true;
}
bool Cmyadmin::MakeYunBiao()
{
    bool finished = true;
    while (finished) {
        sleep(1000);
        QString path=dir.currentPath()+"/pic/yunbiao/";

        if(findClick(path+"action.bmp | "+path+"action2.bmp"))
        {
            QVariant x,y;
            sleep(2000);
            DM->FindPic(0,0,2000,2000,path+"yunbiao.bmp","000000",0.6,0,x,y);
            if(x.toInt()>0){
                DM->MoveTo(x.toInt()+270,y.toInt());
                DM->LeftClick();
                sleep(2000);
                if(findClick(path+"yasong.bmp")){
                    sleep(2000);
                    if(findClick(path + "sure.bmp")){
                        sleep(60000);
                        continue;
                    }

                }
            }
        }
        else if(findClick(path+"fighting.bmp | "+path+"yunbiaoing.bmp"))
        {
            qDebug()<<"运镖途中";
            sleep(10000);
        }
        if(findClick(path+"close.bmp"))
        {
            sleep(2000);
        }
        else
            break;

    }
    return true;
}
bool Cmyadmin::MakeZhuoGui()
{
    int nFindFight = 0;//查是不是在战斗状态
    while (1) {
        sleep(1000);
        QString path=dir.currentPath()+"/pic/zhuogui/";
        QString s = DM->FindPicEx(0,0,2000,2000,path+"zhuoguied.bmp","000000",0.5,0);
        QVariant x,y;
        DM->FindPic(0,0,2000,2000,path+"zhuoguied.bmp","000000",0.6,0,x,y);

        if(findClick(path+"action.bmp | "+path+"action2.bmp"))
        {
            QVariant x,y;
            sleep(2000);
            DM->FindPic(0,0,2000,2000,path+"zhuogui.bmp","000000",0.6,0,x,y);
            if(x.toInt()>0){
                DM->MoveTo(x.toInt()+270,y.toInt());
                DM->LeftClick();
                sleep(2000);
                if(findClick(path+"pipei.bmp")){
                    sleep(2000);
                    if(findClick(path + "close.bmp")){
                        sleep(60000);
                        continue;
                    }

                }
            }
        }
        else if(findClick(path+"fighting.bmp"))
        {
            qDebug()<<QString::fromLocal8Bit("战斗中");
            sleep(10000);
            nFindFight = 0;
        }
        else if(findClick(path+"close.bmp"))
        {
            sleep(2000);
        }
        else if(findClick(path+"sure.bmp"))
        {
            sleep(2000);
        }
        else if(findClick(path+"use.bmp | "+path+"use2.bmp"))
        {
            sleep(2000);
        }
        else
            if(nFindFight > 50)
                break;
            else
                nFindFight++;

    }
    return true;
}
bool Cmyadmin::findClick(QString path)
{
    QVariant x,y;
    DM->FindPic(0,0,2000,2000,path,"000000",0.6,0,x,y);

    if(x.toInt()>0){
        DM->MoveTo(x.toInt(),y.toInt());
        DM->LeftClick();
        return true;
    }
    return false;
}
