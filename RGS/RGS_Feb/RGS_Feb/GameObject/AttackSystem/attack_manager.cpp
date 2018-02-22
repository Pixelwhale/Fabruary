//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.05
// 内容：CollisionBoxの更新と描画
//-------------------------------------------------------
#include "attack_manager.h";
#include <Character\character_base.h>
#include <Character\character_manager.h>
#include "attack.h"

using namespace AttackSystem;
using namespace Math;

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

void AttackManager::Remove()
{
	//remove_ifは同じ
	for (std::vector<shared_ptr<Attack>>::iterator i = m_atk_list.begin(); i != m_atk_list.end();)
	{
		if ((*i)->IsEnd() == true) m_atk_list.erase(i);
		else ++i;
	}
}

bool AttackManager::IsCollision(const std::shared_ptr<const Attack> atk, const std::shared_ptr<Character::CharacterBase> c)
{
	//キャラは無敵時間だったらreturn
	if (c->IsInvincible()) return false;

	//同じチームだったらreturn
	if (atk->GetSide() == c->GetSide()) return false;

	//重複判定か？
	int charaID = c->GetID();
	for (auto attacked : atk->GetAttackedList())
	{
		if (attacked.id == charaID && attacked.cool_down != 0) return false;
	}

	//CollisionBox生成して判定
	CollisionBox atk_box = atk->GetBox();
	CollisionBox c_box = c->GetBox();
	return atk_box.IsCollision(c_box);
}

void AttackManager::Update(std::shared_ptr<Character::CharacterManager> chara_mgr)
{
	AddAttack();

	if (m_atk_list.empty()) return;
	for (auto atk : m_atk_list)
	{
		atk->Update();

		for (auto c : chara_mgr->GetCharacterList())
		{
			if (IsCollision(atk, c))
			{
				c->Collide(*atk);
				for (auto a : atk->Collide())
				{
					AddAttack(a);
				}
				atk->AddID(c->GetID());
			}
		}
	}

	Remove();
}

void AttackManager::Draw()
{
	for (auto atk : m_atk_list)
	{
		atk->Draw();
	}
}