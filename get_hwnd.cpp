#include "get_hwnd.h"
#include "psapi.h"
#include <TlHelp32.h>
typedef struct tagWNDINFO
{
    DWORD dwProcessId;
    HWND hWnd;
} WNDINFO, *LPWNDINFO;

CGetHwnd::CGetHwnd()
{

}
QSet<HWND> CGetHwnd::GetHwnd(QString strExeName)
{
    PROCESSENTRY32 pe32;
    //在使用这个结构前，先设置它的大小
    pe32.dwSize = sizeof(pe32);
    //给系统内所有的进程拍个快照
    HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
    if (hProcessSnap == INVALID_HANDLE_VALUE)
    {
        //printf("CreateToolhelp32Snapshot 调用失败.\n");
        return psethwnd;
    }
    //遍历进程快照，轮流显示每个进程的信息
    BOOL bMore = ::Process32First(hProcessSnap,&pe32);
    while (bMore)
    {
        //if(pe32.szExeFile == exeName)//找到了进程
        if(strExeName.compare(QString::fromStdWString(pe32.szExeFile)) == 0)
        {
            HWND game_window_hwnd=GetProcessMainWnd(pe32.th32ProcessID );
            if (NULL != game_window_hwnd)
            {
//                ::CloseHandle(hProcessSnap);
//                return game_window_hwnd;
                psethwnd.insert(game_window_hwnd);
            }
        }
        bMore = ::Process32Next(hProcessSnap,&pe32);
    }
    //不要忘记清除掉snapshot对象
    ::CloseHandle(hProcessSnap);
    if(psethwnd.isEmpty())
        return psethwnd;
    else
        return psethwnd;


    //通过进程名查找
    //    QString AppName(QString::fromLocal8Bit("《梦幻西游》手游"));
    //    LPCWSTR AppCaption = reinterpret_cast <LPCWSTR>(AppName.data());
    //    HWND hwndLogin=FindWindow(NULL,AppCaption);
    //    if(hwndLogin != 0)
    //    {
    //        return hwndLogin;
    //    }
    //    else
    //    {
    //        return (HWND)(-1);
    //    }
}
BOOL CALLBACK MyEnumProc(HWND hWnd,LPARAM lParam)//枚举所有进程
{
    DWORD dwProcId;
    GetWindowThreadProcessId(hWnd, &dwProcId);
    LPWNDINFO pInfo=(LPWNDINFO)lParam;
    if(dwProcId==pInfo->dwProcessId)
    {
        pInfo->hWnd = hWnd;
        return FALSE;
    }

    return TRUE;
}
HWND CGetHwnd::GetProcessMainWnd(DWORD dwProcessId)//获取给定进程ID的窗口handle
{
    WNDINFO wi;
    wi.dwProcessId = dwProcessId;
    wi.hWnd = NULL;
    EnumWindows(MyEnumProc,(LPARAM)&wi);

    return wi.hWnd;
}
