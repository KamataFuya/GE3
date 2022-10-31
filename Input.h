#pragma once
#include <windows.h>
#include <wrl.h>
#define DIRECTINPUT_VERSION     0x0800   // DirectInput�̃o�[�W�����w��
#include <dinput.h>

#include "WinApp.h"

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
	void Initialize(WinApp* winApp);

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
	//WindowsAPI�̃|�C���^
	WinApp* winApp_ = nullptr;
	//�L�[�{�[�h�f�o�C�X�̐���
	ComPtr<IDirectInputDevice8> keyboard;
	//DirectInput�̃C���X�^���X
	ComPtr<IDirectInput8> directInput;
	//���݂̓��͏��
	BYTE key[256] = {};
	//�O��̓��͏��
	BYTE keyPre[256] = {};
};

