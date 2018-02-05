//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.05
// 内容　：入力処理
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

		///	<summary>シャットダウン処理</summary>
		void ShutDown();
		///	<summary>更新処理</summary>
		void Update();

		///	<summary>指定のキーが押されているか</summary>
		/// <param name="dik_key">KEY_INPUT_指定のキー</param>  
		bool IsKeyDown(unsigned int key_input);
		///	<summary>指定のキーがこのフレームで押されているか</summary>
		/// <param name="dik_key">KEY_INPUT_指定のキー</param>  
		bool IsKeyTrigger(unsigned int key_input);

	private:
		///	<summary>前フレームのKeyStateを更新</summary>
		void UpdateKeyboard();

	private:
		char m_current_keyboard_state[256];		//このフレームのKeyState
		char m_previous_keyboard_state[256];		//前フレームのKeyState
	};
}