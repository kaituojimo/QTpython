#ifndef QGHTHREADOBJECT_H
#define QGHTHREADOBJECT_H
#include <QObject>
#include "qghthreadtaskitem.h"
//用于在子线程内具体承担事件循环的类，用户无需重载
//要想让槽在子线程运行，一般是派生一个QObject的类，并把对象MoveToThread到某个QThread管理的线程上去
class QGHThreadObject:public QObject
{
	Q_OBJECT

public:
	QGHThreadObject(QObject *parent,QGHThreadTaskItem * pThreadTaskItem);
	~QGHThreadObject();
public:
	void SetThreadTaskItem(QGHThreadTaskItem * pThreadTaskItem);
    int ThreadId;
public slots:
	//************************************
	// Method:    process
	// FullName:  QGHThreadObject::process
	// Access:    public 
	// Returns:   void
	// Qualifier:
	// Parameter: QObject *		任务来源 （相同任务源的任务，在队列非空时会被安排到同一个线程处理，以确保对相同源的FIFO）
	// Parameter: QByteArray	任务体	
	// Parameter: QObject *		处理任务的线程对象（QGHThreadObject）
	//************************************
	void process(QObject * data_source, const QByteArray &data,QObject * target);
    void processcontrol();
private:
	QGHThreadTaskItem * m_pThreadTaskItem;

signals:
	//信号，表示一次处理已经完成。QGHThreadEngine捕获该信号，管理data_source的 FIFO 顺序
	void sig_process_finished(QObject * data_source);
};
#endif
