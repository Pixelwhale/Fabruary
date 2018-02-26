//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitleState�̊Ǘ���
//-------------------------------------------------------
#include <GameObject\UI\title_state_manager.h>
#include <GameObject\UI\title_enter.h>
#include <GameObject\UI\title_gameplay.h>
#include <GameObject\UI\title_tutorial.h>
#include <GameObject\UI\title_quit.h>

using namespace UI;

TitleStateManager::TitleStateManager()
{
}

TitleStateManager::TitleStateManager(const TitleStateManager&)
{
}

TitleStateManager::~TitleStateManager()
{
}

void TitleStateManager::Initialize()
{
	m_states[MenuState::kTitle] = make_shared<TitleEnter>();
	m_states[MenuState::kGamePlay] = make_shared<MenuGamePlay>();
	m_states[MenuState::kTutorial] = make_shared<MenuTutorial>();
	m_states[MenuState::kQuit] = make_shared<MenuQuit>();

	m_current_menu = MenuState::kTitle;
	m_current_state = m_states[m_current_menu];
	m_current_state.lock()->Initialize(MenuState::kTitle);
}

void TitleStateManager::Clear()
{
	for (auto &state : m_states) 
	{
		state.second = NULL;
	}

	m_states.clear();
}

void TitleStateManager::Update()
{
	if (m_current_menu == MenuState::kEnd)
		return;

	m_current_state.lock()->Update();

	if (m_current_state.lock()->IsEnd())						//�I������Ύ���State
	{
		MenuState previous_menu = m_current_menu;				//�O��State���L�^
		m_current_menu = m_current_state.lock()->NextState();	//����State���L�^

		if (m_current_menu == MenuState::kEnd)					//�I���ł����Return
			return;

		m_current_state = m_states[m_current_menu];				//State�ύX
		m_current_state.lock()->Initialize(previous_menu);		//����State��������
	}
}

void TitleStateManager::ChangeState(MenuState state)
{
	MenuState previous_menu = m_current_menu;				//�O��State���L�^
	m_current_menu = state;									//����State���L�^

	if (m_current_menu == MenuState::kEnd)					//�I���ł����Return
		return;

	m_current_state = m_states[m_current_menu];				//State�ύX
	m_current_state.lock()->Initialize(previous_menu);		//����State��������
}

void TitleStateManager::Draw()
{
	m_current_state.lock()->Draw();
}

bool TitleStateManager::IsEnd()
{
	return m_current_menu == MenuState::kEnd;
}

Scene::SceneType TitleStateManager::NextScene() 
{
	return m_current_state.lock()->NextScene();
}