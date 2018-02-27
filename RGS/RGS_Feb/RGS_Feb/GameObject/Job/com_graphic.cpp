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
ComputerGraphic::ComputerGraphic(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// デストラクタ
ComputerGraphic::~ComputerGraphic() {}

std::string ComputerGraphic::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::Direction::kRight;
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), 10, 0);

	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::Direction::kLeft;
	}

	switch (m_punch_count)
	{
	case 0 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 4, 0, 1, 5, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_1";
	case 1 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 5, 0, 1, 5, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_2";
	case 2 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(52, 52, 52), m_side, 5, 0, 1, 6, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_5";
	case 3 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(52, 52, 52), m_side, 8, 0, 3, 6, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_7";
	case 4 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(55, 55, 55), m_side, 9, 1, 3, 7, 0.5, 0.2, attack_source));
		m_punch_count = 0;
		m_next_combo.Reset();
		return base_animation + "punch_6";
	}

	return base_animation + "idle";
}

std::string ComputerGraphic::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 4), -10, 0);
	if (!is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(60, 60, 60), m_side, 20, 2, 3, 13, 0.5));
	return base_animation + "kick_1";
}

std::string ComputerGraphic::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::Direction::kRight;
	Math::Vector3 plus = Math::Vector3(0, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::Direction::kLeft;
	}
	// スキルの追加はここに
	attack_manager->AddAttack(std::make_shared<AttackSystem::OmniSlash>(position + plus, Math::Vector3(350, 350, 0), m_side, 3, 1, 0, 30, 5, "Effect/wind_blow", 1, attack_source));
	return base_animation + "skill_color_slash";
}

std::string ComputerGraphic::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::Direction::kRight;
	Math::Vector3 plus = Math::Vector3(0, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::Direction::kLeft;
	}
	// スキルの追加はここに
	attack_manager->AddAttack(std::make_shared<AttackSystem::OmniSlash>(position + plus, Math::Vector3(350, 350, 100), m_side, 10, 1, 0, 0, 5, "skill_effect/skill_omnislash", 1, attack_source));
	// まだ終わってない。
	return base_animation + "skill_energy_blast";
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
	return 8;
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


