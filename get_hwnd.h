#ifndef GET_HWND_H
#define GET_HWND_H
#include "qstring.h"
#include<Windows.h>
#include<qset.h>
BOOL CALLBACK MyEnumProc(HWND hWnd,LPARAM lParam);//枚举所有进程
class CGetHwnd
{

public:
    CGetHwnd();
    QSet<HWND> GetHwnd(QString strExeName);
private:
    HWND hwndLogin;
    QSet<HWND> psethwnd;
    HWND GetProcessMainWnd(DWORD dwProcessId);//获取给定进程ID的窗口handle
};

#endif // GET_HWND_H
