//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：Job Class - プログラマー
// 最後の更新 : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>

using namespace Job;

// コンストラクタ
Programmer::Programmer(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// デストラクタ
Programmer::~Programmer() {}

void Programmer::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{
		if (m_punch_count == 0)
		{
			std::shared_ptr<AttackSystem::Attack> punch(new AttackSystem::Punch(position, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
			attack_manager.AddAttack(punch);
			m_punch_count++;

		}
		else if (m_punch_count == 1)
		{
			std::shared_ptr<AttackSystem::Attack> punch(new AttackSystem::Punch(position, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
			attack_manager.AddAttack(punch);
			m_punch_count++;
		}
		else if (m_punch_count == 2)
		{
			std::shared_ptr<AttackSystem::Attack> punch(new AttackSystem::Punch(position, Math::Vector3(1, 1, 1), m_side, 1, 0, 0.4));
			attack_manager.AddAttack(punch);
			m_punch_count++;
		}
		else
		{
			// ずっとパンチしないように。
		}
	}
	else
	{
		// 左向き
	}
}

void Programmer::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
		std::shared_ptr<AttackSystem::Attack> kick(new AttackSystem::Kick(position, Math::Vector3(2,2,2), m_side, 0, 0, 0.5));
		attack_manager.AddAttack(kick);
}

void Programmer::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{

}

void Programmer::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{

}

void Programmer::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{

}

void Programmer::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{

}

void Programmer::Update()
{
	if (m_next_combo.IsTime())
	{
		m_next_combo.Reset();
		m_punch_count = 0;
		m_punch_last_update = 0;
	}

	if (m_punch_count != m_punch_last_update)
	{
		m_next_combo.Reset();
		m_punch_last_update = m_punch_count;
	}

	if (m_punch_count != 0)
	{
		m_next_combo.Update();
	}
}


