//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.05
// 内容　：入力処理
//-------------------------------------------------------
#pragma once
#include <DX\Include\dinput.h>

namespace Core
{
	class InputState
	{
	public:
		InputState();
		InputState(const InputState&);
		~InputState();

		///	<summary>初期化</summary>
		/// <param name="hInstance">Program実体のハンドル</param>  
		/// <param name="hwnd">Windowのハンドル</param> 
		/// <returns>true:成功、false:失敗</returns>
		bool Initialize(HINSTANCE hInstance, HWND hwnd);
		///	<summary>シャットダウン処理</summary>
		void ShutDown();
		///	<summary>更新処理</summary>
		bool Update();

		///	<summary>マウスの位置を取得</summary>
		/// <param name="mouseX">X座標</param>  
		/// <param name="mouseY">Y座標</param> 
		void MousePosition(int& mouse_x, int& mouse_y);

		///	<summary>指定のキーが押されているか</summary>
		/// <param name="dik_key">DirectInputKey:DIK_指定のキー</param>  
		bool IsKeyDown(unsigned int dik_key);
		///	<summary>指定のキーがこのフレームで押されているか</summary>
		/// <param name="dik_key">DirectInputKey:DIK_指定のキー</param>  
		bool IsKeyTrigger(unsigned int dik_key);

	private:
		///	<summary>KeyStateの更新</summary>
		/// <returns>true:成功、false:失敗</returns>
		bool ReadKeyboard();
		///	<summary>マウスの位置を更新</summary>
		/// <returns>true:成功、false:失敗</returns>
		bool ReadMouse();
		///	<summary>マウスの位置を画面内にClamp</summary>
		void ClampMousePosition();
		///	<summary>前フレームのKeyStateを更新</summary>
		void UpdateKeyboard();

	private:
		IDirectInput8* m_direct_input;				//Input Device
		IDirectInputDevice8* m_keyboard;			//Keyboard Device
		IDirectInputDevice8* m_mouse;				//Mouse Device

		unsigned char m_current_keyboard_state[256];		//このフレームのKeyState
		unsigned char m_previous_keyboard_state[256];		//前フレームのKeyState
		DIMOUSESTATE m_mouse_state;					//MouseState
		int m_mouse_x, m_mouse_y;						//Mouseの位置
	};
}