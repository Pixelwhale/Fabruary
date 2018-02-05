//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：入力処理
//-------------------------------------------------------
#include <Core\input_state.h>
#include <Def\window_def.h>

using namespace Core;

InputState::InputState()
{
	m_direct_input = 0;
	m_keyboard = 0;
	m_mouse = 0;
}

InputState::InputState(const InputState&)
{
}

InputState::~InputState()
{
}

//初期化
bool InputState::Initialize(HINSTANCE hInstance, HWND hwnd)
{
	HRESULT result;

	m_mouse_x = 0;
	m_mouse_y = 0;

	result = DirectInput8Create(					//Initialize input（デバイスの生成はこの後）
								hInstance,
								DIRECTINPUT_VERSION, IID_IDirectInput8,
								(void**)&m_direct_input, NULL);
	if (FAILED(result))
		return false;

	result = m_direct_input->CreateDevice(GUID_SysKeyboard, &m_keyboard, NULL);			//キーボードデバイスを生成
	if (FAILED(result))
		return false;

	result = m_keyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(result))
		return false;

	result = m_keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);	//EXCLUSIVE(他のWindowに入力の影響が出ない)
	if (FAILED(result))
		return false;

	result = m_keyboard->Acquire();
	if (FAILED(result))
		return false;

	result = m_direct_input->CreateDevice(GUID_SysMouse, &m_mouse, NULL);				//マウスデバイスを生成
	if (FAILED(result))
		return false;

	result = m_mouse->SetDataFormat(&c_dfDIMouse);
	if (FAILED(result))
		return false;

	result = m_mouse->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);	//NONEXCLUSIVE(Windowを出ているか確認用)
	if (FAILED(result))
		return false;

	result = m_mouse->Acquire();
	if (FAILED(result))
		return false;

	return true;
}

//シャットダウン処理
void InputState::ShutDown()
{
	if (m_mouse)				//マウスを解放
	{
		m_mouse->Unacquire();
		m_mouse->Release();
		m_mouse = 0;
	}

	if (m_keyboard)				//キーボードを解放
	{
		m_keyboard->Unacquire();
		m_keyboard->Release();
		m_keyboard = 0;
	}

	if (m_direct_input)			//Inputを解放
	{
		m_direct_input->Release();
		m_direct_input = 0;
	}
}

//更新処理
bool InputState::Update()
{
	bool result;

	UpdateKeyboard();				//前フレームのKeyboardState更新
	result = ReadKeyboard();		//このフレームのKeyboardState更新
	if (!result)
		return false;

	result = ReadMouse();			//MouseState更新
	if (!result)
		return false;
	ClampMousePosition();			//Mouseの位置を画面内に

	return true;
}

//このフレームのKeyState更新
bool InputState::ReadKeyboard()
{
	HRESULT result = m_keyboard->GetDeviceState(sizeof(m_current_keyboard_state), (LPVOID)&m_current_keyboard_state);

	if (result == DI_OK)		//Keyboard取得できたらTrue
	{
		return true;
	}

	//他のWindowがメインなどの場合は取得を試みる
	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;				//その他の場合
}

//このフレームのMouseState更新
bool InputState::ReadMouse()
{
	HRESULT result = m_mouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&m_mouse_state);

	if (result == DI_OK)		//Mouse取得できたらTrue
	{
		return true;
	}

	//他のWindowがメインなどの場合は取得を試みる
	if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED)
	{
		m_keyboard->Acquire();
		return true;
	}

	return false;			//その他の場合
}

//前フレームのKeyboard更新
void InputState::UpdateKeyboard()
{
	for (int i = 0; i < sizeof(m_current_keyboard_state); i++)
	{
		m_previous_keyboard_state[i] = m_current_keyboard_state[i];
	}
}

//マウスの位置を画面内にClamp
void InputState::ClampMousePosition()
{
	m_mouse_x += m_mouse_state.lX;
	m_mouse_y += m_mouse_state.lY;

	if (m_mouse_x < 0)
		m_mouse_x = 0;
	if (m_mouse_y < 0)
		m_mouse_y = 0;

	if (m_mouse_x > WindowDef::kScreenWidth)
		m_mouse_x = WindowDef::kScreenWidth;
	if (m_mouse_y > WindowDef::kScreenHeight)
		m_mouse_y = WindowDef::kScreenHeight;
}

//マウスの位置
void InputState::MousePosition(int& mouse_x, int& mouse_y)
{
	mouse_x = m_mouse_x;
	mouse_y = m_mouse_y;
}

//指定のキーが押されているか
bool InputState::IsKeyDown(unsigned int dik_key)
{
	return (m_current_keyboard_state[dik_key] & 0x80) != 0;
}

//指定のキーがこのフレームで押されているか
bool InputState::IsKeyTrigger(unsigned int dik_key)
{
	return (m_previous_keyboard_state[dik_key] & 0x80) == 0 && IsKeyDown(dik_key);
}