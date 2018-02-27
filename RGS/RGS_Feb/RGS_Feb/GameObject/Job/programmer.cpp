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
#include <Device\game_device.h>

using namespace Job;

// コンストラクタ
Programmer::Programmer(Side side) : m_next_combo(1)
{
	m_side = side;
	m_sound = Device::GameDevice::GetInstance()->GetSound();
	m_sound_storage.clear();
}

// デストラクタ
Programmer::~Programmer() 
{
	m_sound = NULL;
}

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
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 10, 3, 1, 8, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_6";
	case 1 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(50, 50, 50), m_side, 11, 3, 1, 10, 0.5, 0.2, attack_source));
		m_punch_count++;
		m_next_combo.Reset();
		return base_animation + "punch_7";
	case 2 :
		attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(80, 80, 80), m_side, 10, 5, 1, 15, 0.5, 0.2, attack_source));
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
	attack_manager->AddAttack(std::make_shared<AttackSystem::Kick>(position + plus, Math::Vector3(65, 65, 65), m_side, 15, 10, 3, 13, 0.5));
	return base_animation + "kick_1";
}

// C++ハンマー
std::string Programmer::Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	SoundEffectStorage se;
	se.play_time = Utility::Timer(0.79);
	se.sound_name = "se_skill_pg";
	m_sound_storage.push_back(se);

	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3(Size::kCharaX, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Punch>(position + plus, Math::Vector3(325, 325, 225), m_side, 23, 10, 2, 25, 1, 0.41, attack_source));
	return base_animation + "skill_hammer";

	/*std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3(Size::kCharaX / 3 - 64, 0, 0);
	Math::Vector3 size = Math::Vector3(160, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		size.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Laser>(position + plus + size, size + Math::Vector3(0, 128, 128), m_side, "Kamehameha/anime_1", 100, 10, 5, 90, 3, 3, 0.66, attack_source));
	return base_animation + "skill_energy_blast";*/
}

// Phyton カメハメハ
std::string Programmer::Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right)
{
	std::string base_animation = "chara_base_anime/";
	AttackSystem::Direction attack_source = AttackSystem::kRight;
	Math::Vector3 plus = Math::Vector3(Size::kCharaX / 3 - 64, 0, 0);
	Math::Vector3 size = Math::Vector3(160, 0, 0);
	if (!is_right)
	{
		plus.x *= -1;
		size.x *= -1;
		attack_source = AttackSystem::kLeft;
	}
	attack_manager->AddAttack(std::make_shared<AttackSystem::Laser>(position + plus + size, size + Math::Vector3(0, 128, 128), m_side, "Kamehameha/anime_1", 100, 10, 5, 90, 3, 3, 0.66, attack_source));
	return base_animation + "skill_energy_blast";
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

	for (auto &se : m_sound_storage)
	{
		se.play_time.Update();

		if (se.play_time.IsTime())
		{
			m_sound->PlaySE(se.sound_name);
		}
	}

	for (std::vector<SoundEffectStorage>::iterator i = m_sound_storage.begin(); i != m_sound_storage.end();)
	{
		if ((*i).play_time.IsTime())
		{
			i = m_sound_storage.erase(i);
			continue;
		}
		++i;
	}

	if (m_punch_count != 0)
	{
		m_next_combo.Update();
	}
}
