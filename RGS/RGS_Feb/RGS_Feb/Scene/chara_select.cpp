//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2018.02.22
//-------------------------------------------------------
#include "chara_select.h"
#include <GameObject\Job\planner.h>
#include <GameObject\Job\business.h>
#include <GameObject\Job\com_graphic.h>
#include <GameObject\Job\programmer.h>
#include <Character\Controller\keyboard_controller.h>
#include <Character\Controller\pad_controller.h>
#include <Character\Controller\ai_controller.h>

using namespace Scene;
using namespace Job;
using namespace Math;

CharaSelect::CharaSelect(std::shared_ptr<GameManager> game_mgr)
{
	m_game_mgr = game_mgr;
}

void CharaSelect::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);
	m_scene_state = kStartAnim;
	m_player = new Player[4];
	for (int i = 0;i < 5;++i)
	{
		m_controller[i] = false;
	}
}

void CharaSelect::Update()
{
	switch (m_scene_state)
	{
	case kStartAnim:
		m_scene_state = kJobSelect;
		break;
	case kJobSelect:
		//check 1P~4P
		for (int player_num = 0; player_num < 4; ++player_num)
		{
			JobSelect(player_num);
		}
		//check if join
		CheckJoin();
		//check all lock
		if (CheckAllLock())
		{
			m_scene_state = kCountToGo;
			timer = Utility::Timer(3.0f);
			timer.Reset();
		}
		break;
	case kCountToGo:
		timer.Update();
		if (timer.IsTime()) m_scene_state = kReturnSelectInfo;
		//join
		if (CheckJoin())
		{
			m_scene_state = kJobSelect;
		}
		//lockÇµÇΩêlÇ™unlockÇ∑ÇÈ
		for (int player_num = 0; player_num < 4; ++player_num)
		{
			if (m_player[player_num].lock == true)
			{
				if (m_player[player_num].controller_num == 4)
				{
					if (CheckKbUnlock(player_num)) m_scene_state = kJobSelect;
				}
				else if (CheckPadUnlock(player_num, m_player[player_num].controller_num))
					m_scene_state = kJobSelect;
			}
		}
		break;
	case kReturnSelectInfo:
		AddChara();
		m_scene_state = kEndAnim;
		break;
	case kEndAnim:
		m_is_end = true;
		m_next = kGamePlay;
		break;
	}
}

void CharaSelect::Draw()
{
	m_renderer->DrawString("CharaSelect", Vector2(0, 0));

	for (int p = 0;p < 4;++p)
	{
		m_renderer->DrawString("player" + std::to_string(p + 1), Vector2(40, 40 + 40 * p));
		m_renderer->DrawString(std::to_string(m_player[p].controller_num), Vector2(120, 40 + 40 * p));
		m_renderer->DrawString(std::to_string(m_player[p].job), Vector2(160, 40 + 40 * p));
		m_renderer->DrawString(std::to_string(m_player[p].lock), Vector2(200, 40 + 40 * p));
		m_renderer->DrawString(std::to_string(m_player[p].occupied), Vector2(240, 40 + 40 * p));
	}

	m_renderer->DrawString(std::to_string(m_scene_state), Vector2(40, 200));
}

void CharaSelect::Shutdown()
{
	delete[] m_player;
}

int CharaSelect::MinIndex()
{
	for (int i = 0;i < 4;++i)
	{
		if (m_player[i].occupied == false) return i;
	}
	return -1;
}
bool CharaSelect::CheckJoin()
{
	int index = MinIndex();
	if (index == -1) return false;
	if (m_controller[4] == false && m_input->IsKeyTrigger(KEY_INPUT_A))
	{
		m_player[index].controller_num = 4;
		m_player[index].occupied = true;
		m_controller[4] = true;
		return true;
	}
	for (int pad_num = 0; pad_num < 3; ++pad_num)
	{
		if (m_controller[pad_num] == true) continue;
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_B))
		{
			m_player[index].controller_num = pad_num;
			m_player[index].occupied = true;
			m_controller[index] = true;
			return true;
		}
	}
	return false;
}

void CharaSelect::JobSelect(int player_num)
{

	if (m_player[player_num].controller_num == -1) return;
	else if (m_player[player_num].controller_num == 4)
	{
		KbSelect(player_num);
	}
	else
	{
		PadSelect(player_num, m_player[player_num].controller_num);
	}
}
void CharaSelect::KbSelect(int player_num)
{
	if (m_player[player_num].lock == false)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_player[player_num].controller_num = -1;
			m_player[player_num].occupied = false;
			m_controller[4] = false;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_RIGHT))
		{
			++m_player[player_num].job;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_LEFT))
		{
			--m_player[player_num].job;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_player[player_num].lock = true;
		}
	}
	else CheckKbUnlock(player_num);
}
bool CharaSelect::CheckKbUnlock(int player_num)
{
	if (m_player[player_num].lock == true && m_input->IsKeyTrigger(KEY_INPUT_D))
	{
		m_player[player_num].lock = false;
		return true;
	}
	return false;
}
void CharaSelect::PadSelect(int player_num, int pad_num)
{
	if (m_player[player_num].lock == false)
	{
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_A))
		{
			m_player[player_num].controller_num = -1;
			m_player[player_num].occupied = false;
			m_controller[pad_num] = false;
		}
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_DPAD_RIGHT))
		{
			++m_player[player_num].job;
		}
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_DPAD_LEFT))
		{
			--m_player[player_num].job;
		}
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_B))
		{
			m_player[player_num].lock = true;
		}
	}
	else CheckPadUnlock(player_num, pad_num);
}
bool CharaSelect::CheckPadUnlock(int player_num, int pad_num)
{
	if (m_player[player_num].lock == true && m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_A))
	{
		m_player[player_num].lock = false;
		return true;
	}
	return false;
}

bool CharaSelect::CheckAllLock()
{
	int player_count = 0;
	for (int player_num = 0; player_num < 4; ++player_num)
	{
		if (!m_player[player_num].occupied) continue;
		++player_count;
		if (!m_player[player_num].lock) return false;
	}
	if (player_count == 0) return false;
	return true;
}

void CharaSelect::AddChara()
{
	for (int player_num = 0; player_num < 4; ++player_num)
	{
		Side side;
		switch (player_num)
		{
		case 0:
			side = kTeam1;
		case 1:
			side = kTeam2;
		case 2:
			side = kTeam3;
		case 3:
			side = kTeam4;
		}
		std::shared_ptr<JobBase> job;
		switch (m_player[player_num].job % 4)
		{
		case 0:
			job = make_shared<Planner>(side);
			break;
		case 1:
			job = make_shared<Business>(side);
			break;
		case 2:
			job = make_shared<ComputerGraphic>(side);
			break;
		case 3:
			job = make_shared<Programmer>(side);
			break;
		}
		shared_ptr<Character::VirtualController> v_controller;
		switch (m_player[player_num].controller_num)
		{
		case 4:
			v_controller = make_shared<Character::KeyboardController>(player_num + 1);
			m_game_mgr->AddSelectCharacter(job, side, v_controller);
			break;
		case -1:
			v_controller = make_shared < Character::AiController>(player_num + 1);
			m_game_mgr->AddSelectAI(job, side, v_controller, 5);
			break;
		default:
			v_controller = make_shared<Character::PadController>(m_player[player_num].controller_num, player_num + 1);
			m_game_mgr->AddSelectCharacter(job, side, v_controller);
			break;
		}
	}
}
