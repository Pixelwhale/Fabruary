//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.21
// 内容　：長くなるとか、大きくなるとか前に直線に行くスキル
//-------------------------------------------------------

#include <GameObject\AttackSystem\laser.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

Laser::Laser(Math::Vector3 initial_position, Math::Vector3 size, Side side, std::string animation_to_play, int attack, int knockdown, int knockback, int dbreak, int damage_combo, float life_span_timer, float take_damage_at, Direction source_dir)
	: Attack(initial_position, size, side, attack, knockdown, knockback, dbreak, 0, source_dir), m_life_span_timer(life_span_timer)
{
	m_take_damage_at = take_damage_at;
	m_damage_combo = damage_combo;

	m_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_motion->Initialize();
	m_motion->Play(animation_to_play, 1);
	if (source_dir == AttackSystem::kRight) m_motion->Flip(true, false);
	m_motion->SetPosition(m_position);
}

Laser::~Laser()
{
	m_motion = NULL;
}

std::vector<std::shared_ptr<Attack>> Laser::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	/*if (m_life_span_timer.Rate() <= m_take_damage_at)
	{
		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position + m_add_position, m_size + m_add_size, m_side, m_c_attack, m_c_knockback, m_knockdown, m_c_dbreak, "Effect/slash", m_life_span_timer.Rate()));
	}*/
	return attack;
}

void Laser::Update()
{
	m_life_span_timer.Update();
	if (m_life_span_timer.IsTime())
	{
		m_is_end = true;
	}
	if (m_life_span_timer.Rate() <= m_take_damage_at && m_damage_combo != 0)
	{
		m_take_damage_at = m_take_damage_at - 0.6667;
		m_position = m_position + m_size;
		m_size *= 2;
		m_damage_combo--;
	}
	m_motion->Update();
}

void Laser::Draw()
{
	m_motion->Draw();
}


//Laser::Laser(Math::Vector3 first_position, Math::Vector3 size, Math::Vector3 add_position, Math::Vector3 add_size, Side side, std::string animation_to_play, int attack, int knockdown, int knockback, int dbreak, int damage_combo, float life_span_timer, float take_damage_at, Direction source_dir)
//	: Attack (first_position, size, side, 0, 0, 0, 0, 0, source_dir), m_life_span_timer(life_span_timer)
//{
//	m_c_attack = attack;
//	m_c_knockback = knockback;
//	m_c_knockdown = knockdown;
//	m_c_dbreak = dbreak;
//	m_take_damage_at = take_damage_at;
//	m_add_position = add_position;
//	m_add_size = add_size;
//	m_damage_combo = damage_combo;
//
//
//	m_motion = std::make_shared<MotionSystem::Motion>("Character");
//	m_motion->Initialize();
//	m_motion->Play(animation_to_play, 1);
//	if (source_dir == AttackSystem::kRight)
//	{
//		m_motion->Flip(true, false);
//	}
//	m_motion->SetPosition(first_position -  Math::Vector3(640, 0, 0));
//}
//
//
//Laser::~Laser() 
//{
//	m_motion = NULL;
//}
//
//std::vector<std::shared_ptr<Attack>> Laser::Collide()
//{
//	std::vector<std::shared_ptr<Attack>> attack;
//	attack.clear();
//	if (m_life_span_timer.Rate() <= m_take_damage_at)
//	{
//		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position + m_add_position, m_size + m_add_size, m_side, m_c_attack, m_c_knockback, m_knockdown, m_c_dbreak, "Effect/slash", m_life_span_timer.Rate()));
//	}
//	return attack;
//}
//
//void Laser::Update()
//{
//	m_life_span_timer.Update();
//	if (m_life_span_timer.IsTime())
//	{
//		m_is_end = true;
//	}
//	m_motion->Update();
//}
//
//void Laser::Draw()
//{
//	m_motion->Draw();
//}