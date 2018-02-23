//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.20
// 内容　：シーンの間に情報を持つゲームマネージャー
//-------------------------------------------------------------
#include <Scene\game_manager.h>

using namespace Scene;

GameManager::GameManager()
{
	Clear();
}

GameManager::GameManager(const GameManager&)
{
	Clear();
}

GameManager::~GameManager()
{
	Clear();
}

void GameManager::AddSelectCharacter(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller)
{
	SelectInfo info;					//info宣言
	info.m_job = job;					//情報設定
	info.m_side = side;
	info.m_controller = controller;

	m_player_info.push_back(info);		//追加
	m_controller.push_back(controller);
}

std::vector<SelectInfo> GameManager::GetSelectInfo()
{
	return m_player_info;
}

void GameManager::Clear() 
{
	m_player_info.clear();
	m_pause_controller = NULL;
	m_controller.clear();
}

bool GameManager::IsPause() 
{
	for (auto &controller : m_controller) 
	{
		if (controller->IsPause()) 
		{
			m_pause_controller = controller;
			return true;
		}
	}

	return false;
}

std::shared_ptr<Character::VirtualController> GameManager::PauseController() 
{
	return m_pause_controller;
}