//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
// ���e�FCollisionBox�̍X�V�ƕ`��
//-------------------------------------------------------
#include "attack_manager.h";

using namespace AttackSystem;

AttackManager::AttackManager()
{
	m_atk_list.clear();
}

AttackManager::~AttackManager()
{
	m_atk_list.clear();
}

void AttackManager::Initialize()
{
	m_atk_list.clear();
}