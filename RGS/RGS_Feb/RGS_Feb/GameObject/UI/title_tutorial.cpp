//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTutorial��I����������State
//-------------------------------------------------------
#include <GameObject\UI\title_tutorial.h>
#include <Def\window_def.h>

using namespace UI;

MenuTutorial::MenuTutorial()
{
}

MenuTutorial::MenuTutorial(const MenuTutorial&)
{
}

MenuTutorial::~MenuTutorial()
{
}

void MenuTutorial::Initialize(MenuState previous_state)
{
	m_end_flag = false;
	m_next_flag = false;
	m_push_alpha = 1.0f;

	if (previous_state == MenuState::kTitle)
		m_push_alpha = 0.0f;
}

void MenuTutorial::Update()
{
	UpdateAlpha();

	CheckEnd();
}

void MenuTutorial::UpdateAlpha()
{
	if (!m_next_flag)
	{
		m_push_alpha += 0.1f;
		if (m_push_alpha >= 1.0f)
			m_push_alpha = 1.0f;
		return;
	}

	m_push_alpha -= 0.1f;
	if (m_push_alpha <= 0.0f)
		m_push_alpha = 0.0f;
	return;
}

void MenuTutorial::CheckEnd()
{
	if (m_next_flag && m_push_alpha <= 0.0f)	//���֍s����
		m_end_flag = true;

	if (m_next_flag)							//���֍s���r����Input����ł��Ȃ�
		return;

	if (Enter())								//Tutorial��
	{
		m_next_flag = true;
		m_next_state = MenuState::kEnd;
		return;
	}

	if (Cancel())								//Push Start��
	{
		m_next_flag = true;
		m_next_state = MenuState::kTitle;
		return;
	}

	if (Up())									//GamePlayState��
	{
		m_end_flag = true;
		m_next_state = MenuState::kGamePlay;
		return;
	}

	if (Down())									//CreditState��
	{
		m_end_flag = true;
		m_next_state = MenuState::kCredit;
		return;
	}
}

void MenuTutorial::Draw()
{
	Math::Vector2 start_pos =
		Math::Vector2(WindowDef::kScreenWidth / 2 - 256, WindowDef::kScreenHeight - 390);
	int height = 75;

	m_renderer->DrawTexture(
		"menu_start_game",
		start_pos,
		m_push_alpha - 0.3f);

	m_renderer->DrawTexture(
		"menu_tutorial",
		start_pos + Math::Vector2(0, height),
		m_push_alpha);

	m_renderer->DrawTexture(
		"menu_credit",
		start_pos + Math::Vector2(0, 2 * height),
		m_push_alpha - 0.3f);

	m_renderer->DrawTexture(
		"menu_quit",
		start_pos + Math::Vector2(0, 3 * height),
		m_push_alpha - 0.3f);
}

MenuState MenuTutorial::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuTutorial::NextScene()
{
	return Scene::kTutorial;
}