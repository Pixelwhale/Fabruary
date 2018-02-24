//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.22
// 内容　：ダメージを担当する当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

// コンストラクタ
Damage::Damage(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, std::string animationToPlay, float life_span_timer)
	: Attack (position, size, side, attack, knockdown, knockback, dbreak), m_life_span_timer (life_span_timer)
{
	m_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_motion->Initialize();
	m_motion->Play(animationToPlay, 1);
	m_motion->SetPosition(m_position);
}

// デストラクタ
Damage::~Damage() 
{
	m_motion = NULL;
}

std::vector<std::shared_ptr<Attack>> AttackSystem::Damage::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();

	return attack;
}

void AttackSystem::Damage::Update()
{
	Attack::Update();
	m_life_span_timer.Update();
	if (m_life_span_timer.IsTime())
	{
		m_is_end = true;
	}
	m_motion->Update();
}

void AttackSystem::Damage::Draw()
{
	m_motion->Draw();
}