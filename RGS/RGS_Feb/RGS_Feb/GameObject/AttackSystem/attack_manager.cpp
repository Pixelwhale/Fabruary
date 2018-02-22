//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
// ���e�FCollisionBox�̍X�V�ƕ`��
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
	//remove_if�͓���
	for (std::vector<shared_ptr<Attack>>::iterator i = m_atk_list.begin(); i != m_atk_list.end();)
	{
		if ((*i)->IsEnd() == true) m_atk_list.erase(i);
		else ++i;
	}
}

bool AttackManager::IsCollision(const std::shared_ptr<const Attack> atk, const std::shared_ptr<Character::CharacterBase> c)
{
	//�L�����͖��G���Ԃ�������return
	if (c->IsInvincible()) return false;

	//�����`�[����������return
	if (atk->GetSide() == c->GetSide()) return false;

	//�d�����肩�H
	int charaID = c->GetID();
	for (auto attacked : atk->GetAttackedList())
	{
		if (attacked.id == charaID && attacked.cool_down != 0) return false;
	}

	//CollisionBox�������Ĕ���
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