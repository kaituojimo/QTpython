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
    QDir dir;
private:
    bool findClick(QString path);
};

#endif // C_MYADMIN_H
