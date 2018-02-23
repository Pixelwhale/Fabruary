//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：攻撃（パンチ）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

// コンストラクタ
Punch::Punch(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(Math::Vector3(), Math::Vector3(), side, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{	
	m_c_position = position;
	m_c_size = size;
	m_timer = 17;
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;
}

// デストラクタ
Punch::~Punch() {}

std::vector<std::shared_ptr<Attack>> Punch::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	attack.push_back(std::make_shared<AttackSystem::Damage>(m_c_position, m_c_size * (1 - m_life_span_timer.Rate()), m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_dbreak, m_life_span_timer.GetCurrentTime()));
	return attack;
}

void AttackSystem::Punch::Update()
{
	Attack::Update();
	m_life_span_timer.Update();
	if (m_life_span_timer.IsTime())
	{
		m_is_end = true;
	}
	if (m_life_span_timer.GetCurrentTime() < (0.3 * 60))
	{
		Collide();
	}
}

void AttackSystem::Punch::Draw()
{

}
