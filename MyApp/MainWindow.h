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
    BEGIN_MSG_MAP_EX(CMainWindow)
        MSG_WM_PAINT(OnPaint)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_DESTROY(OnDestroy)
    END_MSG_MAP()

private:
    LRESULT OnCreate(LPCREATESTRUCT lpCreateStruct)
    {
        return 0;
    }

    LRESULT OnPaint(CDCHandle /*dc*/)
    {
        CPaintDC dc(m_hWnd);

        // 描画コードをここに記述

        return 0;
    }

    void OnDestroy()
    {
        PostQuitMessage(0);
    }
};
