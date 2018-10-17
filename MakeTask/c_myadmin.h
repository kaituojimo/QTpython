#ifndef C_MYADMIN_H
#define C_MYADMIN_H
#include "ctask_parent.h"

#include <QDir>

class Cmyadmin : public CTaskParent
{
public:
    Cmyadmin();
    bool MakeShiMen();
    QDir dir;
};

#endif // C_MYADMIN_H
