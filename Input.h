#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

//�w�b�_�[�t�@�C������using namespace������̂�NG�Busing namespace���S�̂ɍL�����Ă��܂�����

class Input
{
public:
	//using namespace�̑���
	template <class T> using ComPtr = Microsoft::WRL::ComPtr<T>;

public: //�����o�֐�
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(HINSTANCE hInstance, HWND hwnd);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// ����
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool PushKey(BYTE keyNumber);

	/// <summary>
	/// �g���K�[����
	/// </summary>
	/// <param name="keyNumber"></param>
	/// <returns></returns>
	bool TriggerKey(BYTE keyNumber);

private: //�����o�ϐ�
	//�L�[�{�[�h�f�o�C�X�̐���
	ComPtr<IDirectInputDevice8> keyboard;
	//DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> directInput;
	//���݂̓��͏��
	BYTE key[256] = {};
	//�O��̓��͏��
	BYTE keyPre[256] = {};
};

