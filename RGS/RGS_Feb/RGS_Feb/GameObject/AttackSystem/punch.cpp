//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：攻撃（パンチ）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\punch.h>

using namespace AttackSystem;

// コンストラクタ
Punch::Punch(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(position, size, side, attack, knockdown, knockback, dbreak), m_life_span_timer(life_span_timer)
{	
	m_timer = 17;
}

// デストラクタ
Punch::~Punch() {}

std::vector<std::shared_ptr<Attack>> AttackSystem::Punch::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	//attack.push_back(std::make_shared<AttackSystem::Punch>(m_position, m_size, m_side, m_dmg, m_knockback, m_knockdown, m_break, 0.7));
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
	//m_size.x = m_size.x++;
}

void AttackSystem::Punch::Draw()
{

}
