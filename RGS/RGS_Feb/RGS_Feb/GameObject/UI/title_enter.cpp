//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitle��State
//-------------------------------------------------------
#include <GameObject\UI\title_enter.h>
#include <Def\window_def.h>

using namespace UI;

TitleEnter::TitleEnter()
{
}

TitleEnter::TitleEnter(const TitleEnter&)
{
}

TitleEnter::~TitleEnter()
{
}

void TitleEnter::Initialize(MenuState previous_state)
{
	m_end_flag = false;
	m_next_flag = false;
	m_push_alpha_switch = true;
	m_push_alpha = 0.0f;
}

void TitleEnter::Update()
{
	UpdateAlpha();

	CheckEnd();
}

void TitleEnter::UpdateAlpha()
{
	if (m_next_flag)				//���֍s���ƃt�F�C�h�A�E�g
	{
		m_push_alpha -= 0.07f;
		return;
	}

	if (m_push_alpha_switch)		//�t�F�C�h�C��
	{
		m_push_alpha += 0.007f;
		if (m_push_alpha >= 1.0f)
			m_push_alpha_switch = false;
		return;
	}

	m_push_alpha -= 0.007f;			//�t�F�C�h�A�E�g
	if (m_push_alpha <= 0.75f)
		m_push_alpha_switch = true;
}

void TitleEnter::CheckEnd() 
{
	if (m_next_flag && m_push_alpha <= 0.0f)	//���֍s����
		m_end_flag = true;

	if (m_next_flag)							//���֍s���r����Input����ł��Ȃ�
		return;

	if (m_input->IsKeyTrigger(KEY_INPUT_A))
	{
		m_next_flag = true;
		return;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_B)) 
		{
			m_next_flag = true;
			return;
		}
	}
}

void TitleEnter::Draw()
{
	m_renderer->DrawTexture(
		"select_chara_join_button", 
		Math::Vector2(WindowDef::kScreenWidth / 2 - 256, WindowDef::kScreenHeight - 300),
		m_push_alpha);
}

MenuState TitleEnter::NextState()
{
	return MenuState::kGamePlay;
}

Scene::SceneType TitleEnter::NextScene()
{
	return Scene::kTitle;
}