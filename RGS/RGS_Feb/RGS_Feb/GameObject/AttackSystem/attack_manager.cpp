//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
// ���e�FCollisionBox�̍X�V�ƕ`��
//-------------------------------------------------------
#include "attack_manager.h";

using namespace AttackSystem;
using namespace Character;
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

/*
bool AttackManager::IsCollision(Attack& a, CharacterBase& c)
{
	if (a.GetSide() == c.GetSide()) return;

	if (a.IsRepeat() == false)
	{
		CharaID charaID = c.GetID();
		for (auto ID : a.GetAttackedList)
		{
			if (ID == charaID) return;
		}
	}

	CollisionBox atk_box = a.GetBox();
	CollisionBox c_box = CollisionBox(c.GetPosition() - Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), c.GetPosition() + Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));

	return atk_box.IsCollision(c_box);
}
*/

void AttackManager::Update()
{
	AddAttack();

	for (auto atk : m_atk_list)
	{
		atk->Update();

		/*
		for (auto c : character_list)
		{
			if (IsCollision(atk,c)
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