﻿#include "mytaskitem.h"
#include <QDebug>
MyTaskItem::MyTaskItem(QObject *parent)
    : QGHThreadTaskItem(parent)
{

}

MyTaskItem::~MyTaskItem()
{

}
void MyTaskItem::run(QObject * task_source, const QByteArray & data_array,int ThreadId)
{
    int result =1;
    if(result == -1)
        qDebug()<<"解析失败，请检查帧格式";
    return ;
}
void MyTaskItem::run(int ThreadId)
{
    if(ThreadId == 1)
    {

    }
}
