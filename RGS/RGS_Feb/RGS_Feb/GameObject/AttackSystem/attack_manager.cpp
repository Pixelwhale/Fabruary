//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.02.05
// 内容：CollisionBoxの更新と描画
//-------------------------------------------------------
#include "attack_manager.h";

using namespace AttackSystem;

AttackManager::AttackManager()
{
	m_atk_list.clear();
	m_add_list.clear();
}

AttackManager::~AttackManager()
{
	m_atk_list.clear();
	m_add_list.clear();
}

void AttackManager::Initialize()
{
	m_atk_list.clear();
	m_add_list.clear();
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
	m_add_list.clear();
}

/*
bool AttackManager::IsCollision()
{
}
*/

void AttackManager::Update()
{
	AddAttack();

	for (auto atk : m_atk_list)
	{
		atk->Update();

		//攻撃できる対象？
		//距離判定ー＞精度高い判定
		/*
		for (auto c : character_list)
		{
			if (IsCollision(atk,c)　//中でSideをチェックして、Box生成して判定
			{
				c.Collide();
				atk.Collide();
			}
		}
		*/
	}
}

void AttackManager::Draw()
{
	for (auto atk : m_atk_list)
	{
		atk->Draw();
	}
}