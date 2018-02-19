//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
// ���e�FCollisionBox�̍X�V�ƕ`��
//-------------------------------------------------------
#include "attack_manager.h";
#include <Character\character_base.h>
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

bool AttackManager::IsCollision(std::shared_ptr<Attack> a, std::shared_ptr<Character::CharacterBase> c)
{
	//�����`�[����������return
	if (a->GetSide() == c->GetSide()) return false;

	//�d�����肩�H
	/*
	if (a->IsRepeat() == false)
	{
		int charaID = c->GetID();
		for (int ID : a->GetAttackedList)
		{
			if (ID == charaID) return false;
		}
	}
	*/

	//CollisionBox�������Ĕ���
	CollisionBox atk_box = a->GetBox();
	CollisionBox c_box = CollisionBox(c->GetPosition() - Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), c->GetPosition() + Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
	return atk_box.IsCollision(c_box);
}


void AttackManager::Update(Character::CharacterManager& chara_mgr)
{
	AddAttack();

	for (auto atk : m_atk_list)
	{
		atk->Update();

		/*
		for (auto c : chara_mgr.GetCharacterList)
		{
			if (IsCollision(a,c)
			{
				c.Collide();
				atk->Collide();
				atk->AddID(c.GetID());
			}
		}
		*/
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