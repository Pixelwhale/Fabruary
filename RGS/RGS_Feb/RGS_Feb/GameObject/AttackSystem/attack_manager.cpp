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

void AttackManager::AddAttack(std::shared_ptr<Attack> atk)
{
	m_add_list.push_back(atk);
}

void AttackManager::AddAttack()
{
	for (auto atk : m_add_list)
	{
		m_atk_list.push_back(atk);
	}
}

void AttackManager::Update()
{
	AddAttack();

	for (auto atk : m_atk_list)
	{
		atk->Update();
	}
}

void AttackManager::Draw()
{
	for (auto atk : m_atk_list)
	{
		atk->Draw();
	}
}