#include "c_myadmin.h"
#include "QDebug"

#include <qimage.h>
Cmyadmin::Cmyadmin()
{
    StrCurrentPath=dir.currentPath();
}
bool Cmyadmin::MakeShiMen()
{

        sleep(1000);
        QString path = StrCurrentPath +"/pic/";
        if(findClick(path+"action.bmp | "+path+"action2.bmp"))
        {
            QVariant x,y;
            sleep(2000);
            DM->FindPic(0,0,2000,2000,path+"shimen/shimen2.bmp","000000",0.6,0,x,y);
            if(x.toInt()>0){
                DM->MoveTo(x.toInt()+270,y.toInt());
                DM->LeftClick();

                do{
                    sleep(5000);
                }
                while (!findClick(path+"shimen/putizushi.bmp"));
                DM->MoveTo(900,300);
                DM->LeftDown();
                sleep(500);
                DM->MoveTo(900,600);
                DM->LeftUp();
                int finished = 10;
                while (finished>0) {
                    sleep(2000);
                    if(findClick(path+"shimen/No.bmp"))
                    {
                        finished =10;
                        continue;
                    }
                    if(findClick(path+"shimen/use.bmp"))
                    {
                        finished =10;
                        continue;
                    }
                    else if(findClick(path+"shimen/buy.bmp | "+path+"shimen/buy2.bmp"))
                    {
                        if(findClick(path+"shimen/buy3.bmp")){
                            findClick(path+"shimen/buy.bmp | "+path+"shimen/buy2.bmp");

                        }
                        finished =10;
                        continue;
                    }
                    else if(findClick(path+"shimen/fighting.bmp"))
                    {
                        finished =10;
                        continue;
                    }
                    else if(findClick(path+"shimen/shimen1.bmp"))
                    {
                        finished =10;
                        continue;
                    }
                    else if(findClick(path+"shimen/use2.bmp"))
                    {
                        finished =10;
                        continue;
                    }
                    else if(findClick(path+"shimen/push.bmp"))
                    {
                        finished =10;
                        continue;
                    }


                    else
                        finished--;

                }
            }
        }



    return true;
}
bool Cmyadmin::MakeBaotu()
{
    bool finished = true;
    while (finished) {

        QString path = StrCurrentPath +"/pic/baotu/";

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
        QString path = StrCurrentPath +"/pic/yunbiao/";

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
        QString path = StrCurrentPath +"/pic/zhuogui/";
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
        sleep(500);
        return true;
    }
    return false;
}
bool Cmyadmin::findMove(QString path,int width,int heigh)
{
    QVariant x,y;
    DM->FindPic(0,0,2000,2000,path,"000000",0.6,0,x,y);

    if(x.toInt()>0){
        for(int i =0;i<5;i++)
        {
            DM->MoveTo(x.toInt(),y.toInt()+i*10);
            DM->LeftDown();
            sleep(200);
            DM->MoveTo(x.toInt()+width,y.toInt()+i*10);
            sleep(200);
            DM->LeftUp();
            return true;
        }
    }
    return false;
}
bool Cmyadmin::Islogin()
{
    QString path = StrCurrentPath;
    DM->MoveTo(980,60);
    DM->LeftClick();
    sleep(500);
    if(findClick(path+"/pic/myself.bmp")){
        if(findClick(path+"/pic/close.bmp | "+path+"/pic/close2.bmp")){
//        if(findClick(path+"/pic/close.bmp ")){
            return true;
        }
    }
    else if(findClick(path+"/pic/login.bmp")){
        sleep(5000);
        findClick(path+"/pic/cancel.bmp");
        sleep(3000);
        if(findClick(path+"/pic/guaguale.bmp")){
            sleep(1000);
            if(findMove(path+"/pic/guaguale2.bmp",300,70)){
                if(findClick(path+"/pic/close.bmp")){
                    return true;
                }
            }
            else if(findMove(path+"/pic/guaguale3.bmp",250,70)){
                if(findClick(path+"/pic/close.bmp")){
                    return true;
                }
            }
        }
        return true;
    }
    else{
        if(findClick(path+"/pic/close.bmp | "+path+"/pic/close2.bmp")){
            if(findClick(path+"/pic/close.bmp | "+path+"/pic/close2.bmp")){
                return true;
            }
        }
    }


}
