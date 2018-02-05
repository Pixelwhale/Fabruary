//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�F���͏���
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

//�V���b�g�_�E������
void InputState::ShutDown()
{
}

//�X�V����
void InputState::Update()
{
	UpdateKeyboard();				//KeyboardState�X�V
}

//Keyboard�X�V
void InputState::UpdateKeyboard()
{
	for (int i = 0; i < sizeof(m_current_keyboard_state); i++)
	{
		m_previous_keyboard_state[i] = m_current_keyboard_state[i];
	}

	GetHitKeyStateAll(m_current_keyboard_state);
}

//�w��̃L�[��������Ă��邩
bool InputState::IsKeyDown(unsigned int key_input)
{
	return m_current_keyboard_state[key_input] == 1;
}

//�w��̃L�[�����̃t���[���ŉ�����Ă��邩
bool InputState::IsKeyTrigger(unsigned int key_input)
{
	return (m_previous_keyboard_state[key_input] != 1 && IsKeyDown(key_input));
}