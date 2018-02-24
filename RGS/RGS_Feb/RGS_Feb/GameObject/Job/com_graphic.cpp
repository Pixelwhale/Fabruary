//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：Job Class - デザイン
// 最後の更新 : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\com_graphic.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>
#include <GameObject\AttackSystem\laser.h>
#include <GameObject\AttackSystem\omnislash.h>
#include <GameObject\AttackSystem\summoning_type.h>

using namespace Job;

// コンストラクタ
ComputerGraphic::ComputerGraphic(Side side) : m_next_combo(0.5)
{
	m_side = side;
}

// デストラクタ
ComputerGraphic::~ComputerGraphic() {}

std::string ComputerGraphic::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
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
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 6, 0, 0, 15, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_1";
	case 1 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 7, 0, 0, 15, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_2";
	case 2 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(55, 55, 55), m_side, 7, 0, 0, 15, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_3";
	case 3 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(58, 58, 58), m_side, 8, 0, 0, 20, 0.5, 0.2));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_4";
	case 4 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(60, 60, 60), m_side, 10, 1, 1, 30, 0.5, 0.2));
		m_punch_count = 0;
		m_next_combo.Reset();
		return base_animation + "punch_5";
	}

	return base_animation + "idle";
}

std::string ComputerGraphic::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), -10, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(18, 18, 18), m_side, 35, 1, 1, 40, 0.4));
	return base_animation + "kick_1";
}

std::string ComputerGraphic::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	attack_manager->AddAttack(std::make_shared<AttackSystem::OmniSlash>(position + plus, Math::Vector3(20, 20, 20), m_side, 15, 0, 0, 30, 1, "skill_effect/skill_omnislash", 0.4));
	return base_animation + "skill_energy_blast";
}

std::string ComputerGraphic::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	attack_manager->AddAttack(std::make_shared<AttackSystem::SummoningType>(position + plus, Math::Vector3(20, 20, 20), m_side, 0, 0, 0, 1));
	// まだ終わってない。
	return base_animation + "skill_2";
}

std::string ComputerGraphic::Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
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

std::string ComputerGraphic::Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
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

int ComputerGraphic::KnockValue()
{
	return 0;
}

int ComputerGraphic::GetHp()
{
	return m_hp;
}

void ComputerGraphic::Update()
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


