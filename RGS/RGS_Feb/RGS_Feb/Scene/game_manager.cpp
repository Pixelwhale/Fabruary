//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.20
// ���e�@�F�V�[���̊Ԃɏ������Q�[���}�l�[�W���[
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

#pragma region �L�����N�^�[�I���֘A

void GameManager::AddSelectCharacter(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller)
{
	SelectInfo info;					//info�錾
	info.m_job = job;					//���ݒ�
	info.m_side = side;					//Team�ݒ�
	info.m_controller = controller;		//�R���g���[���[�ݒ�
	info.m_ai_controller = NULL;
	info.m_difficulty = 0;

	m_player_info.push_back(info);		//�ǉ�
	m_controller.push_back(controller);
}

void GameManager::AddSelectAI(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller,
	int difficulty)
{
	SelectInfo info;					//info�錾
	info.m_job = job;					//���ݒ�
	info.m_side = side;					//Team�ݒ�
	info.m_ai_controller = controller;	//�R���g���[���[�ݒ�
	info.m_controller = NULL;
	info.m_difficulty = difficulty;

	m_player_info.push_back(info);		//�ǉ�
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

#pragma region Pause�֘A

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

#pragma region Winner�֘A


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
