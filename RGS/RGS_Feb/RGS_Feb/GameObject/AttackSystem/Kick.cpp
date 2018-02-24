//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�U���i�L�b�N�j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\kick.h>
#include <GameObject\AttackSystem\damage.h>

using namespace AttackSystem;

// �R���X�g���N�^
Kick::Kick(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(position, size, side, 0, 0, 0, 0, 0), m_life_span_timer(life_span_timer)
{
	m_c_attack = attack;
	m_c_knockback = knockback;
	m_c_knockdown = knockdown;
	m_c_break = dbreak;
}

// �f�X�g���N�^
Kick::~Kick() {}


std::vector<std::shared_ptr<Attack>> AttackSystem::Kick::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	if (m_life_span_timer.Rate() <= 0.3)
	{
		attack.push_back(std::make_shared<AttackSystem::Damage>(m_position, m_size, m_side, m_c_attack, m_c_knockback, m_c_knockdown, m_c_break, "Effect/slash", m_life_span_timer.Rate()));
		m_cool_down = -1;
	}
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
