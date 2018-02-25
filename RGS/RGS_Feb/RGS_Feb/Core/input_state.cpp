//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.5
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

	UpdatePad();					//PadState�X�V
}

#pragma region KeyBoard

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

//Keyboard��Velocity���擾
Math::Vector3 InputState::GetKeyBoardVelocity() 
{
	Math::Vector3 velocity = Math::Vector3();
	if (IsKeyDown(KEY_INPUT_UP))
		velocity.z += 1;
	if(IsKeyDown(KEY_INPUT_DOWN))
		velocity.z -= 1;
	if (IsKeyDown(KEY_INPUT_RIGHT))
		velocity.x += 1;
	if (IsKeyDown(KEY_INPUT_LEFT))
		velocity.x -= 1;

	return velocity;
}

#pragma endregion

#pragma region Pad

//PadState�X�V
void InputState::UpdatePad() 
{
#pragma region ���p�b�hState�X�V
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 16; j++) 
		{
			m_previous_pad_state[i].Buttons[j] = m_current_pad_state[i].Buttons[j];
		}
		m_previous_pad_state[i].LeftTrigger = m_current_pad_state[i].LeftTrigger;
		m_previous_pad_state[i].RightTrigger = m_current_pad_state[i].RightTrigger;
		m_previous_pad_state[i].ThumbLX = m_current_pad_state[i].ThumbLX;
		m_previous_pad_state[i].ThumbLY = m_current_pad_state[i].ThumbLY;
		m_previous_pad_state[i].ThumbRX = m_current_pad_state[i].ThumbRX;
		m_previous_pad_state[i].ThumbRY = m_current_pad_state[i].ThumbRY;
	}
#pragma endregion

#pragma region ����Frame�̃p�b�hState�X�V
	GetJoypadXInputState(DX_INPUT_PAD1, &m_current_pad_state[0]);
	GetJoypadXInputState(DX_INPUT_PAD2, &m_current_pad_state[1]);
	GetJoypadXInputState(DX_INPUT_PAD3, &m_current_pad_state[2]);
	GetJoypadXInputState(DX_INPUT_PAD4, &m_current_pad_state[3]);
#pragma endregion
}

//���ݐڑ����Ă���p�b�h��
int InputState::CurrentPadCount() 
{
	return GetJoypadNum();
}

//�w��̃p�b�h�̃{�^����������Ă��邩
bool InputState::IsPadButtonDown(int pad_num, unsigned char xinput_button) 
{
	return m_current_pad_state[pad_num].Buttons[xinput_button] == 1;
}

//�w��̃{�^�������̃t���[���ŉ�����Ă��邩
bool InputState::IsPadButtonTrigger(int pad_num, unsigned char xinput_button) 
{
	return m_previous_pad_state[pad_num].Buttons[xinput_button] == 0 && IsPadButtonDown(pad_num, xinput_button);
}

//Left Stick�̓|���
Math::Vector3 InputState::GetLeftStick(int pad_num) 
{
	float x = m_current_pad_state[pad_num].ThumbLX / 32767.0f;
	float y = m_current_pad_state[pad_num].ThumbLY / 32767.0f;

	if (x > 0 && x < 0.3f ||
		x < 0 && x > -0.3f)
		x = 0;

	if (y > 0 && y < 0.3f ||
		y < 0 && y > -0.3f)
		y = 0;

	return Math::Vector3(x, 0, y);
}

bool InputState::IsPadStickTrigger(int pad_num, Math::Vector2 dir_amount) 
{
	float current_x = m_current_pad_state[pad_num].ThumbLX / 32767.0f;
	float current_y = m_current_pad_state[pad_num].ThumbLY / 32767.0f;
	float previous_x = m_previous_pad_state[pad_num].ThumbLX / 32767.0f;
	float previous_y = m_previous_pad_state[pad_num].ThumbLY / 32767.0f;

	float diff_x = current_x - previous_x;
	float diff_y = current_y - previous_y;

	if (dir_amount.x > 0 && diff_x > dir_amount.x)
		return true;
	if (dir_amount.y > 0 && diff_y > dir_amount.y)
		return true;

	if (dir_amount.x < 0 && diff_x < dir_amount.x)
		return true;
	if (dir_amount.y < 0 && diff_y < dir_amount.y)
		return true;

	return false;
}

#pragma endregion
