//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：Job Class - プランナー
// 最後の更新 : 2018.02.20
//-------------------------------------------------------

#include <GameObject\Job\planner.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>

using namespace Job;

// コンストラクタ
Planner::Planner(Side side) : m_next_combo(1)
{
	m_side = side;
}

// デストラクタ
Planner::~Planner() {}

std::string Planner::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), 10, 0);

	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}

	switch (m_punch_count)
	{
		case 0 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 4, 0, 0, 6, 0.5, 0.2, attack_source));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_1";
		case 1 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 5, 0, 0, 9, 0.5, 0.2, attack_source));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_2";
		case 2 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(55, 55, 55), m_side, 5, 0, 1, 9, 0.5, 0.2, attack_source));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_5";
		case 3 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(58, 58, 58), m_side, 7, 0, 1, 9, 0.5, 0.2, attack_source));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_4";
		case 4 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(60, 60, 60), m_side, 8, 3, 1, 13, 0.5, 0.2, attack_source));
			m_punch_count = 0;
			m_next_combo.Reset();
			return base_animation + "punch_7";
	}

	return base_animation + "idle";
}

std::string Planner::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), -10, 0);
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(65, 65, 65), m_side, 20, 2, 3, 13, 0.5));
	return base_animation + "kick_1";
}

std::string Planner::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX), 0, 0);
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared <AttackSystem::Punch>(position + plus, Math::Vector3(400, 400, 0), m_side, 17, 0, 30, 30, 0.83, 0.4, attack_source));
	if (!is_right) return base_animation + "skill_roar_L";
	else return base_animation + "skill_roar_R";
}

std::string Planner::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_2";
}

std::string Planner::Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_3";
}

std::string Planner::Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_4";
}

int Planner::KnockValue()
{
	return 8;
}

int Planner::GetHp()
{
	return m_hp;
}

void Planner::Update()
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