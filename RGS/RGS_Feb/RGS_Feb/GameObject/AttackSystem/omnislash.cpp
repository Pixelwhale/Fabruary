//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.23
// 内容　：攻撃（オムニスラッシュ）の当たり判定
//-------------------------------------------------------

#include <GameObject\AttackSystem\omnislash.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

OmniSlash::OmniSlash(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, int attackCount, std::string animationToPlay, float life_span_timer, Direction source_dir)
	: Attack(position, size, side, 0, 0, 0, 0, 0, source_dir), m_life_span_timer(life_span_timer)
{
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;
	m_attack_count = attackCount;
	m_animationToPlay = animationToPlay;

	m_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_motion->Initialize();
	m_motion->Play(animationToPlay, 1);
	if (source_dir == AttackSystem::kRight)
	{
		m_motion->Flip(true, false);
		size.x *= -1;
	}
	m_motion->SetPosition(m_position + Math::Vector3(-size.x, 0, 0));
}

// デストラクタ
OmniSlash::~OmniSlash() 
{
	m_motion = NULL;
}

std::vector<std::shared_ptr<Attack>> OmniSlash::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	if (m_life_span_timer.Rate() <= 0.4 && m_attack_count != 0)
	{
		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position, m_size, m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_dbreak, "Effect/slash", m_life_span_timer.Rate()));
		m_attack_count--;
		if (m_attack_count == 0) m_cool_down = -1;
	}
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
	m_motion->Update();
}

void AttackSystem::OmniSlash::Draw()
{
	m_motion->Draw();
}

