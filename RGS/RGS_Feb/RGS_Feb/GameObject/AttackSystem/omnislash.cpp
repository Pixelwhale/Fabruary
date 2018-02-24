//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.23
// ���e�@�F�U���i�I���j�X���b�V���j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\omnislash.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

OmniSlash::OmniSlash(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, int attackCount, std::string animationToPlay, float life_span_timer)
	: Attack(position, size, side, 0, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_dbreak = dbreak;
	m_attack_count = attackCount;
	m_animationToPlay = animationToPlay;
}

// �f�X�g���N�^
OmniSlash::~OmniSlash() {}

std::vector<std::shared_ptr<Attack>> OmniSlash::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	if (m_life_span_timer.Rate() <= 0.4 && m_attack_count != 0)
	{
		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position, m_size, m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_dbreak, m_animationToPlay, m_life_span_timer.Rate()));
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
}

void AttackSystem::OmniSlash::Draw()
{

}

