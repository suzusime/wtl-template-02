#pragma once

#include <atlbase.h>
#include <atlapp.h>
#include <atlwin.h>
#include <atlcrack.h>

#include "resource.h"
#include "wtlhelper.h"

extern CAppModule _Module;

class CMainDlg : public CDialogImpl<CMainDlg>
{
public:
    enum { IDD = IDD_MAINDLG };
    BEGIN_MSG_MAP_EX(CMainDlg)
        MSG_WM_INITDIALOG(OnInitDialog)
        MSG_WM_PAINT(OnPaint)
        MSG_WM_CLOSE(OnClose)
        MSG_WM_DESTROY(OnDestroy)
    END_MSG_MAP()

private:
    BOOL OnInitDialog(CWindow /*wndFocus*/, LPARAM /*lInitParam*/)
    {
        // 初期化コードをここに記述

        return TRUE;
    }

    LRESULT OnPaint(CDCHandle /*dc*/)
    {
        CPaintDC dc(m_hWnd);

        // 描画コードをここに記述

        return 0;
    }

    void OnClose()
    {
        // モードレスダイアログの場合は DestroyWindow() を呼び出す
        DestroyWindow();
        // モーダルダイアログの場合は EndDialog() を呼び出す
        // EndDialog(IDCANCEL);
    }

    void OnDestroy()
    {
        PostQuitMessage(0);
    }
};
