//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：Job Class - ビジネス
// 最後の更新 : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\business.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>

using namespace Job;

// コンストラクタ
Business::Business(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// デストラクタ
Business::~Business() {}

std::string Business::Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";

	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 2), 0);

	if (is_right)
	{
		plus.x *= -1;
	}

	if (m_punch_count == 0)
	{
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 100, 0, 0, 0.4f));
		m_punch_count++;
		return base_animation + "punch_3";
	}
	else if (m_punch_count == 1)
	{
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 200, 0, 0, 0.4));
		m_punch_count++;
		return base_animation + "punch_4";
	}
	else if (m_punch_count == 2)
	{
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 200, 0, 0, 0.4));
		m_punch_count++;
		return base_animation + "punch_6";
	}
	return base_animation + "idle";
}

std::string Business::Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(1, 1, 1), m_side, 300, 0, 0, 0.4));
	return base_animation + "kick_1";
}

std::string Business::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_1";
}

std::string Business::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_1";
}

std::string Business::Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_1";
}

std::string Business::Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill_1";
}

int Business::KnockValue()
{
	return 0;
}

int Business::GetHp()
{
	return m_hp;
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