#pragma once
#include <Windows.h>

//WindowsAPI
class WinApp
{
public://�ÓI�����o�֐�
	static LRESULT WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

public://�����o�֐�

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �I��
	/// </summary>
	void Finalize();

	//Getter
	HWND GetHwnd() const { return hwnd; }
	HINSTANCE GetHInstance() const { return w.hInstance; }

public://�萔
	//�E�B���h�E����
	static const int window_width = 1280;
	//�E�B���h�E�c��
	static const int window_height = 720;

private://�����o�ϐ�
	//�E�B���h�E�n���h��
	HWND hwnd = nullptr;
	//�E�B���h�E�N���X�̐ݒ�
	WNDCLASSEX w{};
};

