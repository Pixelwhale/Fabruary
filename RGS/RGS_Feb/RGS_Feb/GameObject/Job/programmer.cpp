//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.05
// ���e�@�FJob Class - �v���O���}�[
// �Ō�̍X�V : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>

using namespace Job;

// �R���X�g���N�^
Programmer::Programmer(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// �f�X�g���N�^
Programmer::~Programmer() {}

void Programmer::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 2), 0);
	
	if (is_right)
	{
		plus.x *= -1;
	}

	if (m_punch_count == 0)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
		m_punch_count++;
	}
	else if (m_punch_count == 1)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
		m_punch_count++;
	}
	else if (m_punch_count == 2)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 1, 0, 0.4));
		m_punch_count++;
	}
	else
	{
		// �Ō�̃p���`���o����B
	}
}

void Programmer::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)

	{
		plus.x *= -1;
	}
	attack_manager.AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
}

void Programmer::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Programmer::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Programmer::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
}

void Programmer::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	if (is_right)
	{

	}
	else
	{

	}
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


