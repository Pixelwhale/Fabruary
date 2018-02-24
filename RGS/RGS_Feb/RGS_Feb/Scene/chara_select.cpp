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

CharaSelect::CharaSelect(std::shared_ptr<GameManager> game_mgr)
{
	m_game_mgr = game_mgr;
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
	case kCountToGo:
		timer.Update();
		if (timer.IsTime()) m_scene_state = kReturnSelectInfo;
		if (m_controller[0][0] != 1 || m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_scene_state = kCharaSelect;
			m_controller[0][0] = 0;
			m_lock[m_controller[0][0]] = false;
			return;
		}
		for (int i = 1;i <= 4;++i)
		{
			if (m_controller[i][0] != 1 || m_input->IsPadButtonTrigger(i - 1, XINPUT_BUTTON_A))
			{
				m_scene_state = kCharaSelect;
				m_controller[i][0] = 0;
				m_lock[m_controller[i][0]] = false;
				return;
			}
		}
		break;
	case kReturnSelectInfo:
		AddChara();
		m_scene_state = kEndAnim;
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
		if (m_input->IsPadButtonTrigger(pad_index - 1, XINPUT_BUTTON_B))
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
		if (m_input->IsPadButtonTrigger(pad_index - 1, XINPUT_BUTTON_DPAD_RIGHT))
		{
			++m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(pad_index - 1, XINPUT_BUTTON_DPAD_LEFT))
		{
			--m_job[player_num];
		}
		if (m_input->IsPadButtonTrigger(pad_index - 1, XINPUT_BUTTON_B))
		{
			m_controller[pad_index][0] = 1;
			m_lock[player_num] = true;
		}
	}
	//lock
	if (m_controller[pad_index][0] == 1)
	{
		if (m_input->IsPadButtonTrigger(pad_index - 1, XINPUT_BUTTON_A))
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
	m_scene_state = kReturnSelectInfo;
	timer = Utility::Timer(3.0f);
	return;
}

void CharaSelect::AddChara()
{
	for (int p = 0;p < m_player_count;++p)
	{
		Side side;
		switch (p)
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
		switch (m_job[0])
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
		for (int i = 0;i < 5;++i)
		{
			if (m_controller[i][1] == p && i == 0)
			{
				v_controller = make_shared<Character::KeyboardController>(p + 1);
			}
		}
		m_game_mgr->AddSelectCharacter(job, side, v_controller);
	}
	for (int p = m_player_count;p < 4;++p)
	{
		Side side;
		switch (p)
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
		switch (m_job[0])
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
		m_game_mgr->AddSelectAI(job, side, p, 5);
	}
}