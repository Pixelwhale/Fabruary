//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：攻撃（キック）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\kick.h>

using namespace AttackSystem;

// コンストラクタ
Kick::Kick(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, knockdown, knockback), m_life_span_timer(life_span_timer)
{
}

// デストラクタ
Kick::~Kick() {}


void AttackSystem::Kick::Collide(AttackManager attackManager)
{
}

void AttackSystem::Kick::Update()
{
	m_life_span_timer.Update();
}

void AttackSystem::Kick::Draw()
{

}
