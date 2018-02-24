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
	m_scene_state = kStartAnim;

	m_player_count = 0;

	m_controller = new int*[5];
	for (int p = 0;p < 5;++p)
	{
		m_controller[p] = new int[2]{ -1,-1 };
	}
	m_occupied = new bool[4]{ false,false,false,false };
	m_lock = new bool[4]{ false,false,false,false };
	m_job = new int[4]{ 0,0,0,0 };
}

void CharaSelect::Update()
{
	switch (m_scene_state)
	{
	case kStartAnim:
		m_scene_state = kCharaSelect;
		break;
	case kCharaSelect:
		KbSelect();
		for (int index = 1;index <= 4;++index)
		{
			PadSelect(index);
		}
		CheckPlayerSet();
		break;
	case kNoFullCheck:
		PressToGo(kReturnSelectInfo, kCharaSelect);
		break;
	case kReturnSelectInfo:
		break;
	case kEndAnim:
		m_is_end = true;
		break;
	}
}

void CharaSelect::Draw()
{
	m_renderer->DrawString("CharaSelect", Math::Vector2(150, 0));
}

void CharaSelect::Shutdown()
{
	delete m_controller;
	delete m_occupied;
	delete m_lock;
	delete m_job;
}

int CharaSelect::MinIndex()
{
	for (int index = 0;index < 4;++index)
	{
		if (m_occupied[index] == false) return index;
	}
	return -1;
}

void CharaSelect::KbSelect()
{
	//join
	if (m_controller[0][0] == -1 && m_player_count < 4)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_controller[0][0] = 0;
			m_controller[0][1] = MinIndex();
			m_occupied[MinIndex()] = true;
			++m_player_count;
		}
	}
	//job select
	//i: controller num, controller[i]: player num
	if (m_controller[0][0] == 0)
	{
		int player_num = m_controller[0][1];
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
			m_controller[0][0] = 1;
			m_lock[player_num] = true;
		}
	}
	//lock
	if (m_controller[0][0] == 1)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_controller[0][0] = 0;
			m_lock[m_controller[0][1]] = false;
		}
	}
}

void CharaSelect::PadSelect(int pad_index)
{
	//join
	if (m_controller[pad_index][0] == -1 && m_player_count < 4)
	{
		if (m_input->IsPadButtonTrigger(pad_index, XINPUT_BUTTON_B))
		{
			m_controller[pad_index][0] = 0;
			m_controller[pad_index][1] = MinIndex();
			m_occupied[MinIndex()] = true;
			++m_player_count;
		}
	}
	//job select
	//i: controller num, controller[i]: player num
	if (m_controller[pad_index][0] == 0)
	{
		int player_num = m_controller[pad_index][1];
		if (m_input->IsPadButtonTrigger(pad_index, XINPUT_BUTTON_DPAD_RIGHT))
		{
			++m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(pad_index, XINPUT_BUTTON_DPAD_LEFT))
		{
			--m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(pad_index, XINPUT_BUTTON_B))
		{
			m_controller[pad_index][0] = 1;
			m_lock[player_num] = true;
		}
	}
	//lock
	if (m_controller[pad_index][0] == 1)
	{
		if (m_input->IsPadButtonTrigger(pad_index, XINPUT_BUTTON_A))
		{
			m_controller[pad_index][0] = 0;
			m_lock[m_controller[pad_index][1]] = false;
		}
	}
}

void CharaSelect::CheckPlayerSet()
{
	for (int p = 0;p < 4;++p)
	{
		if (m_lock[p] == false) return;
	}
	if (m_player_count == 4)
	{
		m_scene_state = kReturnSelectInfo;
		return;
	}
}

void CharaSelect::PressToGo(SceneState enter, SceneState cancel)
{
	if (m_controller[0] != 0 || m_input->IsKeyTrigger(KEY_INPUT_A))
	{
		m_scene_state = enter;
		return;
	}
	for (int i = 1;i < 5;++i)
	{
		if (m_controller[i] != 0 || m_input->IsPadButtonTrigger(i - 1, XINPUT_BUTTON_B))
		{
			m_scene_state = enter;
			return;
		}
	}
	if (m_controller[0] != 0 || m_input->IsKeyTrigger(KEY_INPUT_D))
	{
		m_scene_state = cancel;
		return;
	}
	for (int i = 1;i < 5;++i)
	{
		if (m_controller[i] != 0 || m_input->IsPadButtonTrigger(i - 1, XINPUT_BUTTON_A))
		{
			m_scene_state = cancel;
			return;
		}
	}
}