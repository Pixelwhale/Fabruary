//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：Quitを選択した時のState
//-------------------------------------------------------
#include <GameObject\UI\title_quit.h>
#include <Def\window_def.h>

using namespace UI;

MenuQuit::MenuQuit()
{
}

MenuQuit::MenuQuit(const MenuQuit&)
{
}

MenuQuit::~MenuQuit()
{
}

void MenuQuit::Initialize(MenuState previous_state)
{
	m_end_flag = false;
	m_next_flag = false;
	m_push_alpha = 1.0f;

	if (previous_state == MenuState::kTitle)
		m_push_alpha = 0.0f;
}

void MenuQuit::Update()
{
	UpdateAlpha();

	CheckEnd();
}

void MenuQuit::UpdateAlpha()
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

void MenuQuit::CheckEnd()
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

	if (Up())									//TutorialStateへ
	{
		m_end_flag = true;
		m_next_state = MenuState::kTutorial;
		return;
	}
}

void MenuQuit::Draw()
{
	m_renderer->DrawTexture(
		"select_chara_join_button",
		Math::Vector2(WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight - 100),
		m_push_alpha);
}

MenuState MenuQuit::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuQuit::NextScene()
{
	return Scene::kEnd;
}