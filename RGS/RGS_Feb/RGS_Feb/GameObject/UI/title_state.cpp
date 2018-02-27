//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitleMenu��State
//-------------------------------------------------------
#include <GameObject\UI\title_state.h>

using namespace UI;

TitleState::TitleState()
{
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_input = Device::GameDevice::GetInstance()->GetInput();
	m_sound = Device::GameDevice::GetInstance()->GetSound();

	m_end_flag = false;
}

TitleState::TitleState(const TitleState&)
{
}

TitleState::~TitleState()
{
	m_renderer = NULL;
	m_input = NULL;
}

bool TitleState::IsEnd()
{
	return m_end_flag;
}

bool TitleState::TriggerKey(unsigned int key_input, unsigned char xinput_button)
{
	if (m_input->IsKeyTrigger(key_input))						//KeyBoard�`�F�b�N
	{
		return true;
	}
	for (int i = 0; i < 4; ++i)									//�l��Pad�`�F�b�N
	{
		if (m_input->IsPadButtonTrigger(i, xinput_button))
		{
			return true;
		}
	}
	return false;
}

bool TitleState::Enter()
{
	if (TriggerKey(KEY_INPUT_A, XINPUT_BUTTON_B)) 
	{
		m_sound->PlaySE("se_select");
		return true;
	}
	return false;
}

bool TitleState::Cancel()
{
	if (TriggerKey(KEY_INPUT_D, XINPUT_BUTTON_A)) 
	{
		m_sound->PlaySE("se_cancel");
		return true;
	}
	return false;
}

bool TitleState::Down()
{
	//For������񂾂��񂷂���TriggerKey�i�j�g��Ȃ�
	if (m_input->IsKeyTrigger(KEY_INPUT_DOWN))
	{
		return true;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_DPAD_DOWN))
		{
			return true;
		}
		if (m_input->IsPadStickTrigger(i, Math::Vector2(0, -0.7f)))
			return true;
	}
	return false;
}

bool TitleState::Up()
{
	//For������񂾂��񂷂���TriggerKey�i�j�g��Ȃ�
	if (m_input->IsKeyTrigger(KEY_INPUT_UP))
	{
		return true;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_DPAD_UP))
		{
			return true;
		}
		if (m_input->IsPadStickTrigger(i, Math::Vector2(0, 0.7f)))
			return true;
	}
	return false;
}