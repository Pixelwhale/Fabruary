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

void GameManager::AddSelectCharacter(
	std::shared_ptr<Job::JobBase> job,
	Side side,
	std::shared_ptr<Character::VirtualController> controller)
{
	SelectInfo info;					//info�錾
	info.m_job = job;					//���ݒ�
	info.m_side = side;
	info.m_controller = controller;

	m_player_info.push_back(info);		//�ǉ�
}

std::vector<SelectInfo> GameManager::GetSelectInfo()
{
	return m_player_info;
}

void GameManager::Clear() 
{
	m_player_info.clear();
}