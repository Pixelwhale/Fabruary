//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：Job Class - プログラマー
// 最後の更新 : 2018.02.19
//-------------------------------------------------------

#include <GameObject\Job\programmer.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>

using namespace Job;

// コンストラクタ
Programmer::Programmer(Side side) : m_next_combo(0.7)
{
	m_side = side;
}

// デストラクタ
Programmer::~Programmer() {}

std::string Programmer::Punch(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";

	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 2), 0);
	
	if (is_right)
	{
		plus.x *= -1;
	}

	if (m_punch_count == 0)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4f));
		m_punch_count++;
		return base_animation + "punch_1";
	}
	else if (m_punch_count == 1)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
		m_punch_count++;
		return base_animation + "punch_2";
	}
	else if (m_punch_count == 2)
	{
		attack_manager.AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(1, 1, 1), m_side, 1, 0, 0.4));
		m_punch_count++;
		return base_animation + "punch_3";
	}
	else
	{
		// 最後のパンチを出す後。
		return "";
	}
}

std::string Programmer::Kick(AttackSystem::AttackManager & attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	attack_manager.AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(1, 1, 1), m_side, 0, 0, 0.4));
	return base_animation + "kick1";
}

std::string Programmer::Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill1";
}

std::string Programmer::Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill2";
}

std::string Programmer::Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill3";
}

std::string Programmer::Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	Math::Vector3 plus = Math::Vector3((Size::kCharaX / 2), (Size::kCharaY / 3), 0);
	if (is_right)
	{
		plus.x *= -1;
	}
	// スキルの追加はここに
	return base_animation + "skill4";
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


