//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.15
// ���e�@�F�U���i�p���`�j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\punch.h>

using namespace AttackSystem;

// �R���X�g���N�^
Punch::Punch(Math::Vector3 position, Math::Vector3 size, Side side, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, knockdown, knockback), m_life_span_timer(life_span_timer)
{	
}

// �f�X�g���N�^
Punch::~Punch() {}

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
