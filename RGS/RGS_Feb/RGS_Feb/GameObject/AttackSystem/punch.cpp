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
	: Attack(position, size, side, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{	
	m_timer = 17;
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;

	m_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_motion->Initialize();
	m_motion->Play("skill_effect/skill_omnislash", 1);
	m_motion->SetPosition(m_position + m_size);
}

// デストラクタ
Punch::~Punch() {}

std::vector<std::shared_ptr<Attack>> Punch::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	if (m_life_span_timer.GetCurrentTimes() <= (0.3 * 60))
		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position, m_size * (1 - m_life_span_timer.Rate()), m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_dbreak, m_life_span_timer.GetCurrentTimes()));
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
	m_motion->Update();
}

void AttackSystem::Punch::Draw()
{
	m_motion->Draw();
}
