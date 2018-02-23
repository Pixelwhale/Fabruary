//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.23
// 内容　：攻撃（オムニスラッシュ）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\omnislash.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

OmniSlash::OmniSlash(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(Math::Vector3(), Math::Vector3(), side, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{
	m_c_size = size;
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;
}

// デストラクタ
OmniSlash::~OmniSlash() {}

std::vector<std::shared_ptr<Attack>> OmniSlash::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	attack.push_back(std::make_shared<AttackSystem::Damage>(m_c_position, m_c_size * (1 - m_life_span_timer.Rate()), m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_dbreak, m_life_span_timer.GetCurrentTimes()));
	return attack;
}

void AttackSystem::OmniSlash::Update()
{
	Attack::Update();
	m_life_span_timer.Update();
	if (m_life_span_timer.IsTime())
	{
		m_is_end = true;
	}
	if (m_life_span_timer.GetCurrentTimes() < (0.3 * 60))
	{
		Collide();
	}
}

void AttackSystem::OmniSlash::Draw()
{

}

