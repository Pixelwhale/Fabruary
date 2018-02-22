//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�U���i�L�b�N�j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\kick.h>

using namespace AttackSystem;

// �R���X�g���N�^
Kick::Kick(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer)
	: Attack(position, size, side, attack, knockdown, knockback, dbreak), m_life_span_timer(life_span_timer)
{
}

// �f�X�g���N�^
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
