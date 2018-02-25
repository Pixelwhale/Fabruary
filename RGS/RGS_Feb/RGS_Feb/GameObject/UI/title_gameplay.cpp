//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：GamePlayを選択した時のState
//-------------------------------------------------------
#include <GameObject\UI\title_gameplay.h>
#include <Def\window_def.h>

using namespace UI;

MenuGamePlay::MenuGamePlay()
{
}

MenuGamePlay::MenuGamePlay(const MenuGamePlay&)
{
}

MenuGamePlay::~MenuGamePlay()
{
}

void MenuGamePlay::Initialize(MenuState previous_state)
{
	m_end_flag = false;
	m_next_flag = false;
	m_push_alpha = 1.0f;

	if(previous_state == MenuState::kTitle)
		m_push_alpha = 0.0f;
}

void MenuGamePlay::Update()
{
	UpdateAlpha();

	CheckEnd();
}

void MenuGamePlay::UpdateAlpha()
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

void MenuGamePlay::CheckEnd()
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

	if (Down())									//TutorialStateへ
	{
		m_end_flag = true;
		m_next_state = MenuState::kTutorial;
		return;
	}
}

void MenuGamePlay::Draw()
{
	m_renderer->DrawTexture(
		"select_chara_join_button",
		Math::Vector2(WindowDef::kScreenWidth / 2, WindowDef::kScreenHeight - 300),
		m_push_alpha);
}

MenuState MenuGamePlay::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuGamePlay::NextScene()
{
	return Scene::kCharaSelect;
}