//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�FJob Class - �r�W�l�X
// �Ō�̍X�V : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\business.h>

using namespace Job;

// �R���X�g���N�^
Business::Business(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// �f�X�g���N�^
Business::~Business() {}

void Business::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
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
			// �����ƃp���`���Ȃ��悤�ɁB
		}
	}
	else
	{
		// ������
	}
}

void Business::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
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

void Business::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Business::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Business::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Business::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Business::Update()
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