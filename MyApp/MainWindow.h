#pragma once

#include <atlbase.h>
#include <atlapp.h>
#include <atlwin.h>
#include <atlcrack.h>


extern CAppModule _Module;

class CMainWindow : public CWindowImpl<CMainWindow>
{
public:
    DECLARE_WND_CLASS(L"MyMainWindowClass")
private:
    BEGIN_MSG_MAP_EX(CMainWindow)
        MSG_WM_PAINT(OnPaint)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_DESTROY(OnDestroy)
    END_MSG_MAP()

    LRESULT OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        return 0;
    }

    LRESULT OnPaint(HDC hdc)
    {
        return 0;
    }

    LRESULT OnDestroy()
    {
        PostQuitMessage(0);
        return 0;
    }
};