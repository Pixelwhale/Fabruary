//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.5
// 内容　：入力処理
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

		///	<summary>シャットダウン処理</summary>
		void ShutDown();
		///	<summary>更新処理</summary>
		void Update();

#pragma region KeyBoard

		///	<summary>指定のキーが押されているか</summary>
		/// <param name="dik_key">KEY_INPUT_指定のキー</param>
		bool IsKeyDown(unsigned int key_input);

		///	<summary>指定のキーがこのフレームで押されているか</summary>
		/// <param name="dik_key">KEY_INPUT_指定のキー</param>  
		bool IsKeyTrigger(unsigned int key_input);

		///	<summary>KeyboardのVelocityを取得</summary>
		Math::Vector3 GetKeyBoardVelocity();

#pragma endregion


#pragma region Pad

		///	<summary>パッドを接続している数</summary>
		int CurrentPadCount();

		///	<summary>指定のボタンが押されているか</summary>
		/// <param name="pad_num">Pad番号（0～3）</param>
		/// <param name="xinput_button">XINPUT_BUTTON_指定ボタン</param>
		bool IsPadButtonDown(int pad_num, unsigned char xinput_button);

		///	<summary>指定のボタンがこのフレームで押されているか</summary>
		/// <param name="pad_num">Pad番号（0～3）</param>
		/// <param name="xinput_button">XINPUT_BUTTON_指定ボタン</param>
		bool IsPadButtonTrigger(int pad_num, unsigned char xinput_button);

		///	<summary>Left Stickの倒し具合(ゲーム対応でX、Z軸にした)</summary>
		/// <param name="pad_num">Pad番号（0～3）</param>
		Math::Vector3 GetLeftStick(int pad_num);

		///	<summary>Left Stickが特定の方向にどれくらい変化したか</summary>
		/// <param name="pad_num">Pad番号（0～3）</param>
		/// <param name="dir_amount">前フレームとの方向差</param>
		bool IsPadStickTrigger(int pad_num, Math::Vector2 dir_amount);

#pragma endregion


	private:
		///	<summary>KeyStateを更新</summary>
		void UpdateKeyboard();

		///	<summary>PadStateを更新</summary>
		void UpdatePad();

	private:
		char m_current_keyboard_state[256];			//このフレームのKeyState
		char m_previous_keyboard_state[256];		//前フレームのKeyState

		XINPUT_STATE m_current_pad_state[4];		//このフレームのPadState
		XINPUT_STATE m_previous_pad_state[4];		//前フレームのPadState
	};
}