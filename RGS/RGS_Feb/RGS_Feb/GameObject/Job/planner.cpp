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

	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), 10, 0);

	if (!is_right)
	{
		plus.x *= -1;
	}

	switch (m_punch_count)
	{
		case 0 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(15, 15, 15), m_side, 10, 0, 0, 15, 0.4f));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_1";
		case 1 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(15, 15, 15), m_side, 10, 0, 0, 15, 0.4));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_2";
		case 2 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(15, 15, 15), m_side, 10, 0, 0, 15, 0.4));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_5";
		case 3 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(15, 15, 15), m_side, 13, 0, 0, 20, 0.4));
			m_punch_count++;
			m_next_combo.Reset();
			return base_animation + "punch_4";
		case 4 :
			attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(15, 15, 15), m_side, 15, 1, 1, 20, 0.4));
			m_punch_count = 0;
			m_next_combo.Reset();
			return base_animation + "punch_7";
	}

	return base_animation + "idle";
}

std::string Planner::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), -10, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(18, 18, 18), m_side, 35, 0, 0, 40, 0.4));
	return base_animation + "kick_1";
}

std::string Planner::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_1";
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
	return 0;
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