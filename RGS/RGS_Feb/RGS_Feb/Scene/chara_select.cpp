//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.22
//-------------------------------------------------------
#include "chara_select.h"
#include <GameObject\Job\planner.h>
#include <GameObject\Job\business.h>
#include <GameObject\Job\com_graphic.h>
#include <GameObject\Job\programmer.h>
#include <Character\Controller\keyboard_controller.h>
#include <Character\Controller\pad_controller.h>
#include <Character\Controller\ai_controller.h>
#include <Def\window_def.h>
#include <Def\character_color.h>
#include <Device\game_device.h>

using namespace Scene;
using namespace Job;
using namespace Math;

CharaSelect::CharaSelect(std::shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect, std::shared_ptr<GameManager> game_mgr)
	: m_background(background), m_scene_effect(scene_effect), m_game_mgr(game_mgr)
{
}

void CharaSelect::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);
	m_scene_state = kStartAnim;
	m_ui_alpha = 0;
	m_timer = Utility::Timer(0.5f);

	m_scene_effect->Zoom(true);
	m_scene_effect->SetZoomRate(5.0f);

	m_player = new Player[4];
	m_player[0].side = kTeam1;
	m_player[1].side = kTeam2;
	m_player[2].side = kTeam3;
	m_player[3].side = kTeam4;

	//note: 値を変更したいなら、&が必要
	for (auto &c : m_controller) c = false;

	m_back_to_title = false;
}

void CharaSelect::Update()
{
	m_scene_effect->Update();
	switch (m_scene_state)
	{
	case kStartAnim:
		m_timer.Update();
		m_ui_alpha = 1 - m_timer.Rate();
		if (m_timer.IsTime()) m_scene_state = kJobSelect;
		break;
	case kJobSelect:
		if (CheckBackToTitle())
		{
			m_back_to_title = true;
			m_scene_state = kEndAnim;
			m_timer = Utility::Timer(0.5f);
			return;
		}
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
			m_timer = Utility::Timer(3.0f);
		}
		break;
	case kCountToGo:
		m_timer.Update();
		if (m_timer.IsTime()) m_scene_state = kReturnSelectInfo;
		//join
		if (CheckJoin())
		{
			m_scene_state = kJobSelect;
		}
		//lockした人がunlockする
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
		m_timer = Utility::Timer(0.5f);
		break;
	case kEndAnim:
		m_timer.Update();
		m_ui_alpha = m_timer.Rate();
		if (m_timer.IsTime())
		{
			m_is_end = true;
			if (m_back_to_title) m_next = kTitle;
			else m_next = kGamePlay;
		}
		break;
	}
}

void CharaSelect::Draw()
{
	m_scene_effect->DrawOnEffect();
	m_background->DrawBack();
	m_scene_effect->DrawEffect();
	m_renderer->DrawString("CharaSelect", Vector2(0, 0));

	m_renderer->DrawTexture("select_chara_ui", Vector2(0, 0), m_ui_alpha);
	for (int player_num = 0; player_num < 4; ++player_num)
	{
		int x = 107 + (player_num % 2) * 560;
		int y = 128 + (player_num / 2) * 246;
		if (m_player[player_num].controller_num == -1)
		{
			m_renderer->DrawTexture("select_chara_join_button", Vector2(x, y), m_ui_alpha);
		}
		else
		{
			m_renderer->DrawTexture("select_chara_button", Vector2(x, y), m_ui_alpha);
			switch (m_player[player_num].job % 4)
			{
			case 0:
				m_renderer->DrawTexture("select_chara_planner", Vector2(x, y), m_ui_alpha);
				m_renderer->DrawMotion("chara_face", 0, Vector2(x + 225, y + 140), CharacterColor::GetTeamColor(m_player[player_num].side), m_ui_alpha);
				break;
			case 1:
				m_renderer->DrawTexture("select_chara_business", Vector2(x, y), m_ui_alpha);
				m_renderer->DrawMotion("chara_face", 1, Vector2(x + 225, y + 140), CharacterColor::GetTeamColor(m_player[player_num].side), m_ui_alpha);
				break;
			case 2:
				m_renderer->DrawTexture("select_chara_designer", Vector2(x, y), m_ui_alpha);
				m_renderer->DrawMotion("chara_face", 2, Vector2(x + 225, y + 140), CharacterColor::GetTeamColor(m_player[player_num].side), m_ui_alpha);
				break;
			case 3:
				m_renderer->DrawTexture("select_chara_programmer", Vector2(x, y), m_ui_alpha);
				m_renderer->DrawMotion("chara_face", 3, Vector2(x + 225, y + 140), CharacterColor::GetTeamColor(m_player[player_num].side), m_ui_alpha);
				break;
			}
			if (m_player[player_num].lock)
			{
				m_renderer->DrawTexture("select_chara_ready", Vector2(x, y), m_ui_alpha);
			}
		}
	}
	if (m_scene_state == kCountToGo) DrawCount();
}

void CharaSelect::DrawCount()
{
	int num = m_timer.Rate() * 4;
	float size = 10 * ((int)(m_timer.Rate() * 100) % 25) / 25.0f;
	m_renderer->DrawMotion("panel_number", num, Vector2(WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight / 2), Vector2(size, size));
}

void CharaSelect::Shutdown()
{
	delete[] m_player;
}

bool CharaSelect::CheckBackToTitle()
{
	for (int i = 0;i < 5;++i)
	{
		if (m_controller[i] == true) return false;
	}
	if (m_input->IsKeyTrigger(KEY_INPUT_D)) return true;
	for (int pad_num = 0;pad_num < 4;++pad_num)
	{
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_A)) return true;
	}
	return false;
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
			m_controller[pad_num] = true;
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
			m_player[player_num].job += 3;
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
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_DPAD_RIGHT) || m_input->IsPadStickTrigger(pad_num, Vector2(0.7f, 0)))
		{
			++m_player[player_num].job;
		}
		if (m_input->IsPadButtonTrigger(pad_num, XINPUT_BUTTON_DPAD_LEFT) || m_input->IsPadStickTrigger(pad_num, Vector2(-0.7f, 0)))
		{
			m_player[player_num].job += 3;
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
		if (m_player[player_num].controller_num == -1)
		{
			m_player[player_num].job = Device::GameDevice::GetInstance()->GetRandom()->Next(4);
		}
		Side side = m_player[player_num].side;
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
		int difficulty = 0;
		difficulty = Device::GameDevice::GetInstance()->
			GetRandom()->Next(1, 10);
		switch (m_player[player_num].controller_num)
		{
		case 4:
			v_controller = make_shared<Character::KeyboardController>(player_num + 1);
			m_game_mgr->AddSelectCharacter(job, side, v_controller);
			break;
		case -1:
			v_controller = make_shared < Character::AiController>(player_num + 1);
			m_game_mgr->AddSelectAI(job, side, v_controller, difficulty);
			break;
		default:
			v_controller = make_shared<Character::PadController>(m_player[player_num].controller_num, player_num + 1);
			m_game_mgr->AddSelectCharacter(job, side, v_controller);
			break;
		}
	}
}
