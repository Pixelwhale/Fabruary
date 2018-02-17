//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2017.02.15
// 内容　：攻撃（パンチ）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\punch.h>

using namespace AttackSystem;

Punch::Punch(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, knockdown, knockback), m_life_span_timer(life_span_timer)
{	
}

void AttackSystem::Punch::Collide()
{
}

void AttackSystem::Punch::Update()
{
	m_life_span_timer.Update();
}

void AttackSystem::Punch::Draw()
{

}
