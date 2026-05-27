#pragma once
#include <atlbase.h>
#include <memory>

/// <summary>
/// 指定したウィンドウに新しい結果をポストメッセージとして送信する。
/// </summary>
/// <typeparam name="T">送信する結果データの型。</typeparam>
/// <param name="hWnd">メッセージを送信する対象のウィンドウのハンドル。</param>
/// <param name="msg">送信するメッセージの識別子。</param>
/// <param name="result">送信する結果データ。ムーブまたはコピーされる。</param>
/// <returns>メッセージの送信に成功した場合は true、失敗した場合は false を返す。</returns>
template<typename T>
bool PostNewResult(HWND hWnd, UINT msg, T&& result) {
    // resultをヒープに保存する。
    // std::forward を使っているのは、resultが右辺値参照であればムーブコンストラクタを呼び出し、左辺値参照であればコピーコンストラクタを呼び出すため。
    // std::remove_reference_t<T> を使っているのは、Tが参照型であっても、実際に保存するオブジェクトの型を取得するため。
    auto p = new std::remove_reference_t<T>(std::forward<T>(result));

    // PostMessageに失敗した場合は、ヒープに保存した値を解放する
    if (!PostMessage(hWnd, msg, 0, reinterpret_cast<LPARAM>(p))) {
        delete p;
        return false;
    }
    return true;
}

/// <summary>
/// PostNewResult()で作られたメッセージのLPARAMからポインタを取得し、std::unique_ptrとして返す。
/// </summary>
/// <typeparam name="T">取得するオブジェクトの型。</typeparam>
/// <param name="lParam">取得するオブジェクトのポインタ値が格納されたLPARAM値。</param>
/// <returns>lParamから取得したポインタを所有するstd::unique_ptr。</returns>
template<typename T>
std::unique_ptr<T> GetResultFromMessage(LPARAM lParam) {
    // ここで、lParamの中に入っているのはPostNewResultで作られたデータである。
    // 従って、ポインタの中身は new によって確保されたデータであるため、std::unique_ptrに入れることができる。
    return std::unique_ptr<T>(reinterpret_cast<T*>(lParam));
}
