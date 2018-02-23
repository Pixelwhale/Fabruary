//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2018.02.22
//-------------------------------------------------------
#include "chara_select.h"

using namespace Scene;

CharaSelect::CharaSelect()
{
}

void CharaSelect::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);
	m_state = kStartAnim;
	for (int i : m_controller) i = 0;
	m_player_count = 0;
	for (bool e : m_enter) e = false;
	for (int j : m_job) j = 0;
}

void CharaSelect::Update()
{
	switch (m_state)
	{
	case kStartAnim:
		break;
	case kCharaSelect:
		KbSelect();
		for (int index = 1;index <= m_input->CurrentPadCount();++index)
		{
			PadSelect(index);
		}
		CheckPlayerSet();
		break;
	case kPlayerSetCheck:
		break;
	case kReturnSelectInfo:
		break;
	case kEndAnim:
		break;
	}
}

void CharaSelect::Draw()
{
	m_renderer->DrawString("CharaSelect", Math::Vector2(150, 0));
}

void CharaSelect::Shutdown()
{
}

int CharaSelect::MinIndex()
{
	int index;
	for (index = 1;index <= 4;++index)
	{
		for (int i = 0;i < 5;++i)
		{
			if (index == m_controller[i]) continue;
		}
		break;
	}
	return index;
}

void CharaSelect::KbSelect()
{
	//join
	if (m_player_count < 4)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_A) && m_controller[0] == 0)
		{
			m_controller[0] = MinIndex();
			++m_player_count;
		}
	}
	//quit
	if (m_player_count > 0)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_D) && m_controller[0] != 0)
		{
			m_controller[0] = 0;
			--m_player_count;
		}
	}
	//job select
	//i: controller num, controller[i]: player num
	int player_num = m_controller[0];
	if (player_num == 0) return;
	if (m_enter[player_num] == false)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_RIGHT))
		{
			++m_job[player_num];
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_LEFT))
		{
			--m_job[player_num];
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_enter[player_num] = true;
		}
	}
}

void CharaSelect::PadSelect(int index)
{
	//join
	if (m_player_count < 4)
	{
		if (m_input->IsPadButtonTrigger(index, XINPUT_BUTTON_B) && m_controller[index] == 0)
		{
			m_controller[index] = MinIndex();
			++m_player_count;
		}
	}
	//quit
	if (m_player_count > 0)
	{
		if (m_input->IsPadButtonTrigger(0, XINPUT_BUTTON_A) && m_controller[index] != 0)
		{
			m_controller[index] = 0;
			--m_player_count;
		}
	}
	//job select
	//i: controller num, controller[i]: player num
	int player_num = m_controller[index];
	if (player_num == 0) return;
	if (m_enter[player_num] == false)
	{
		if (m_input->IsPadButtonTrigger(index - 1, XINPUT_BUTTON_DPAD_RIGHT))
		{
			++m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(index - 1, XINPUT_BUTTON_DPAD_LEFT))
		{
			--m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(index - 1, XINPUT_BUTTON_B))
		{
			m_enter[player_num] = true;
		}
	}
}

void CharaSelect::CheckPlayerSet()
{
	for (bool e : m_enter)
	{
		if (e == false) return;
	}
	if (m_player_count == 4)
	{
		m_state = kReturnSelectInfo;
		return;
	}
	else
	{
		if (m_controller[0] != 0 || m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_state = kPlayerSetCheck;
			return;
		}
		for (int i = 1;i < 5;++i)
		{
			if (m_controller[i] != 0 || m_input->IsPadButtonTrigger(i - 1, XINPUT_BUTTON_B))
			{
				m_state = kPlayerSetCheck;
				return;
			}
		}
	}
}