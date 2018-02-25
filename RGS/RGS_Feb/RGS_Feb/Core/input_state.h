//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.5
// ���e�@�F���͏���
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Math\vector3.h>
#include <Math\vector2.h>

namespace Core
{
	class InputState
	{
	public:
		InputState();
		InputState(const InputState&);
		~InputState();

		///	<summary>�V���b�g�_�E������</summary>
		void ShutDown();
		///	<summary>�X�V����</summary>
		void Update();

#pragma region KeyBoard

		///	<summary>�w��̃L�[��������Ă��邩</summary>
		/// <param name="dik_key">KEY_INPUT_�w��̃L�[</param>
		bool IsKeyDown(unsigned int key_input);

		///	<summary>�w��̃L�[�����̃t���[���ŉ�����Ă��邩</summary>
		/// <param name="dik_key">KEY_INPUT_�w��̃L�[</param>  
		bool IsKeyTrigger(unsigned int key_input);

		///	<summary>Keyboard��Velocity���擾</summary>
		Math::Vector3 GetKeyBoardVelocity();

#pragma endregion


#pragma region Pad

		///	<summary>�p�b�h��ڑ����Ă��鐔</summary>
		int CurrentPadCount();

		///	<summary>�w��̃{�^����������Ă��邩</summary>
		/// <param name="pad_num">Pad�ԍ��i0�`3�j</param>
		/// <param name="xinput_button">XINPUT_BUTTON_�w��{�^��</param>
		bool IsPadButtonDown(int pad_num, unsigned char xinput_button);

		///	<summary>�w��̃{�^�������̃t���[���ŉ�����Ă��邩</summary>
		/// <param name="pad_num">Pad�ԍ��i0�`3�j</param>
		/// <param name="xinput_button">XINPUT_BUTTON_�w��{�^��</param>
		bool IsPadButtonTrigger(int pad_num, unsigned char xinput_button);

		///	<summary>Left Stick�̓|���(�Q�[���Ή���X�AZ���ɂ���)</summary>
		/// <param name="pad_num">Pad�ԍ��i0�`3�j</param>
		Math::Vector3 GetLeftStick(int pad_num);

		///	<summary>Left Stick������̕����ɂǂꂭ�炢�ω�������</summary>
		/// <param name="pad_num">Pad�ԍ��i0�`3�j</param>
		/// <param name="dir_amount">�O�t���[���Ƃ̕�����</param>
		bool IsPadStickTrigger(int pad_num, Math::Vector2 dir_amount);

#pragma endregion


	private:
		///	<summary>KeyState���X�V</summary>
		void UpdateKeyboard();

		///	<summary>PadState���X�V</summary>
		void UpdatePad();

	private:
		char m_current_keyboard_state[256];			//���̃t���[����KeyState
		char m_previous_keyboard_state[256];		//�O�t���[����KeyState

		XINPUT_STATE m_current_pad_state[4];		//���̃t���[����PadState
		XINPUT_STATE m_previous_pad_state[4];		//�O�t���[����PadState
	};
}