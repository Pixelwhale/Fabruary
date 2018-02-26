//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：Creditを選択した時のState
//-------------------------------------------------------
#include <GameObject\UI\title_credit.h>
#include <Def\window_def.h>

using namespace UI;

MenuCredit::MenuCredit()
{
}

MenuCredit::MenuCredit(const MenuCredit&)
{
}

MenuCredit::~MenuCredit()
{
}

void MenuCredit::Initialize(MenuState previous_state)
{
	m_end_flag = false;
	m_next_flag = false;
	m_push_alpha = 1.0f;

	if (previous_state == MenuState::kTitle)
		m_push_alpha = 0.0f;
}

void MenuCredit::Update()
{
	UpdateAlpha();

	CheckEnd();
}

void MenuCredit::UpdateAlpha()
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

void MenuCredit::CheckEnd()
{
	if (m_next_flag && m_push_alpha <= 0.0f)	//次へ行ける
		m_end_flag = true;

	if (m_next_flag)							//次へ行く途中はInput操作できない
		return;

	if (Enter())								//Creditへ
	{
		m_next_flag = true;
		m_next_state = MenuState::kEnd;
		return;
	}

	if (Cancel())								//Push Startへ
	{
		m_next_flag = true;
		m_next_state = MenuState::kTitle;
		return;
	}

	if (Up())									//GamePlayStateへ
	{
		m_end_flag = true;
		m_next_state = MenuState::kTutorial;
		return;
	}

	if (Down())									//QuitStateへ
	{
		m_end_flag = true;
		m_next_state = MenuState::kQuit;
		return;
	}
}

void MenuCredit::Draw()
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
		m_push_alpha - 0.3f);

	m_renderer->DrawTexture(
		"menu_credit",
		start_pos + Math::Vector2(0, 2 * height),
		m_push_alpha);

	m_renderer->DrawTexture(
		"menu_quit",
		start_pos + Math::Vector2(0, 3 * height),
		m_push_alpha - 0.3f);
}

MenuState MenuCredit::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuCredit::NextScene()
{
	return Scene::kCredit;
}