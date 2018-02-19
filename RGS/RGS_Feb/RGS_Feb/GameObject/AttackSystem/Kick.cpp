//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�U���i�L�b�N�j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\kick.h>

using namespace AttackSystem;

// �R���X�g���N�^
Kick::Kick(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, knockdown, knockback), m_life_span_timer(life_span_timer)
{
}

// �f�X�g���N�^
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
