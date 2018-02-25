//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FGamePlay��I����������State
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
	if (m_next_flag && m_push_alpha <= 0.0f)	//���֍s����
		m_end_flag = true;

	if (m_next_flag)							//���֍s���r����Input����ł��Ȃ�
		return;

	if (Enter())								//SelectCharacter��
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

	if (Down())									//TutorialState��
	{
		m_end_flag = true;
		m_next_state = MenuState::kTutorial;
		return;
	}
}

void MenuGamePlay::Draw()
{
	Math::Vector2 start_pos = 
		Math::Vector2(WindowDef::kScreenWidth / 2 - 256, WindowDef::kScreenHeight - 390);
	int height = 85;

	m_renderer->DrawTexture(
		"menu_start_game",
		start_pos,
		m_push_alpha);

	m_renderer->DrawTexture(
		"menu_tutorial",
		start_pos + Math::Vector2(0, height),
		m_push_alpha - 0.3f);

	m_renderer->DrawTexture(
		"menu_quit",
		start_pos + Math::Vector2(0, 2 * height),
		m_push_alpha - 0.3f);
}

MenuState MenuGamePlay::NextState()
{
	return m_next_state;
}

Scene::SceneType MenuGamePlay::NextScene()
{
	return Scene::kCharaSelect;
}