//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.05
// ���e�@�F���͏���
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>

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

		///	<summary>�w��̃L�[��������Ă��邩</summary>
		/// <param name="dik_key">KEY_INPUT_�w��̃L�[</param>  
		bool IsKeyDown(unsigned int key_input);
		///	<summary>�w��̃L�[�����̃t���[���ŉ�����Ă��邩</summary>
		/// <param name="dik_key">KEY_INPUT_�w��̃L�[</param>  
		bool IsKeyTrigger(unsigned int key_input);

	private:
		///	<summary>�O�t���[����KeyState���X�V</summary>
		void UpdateKeyboard();

	private:
		char m_current_keyboard_state[256];		//���̃t���[����KeyState
		char m_previous_keyboard_state[256];		//�O�t���[����KeyState
	};
}