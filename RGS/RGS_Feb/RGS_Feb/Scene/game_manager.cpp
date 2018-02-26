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

#pragma region キャラクター選択関連

void GameManager::AddSelectCharacter(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller)
{
	SelectInfo info;					//info宣言
	info.m_job = job;					//情報設定
	info.m_side = side;					//Team設定
	info.m_controller = controller;		//コントローラー設定
	info.m_ai_controller = NULL;
	info.m_difficulty = 0;

	m_player_info.push_back(info);		//追加
	m_controller.push_back(controller);
}

void GameManager::AddSelectAI(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller,
	int difficulty)
{
	SelectInfo info;					//info宣言
	info.m_job = job;					//情報設定
	info.m_side = side;					//Team設定
	info.m_ai_controller = controller;	//コントローラー設定
	info.m_controller = NULL;
	info.m_difficulty = difficulty;

	m_player_info.push_back(info);		//追加
}

std::vector<SelectInfo> GameManager::GetSelectInfo()
{
	return m_player_info;
}

void GameManager::Clear() 
{
	m_pause_controller = NULL;

	for (auto &info : m_player_info) 
	{
		info.m_controller = NULL;
		info.m_job = NULL;
	}
	m_player_info.clear();

	for (auto &controller : m_controller)
	{
		controller = NULL;
	}
	m_controller.clear();
}

#pragma endregion

#pragma region Pause関連

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

#pragma endregion

#pragma region Winner関連


void GameManager::SetWinner(std::vector<shared_ptr<MotionSystem::Motion>> motion)
{
	m_winner_motion = motion;
}

std::vector<shared_ptr<MotionSystem::Motion>> GameManager::WinnerMotion() 
{
	return m_winner_motion;
}

void GameManager::ClearWinnerMotion() 
{
	for (auto &motion : m_winner_motion)
	{
		motion = NULL;
	}
	m_winner_motion.clear();
}

#pragma endregion
