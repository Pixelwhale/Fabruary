//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：攻撃（キック）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\kick.h>

using namespace AttackSystem;

// コンストラクタ
Kick::Kick(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(position, size, side, attack, knockdown, knockback, dbreak), m_life_span_timer(life_span_timer)
{
}

// デストラクタ
Kick::~Kick() {}


std::vector<std::shared_ptr<Attack>> AttackSystem::Kick::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	return attack;
}

void AttackSystem::Kick::Update()
{
	Attack::Update();
	m_life_span_timer.Update();
	if (m_life_span_timer.IsTime())
	{
		m_is_end = true;
	}
}

void AttackSystem::Kick::Draw()
{

}
