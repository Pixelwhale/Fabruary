//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：TitleStateの管理者
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

	if (m_current_state.lock()->IsEnd())						//終了すれば次のState
	{
		MenuState previous_menu = m_current_menu;				//前のStateを記録
		m_current_menu = m_current_state.lock()->NextState();	//次のStateを記録

		if (m_current_menu == MenuState::kEnd)					//終了であればReturn
			return;

		m_current_state = m_states[m_current_menu];				//State変更
		m_current_state.lock()->Initialize(previous_menu);		//次のStateを初期化
	}
}

void TitleStateManager::ChangeState(MenuState state)
{
	MenuState previous_menu = m_current_menu;				//前のStateを記録
	m_current_menu = state;									//次のStateを記録

	if (m_current_menu == MenuState::kEnd)					//終了であればReturn
		return;

	m_current_state = m_states[m_current_menu];				//State変更
	m_current_state.lock()->Initialize(previous_menu);		//次のStateを初期化
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