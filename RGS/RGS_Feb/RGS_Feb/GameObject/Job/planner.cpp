//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：Job Class - プランナー
//-------------------------------------------------------

#include <GameObject\Job\planner.h>

using namespace Job;

// コンストラクタ
Planner::Planner(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// デストラクタ
Planner::~Planner() {}

void Planner::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
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
		else
		{
		}
	}
	else
	{
		// 左向き
	}
}

void Planner::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{
		std::shared_ptr<AttackSystem::Attack> kick(new AttackSystem::Kick(position, Math::Vector3(2, 2, 2), m_side, 0, 0, 0.5));
		attack_manager.AddAttack(kick);
	}
	else
	{

	}
}

void Planner::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Planner::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Planner::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Planner::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Planner::Update()
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