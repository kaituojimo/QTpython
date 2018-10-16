#ifndef MYTASKITEM_H
#define MYTASKITEM_H
#include <qprocess.h>
#include "qghthreadtaskitem.h"
class MyTaskItem : public QGHThreadTaskItem
{
    Q_OBJECT

public:
    MyTaskItem(QObject *parent);
    ~MyTaskItem();
private:

public:
    virtual void run(QObject * task_source, const QByteArray & data_array,int ThreadId);
    virtual void run(int ThreadId);
signals:
    void evt_SendData(QObject * objClient,const QByteArray & dtarray);
    void evt_Sendcontrol(bool needtocontrol);
private slots:

};

#endif // MYTASKITEM_H
