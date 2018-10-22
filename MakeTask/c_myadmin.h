#ifndef C_MYADMIN_H
#define C_MYADMIN_H
#include "ctask_parent.h"

#include <QDir>

class Cmyadmin : public CTaskParent
{
public:
    Cmyadmin();
    bool MakeShiMen();
    bool MakeBaotu();
    bool MakeYunBiao();
    bool MakeZhuoGui();
    bool Islogin();
    QDir dir;
private:
    QString StrCurrentPath;
    bool findClick(QString path);
    bool findMove(QString path,int width,int heigh);
};

#endif // C_MYADMIN_H
