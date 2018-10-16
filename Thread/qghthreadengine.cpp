#include "qghthreadengine.h"
#include <assert.h>
QGHThreadEngine::QGHThreadEngine(QObject *parent,QGHThreadTaskItem * pTaskItem,int nThreads,bool bFIFOKeep)
	: QObject(parent),
	m_nThreads(nThreads),
	m_pThreadTaskItem(pTaskItem),
	m_bFIFOKeep(bFIFOKeep)
{
	assert(nThreads>0 && nThreads<512 && pTaskItem!=NULL);
	//创建固定数目的线程
	for (int i=0;i<nThreads;i++)
	{
		QThread * pNewThread = new QThread(this);
		QGHThreadObject * pNewObject = new QGHThreadObject(0,pTaskItem);
        pNewObject->ThreadId = i;
		//记录下来
        m_ThreadPool.push_back(pNewThread);//线程池
        m_ThreadObjs.push_back(pNewObject);//
		m_map_Tasks[pNewObject] = 0;
		pNewThread->start();
		//把QGHThreadObject的信号、曹处理搬移到子线程内
		pNewObject->moveToThread(pNewThread);
		//连接处理完成消息
		connect(pNewObject,SIGNAL(sig_process_finished(QObject *)),this,SLOT(on_sig_process_finished(QObject *)));
		//连接处理新任务消息
		connect(this,SIGNAL(do_task(QObject *, const QByteArray &,QObject *)),pNewObject,SLOT(process(QObject *, const QByteArray &,QObject *)));
        if(i == 1)
        {
            connect(this,SIGNAL(do_control()),pNewObject,SLOT(processcontrol()));
            emit do_control();//process
        }
	}
}

QGHThreadEngine::~QGHThreadEngine()
{
    foreach(QGHThreadObject * obj,m_ThreadObjs)
    {
        disconnect(this,SIGNAL(do_task(QObject *, QByteArray,QObject *)),obj,SLOT(process(QObject *, QByteArray,QObject *)));

        disconnect(obj,SIGNAL(sig_process_finished(QObject *)),this,SLOT(on_sig_process_finished(QObject *)));
        if(obj->ThreadId == 1)
            disconnect(this,SIGNAL(do_control()),obj,SLOT(processcontrol()));
        obj->deleteLater();
    }
    foreach(QThread * th ,m_ThreadPool)
    {
        th->exit(0);
        th->wait();
    }
}
void QGHThreadEngine::append_new(QObject * data_source, const QByteArray &  data)
{
	QObject * pMinObj = 0;
	//对一批来自同一数据源的数据，使用同样的数据源处理，以免发生多线程扰乱FIFO对单个data_source的完整性
	if (m_map_busy_source_counter.find(data_source)!=m_map_busy_source_counter.end()&& m_bFIFOKeep==true)
	{
        m_map_busy_source_counter[data_source]++;
        pMinObj = m_map_busy_source_task[data_source];

    }
	else
	{
        qint32 nMinCost = 0x7fffffff;//为什么指定这个数
		//寻找现在最空闲的一个线程
		for (QMap<QObject *,qint32>::iterator p = m_map_Tasks.begin();p!=m_map_Tasks.end();p++)
		{
            if (p.value()< nMinCost)
            {
                pMinObj = p.key();
                QGHThreadObject *a = (QGHThreadObject *)pMinObj;
                if(a->ThreadId == 1)
                {
                    continue;
                }
                nMinCost = p.value();

            }
		}
		if (pMinObj)
		{
			m_map_busy_source_counter[data_source] = 1;
			m_map_busy_source_task[data_source] = pMinObj;
		}
	}
	if (pMinObj)
	{
		m_map_Tasks[pMinObj]++;
		emit do_task(data_source,data,pMinObj);
	}
}
void QGHThreadEngine::on_sig_process_finished(QObject * data_source)
{
	if (m_map_Tasks.find(sender())!=m_map_Tasks.end())
	{
		m_map_Tasks[sender()]--;
	}
	if (m_map_busy_source_counter.find(data_source)!=m_map_busy_source_counter.end())
	{
		m_map_busy_source_counter[data_source]--;
		if (m_map_busy_source_counter[data_source]<=0)
		{
			m_map_busy_source_counter.remove(data_source);
			m_map_busy_source_task.remove(data_source);
		}
	}
}
