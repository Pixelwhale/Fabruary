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
}

// デストラクタ
Punch::~Punch() {}

std::vector<std::shared_ptr<Attack>> AttackSystem::Punch::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	return attack;
}

void AttackSystem::Punch::Update()
{
	Attack::Update();
	m_life_span_timer.Update();
}

void AttackSystem::Punch::Draw()
{

}
