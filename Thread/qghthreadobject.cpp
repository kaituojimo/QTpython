#include "qghthreadobject.h"
#include <assert.h>

QGHThreadObject::QGHThreadObject(QObject *parent,QGHThreadTaskItem * pThreadTaskItem)
	: QObject(parent),
	m_pThreadTaskItem(pThreadTaskItem)
{
	assert(pThreadTaskItem!=NULL);

}

QGHThreadObject::~QGHThreadObject()
{
}
void QGHThreadObject::process(QObject * data_source, const QByteArray &data,QObject * target)
{
	if (target==this)
	{
        m_pThreadTaskItem->run(data_source,data,ThreadId);
		emit sig_process_finished(data_source);
	}
}
void QGHThreadObject::processcontrol()
{

        m_pThreadTaskItem->run(ThreadId);

}
void QGHThreadObject::SetThreadTaskItem(QGHThreadTaskItem * pThreadTaskItem)
{
	assert(pThreadTaskItem!=NULL);
	m_pThreadTaskItem = pThreadTaskItem;
}
