#include "MainWindow.h"

CAppModule _Module;

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, PWSTR pCmdLine, int nCmdShow)
{
    // DPI認識を有効化
    SetProcessDpiAwarenessContext(DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2);

    // アプリケーションモジュールの初期化
    _Module.Init(NULL, hInstance);

    // メッセージループオブジェクトを作成して登録
    CMessageLoop theLoop;
    _Module.AddMessageLoop(&theLoop);

    // ウインドウを作成して表示
    CMainWindow wnd;
    wnd.Create(NULL, CWindow::rcDefault, L"はろはろ～",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE);
    wnd.ShowWindow(nCmdShow);
    wnd.UpdateWindow();

    // メッセージループを開始
    int nRet = theLoop.Run();

    // 後片付け
    _Module.RemoveMessageLoop();
    _Module.Term();

    return nRet;
}
