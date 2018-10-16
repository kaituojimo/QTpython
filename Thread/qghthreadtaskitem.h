#ifndef QGHTHREADTASKITEM_H
#define QGHTHREADTASKITEM_H
#include <QObject>
//用户重载该类，实现自定义方法的线程池调用
class QGHThreadTaskItem:public QObject
{
	Q_OBJECT

public:
	QGHThreadTaskItem(QObject *parent);
	~QGHThreadTaskItem();
public:
    virtual void run(QObject * task_source, const QByteArray & data_array,int ThreadId) = 0;
    virtual void run(int ThreadId) = 0;

};
#endif
