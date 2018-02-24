//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：Job Class - プログラマー
// 最後の更新 : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>
#include <GameObject\AttackSystem\laser.h>

using namespace Job;

// コンストラクタ
Programmer::Programmer(Side side) : m_next_combo(1)
{
	m_side = side;
}

// デストラクタ
Programmer::~Programmer() {}

std::string Programmer::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";

	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 10, 0);
	
	if (!is_right)
	{
		plus.x *= -1;
	}

	switch (m_punch_count)
	{
	case 0 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 10, 1, 5, 8, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_6";
	case 1 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 11, 1, 5, 10, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_7";
	case 2 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(80, 80, 80), m_side, 13, 2, 5, 15, 0.5, 0.2));
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
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(60, 60, 60), m_side, 35, 2, 3, 40, 0.5));
	return base_animation + "kick_1";
}

// C++ハンマー
std::string Programmer::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3(Size::kCharaX, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(100, 100, 100), m_side, 35, 1, 2, 40, 1, 0.41));
	return base_animation + "skill_hammer";
}

// Phyton カメハメハ
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
	// スキルの追加はここに
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
	// スキルの追加はここに
	return base_animation + "skill_4";
}

int Programmer::KnockValue()
{
	return 0;
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
