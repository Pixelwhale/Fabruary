//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.05
// ���e�@�FJob Class - �v���O���}�[
// �Ō�̍X�V : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>
#include <GameObject\AttackSystem\laser.h>

using namespace Job;

// �R���X�g���N�^
Programmer::Programmer(Side side) : m_next_combo(1)
{
	m_side = side;
}

// �f�X�g���N�^
Programmer::~Programmer() {}

std::string Programmer::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 10, 0);
	
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}

	switch (m_punch_count)
	{
	case 0 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 10, 1, 1, 8, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_6";
	case 1 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 11, 1, 1, 10, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_7";
	case 2 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(80, 80, 80), m_side, 10, 2, 3, 15, 0.5, 0.2, attack_source));
		m_punch_count = 0;
		m_next_combo.Reset();
		return base_animation + "punch_8";
	}

	return base_animation + "idle";
}

std::string Programmer::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), -10, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(65, 65, 65), m_side, 20, 2, 3, 13, 0.5));
	return base_animation + "kick_1";
}

// C++�n���}�[
std::string Programmer::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3(Size::kCharaX, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(100, 100, 100), m_side, 18, 0, 9, 18, 1, 0.41, attack_source));
	return base_animation + "skill_hammer";
}

// Phyton �J���n���n
std::string Programmer::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Laser>(position + plus, Math::Vector3(20, 20, 20), m_side, 30, 0, 50, 90, Math::Vector3(2, 0, 0), Math::Vector3(0, 0, 0), 2));
	return base_animation + "skill_2";
}

std::string Programmer::Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// �X�L���̒ǉ��͂�����
	return base_animation + "skill_3";
}

std::string Programmer::Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// �X�L���̒ǉ��͂�����
	return base_animation + "skill_4";
}

int Programmer::KnockValue()
{
	return 9;
}

int Programmer::GetHp()
{
	return m_hp;
}

void Programmer::Update()
{
	if (m_next_combo.IsTime())
	{
		m_next_combo.Reset();
		m_punch_count = 0;
	}

	if (m_punch_count != 0)
	{
		m_next_combo.Update();
	}
}
