#pragma once
#include "dm.h"

using namespace Dm;

class CMyDM
{
public:
    CMyDM();
    ~CMyDM();


    /// 获取类的实例
    static Idmsoft* GetIns();

    /// 清理COM接口，main函数返回前，应确保调用此方法，否则可能引起内存泄漏
    static int deInit();

private:
    /// 初始化COM组件
    static void init();
    static void RegDllByCmd(QString dllName);

};
