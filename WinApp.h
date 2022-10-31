#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
public://静的メンバ関数
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize();

	//Getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

public://定数
	//ウィンドウ横幅
	static const int window_width = 1280;
	//ウィンドウ縦幅
	static const int window_height = 720;

private://メンバ変数
	//ウィンドウハンドル
	HWND hwnd = nullptr;
	//ウィンドウクラスの設定
	WNDCLASSEX w{};
};

