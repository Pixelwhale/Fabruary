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
}

InputState::InputState(const InputState&)
{
}

InputState::~InputState()
{
}

//シャットダウン処理
void InputState::ShutDown()
{
}

//更新処理
void InputState::Update()
{
	UpdateKeyboard();				//KeyboardState更新
}

//Keyboard更新
void InputState::UpdateKeyboard()
{
	for (int i = 0; i < sizeof(m_current_keyboard_state); i++)
	{
		m_previous_keyboard_state[i] = m_current_keyboard_state[i];
	}

	GetHitKeyStateAll(m_current_keyboard_state);
}

//指定のキーが押されているか
bool InputState::IsKeyDown(unsigned int key_input)
{
	return m_current_keyboard_state[key_input] == 1;
}

//指定のキーがこのフレームで押されているか
bool InputState::IsKeyTrigger(unsigned int key_input)
{
	return (m_previous_keyboard_state[key_input] != 1 && IsKeyDown(key_input));
}