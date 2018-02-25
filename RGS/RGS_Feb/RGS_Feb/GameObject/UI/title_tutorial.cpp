//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：Tutorialを選択した時のState
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
	if (m_next_flag && m_push_alpha <= 0.0f)	//次へ行ける
		m_end_flag = true;

	if (m_next_flag)							//次へ行く途中はInput操作できない
		return;

	if (Enter())								//SelectCharacterへ
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
		m_next_state = MenuState::kGamePlay;
		return;
	}

	if (Down())									//QuitStateへ
	{
		m_end_flag = true;
		m_next_state = MenuState::kQuit;
		return;
	}
}

void MenuTutorial::Draw()
{
	m_renderer->DrawTexture(
		"select_chara_join_button",
		Math::Vector2(WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight - 200),
		m_push_alpha);
}

MenuState MenuTutorial::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuTutorial::NextScene()
{
	return Scene::kTutorial;
}