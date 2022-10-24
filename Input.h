#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInputのバージョン指定
#include <dinput.h>

//ヘッダーファイル内にusing namespaceを入れるのはNG。using namespaceが全体に広がってしまうため

class Input
{
public:
	//using namespaceの代わり
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //メンバ関数
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(HINSTANCE hInstance, HWND hwnd);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 入力
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// トリガー処理
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

private: //メンバ変数
	//キーボードデバイスの生成
	ComPtr<IDirectInputDevice8> keyboard;
	//DirectInputのインスタンス
	ComPtr<IDirectInput8> directInput;
	//現在の入力情報
	BYTE key[256] = {};
	//前回の入力情報
	BYTE keyPre[256] = {};
};

