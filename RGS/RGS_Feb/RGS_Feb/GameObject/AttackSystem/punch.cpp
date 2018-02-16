//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2017.02.15
// ���e�@�F�U���i�p���`�j�̓����蔻��
//-------------------------------------------------------

#include <GameObject\AttackSystem\punch.h>

using namespace AttackSystem;

Punch::Punch(Side side, Math::Vector3 position, Math::Vector3 size, float life_span_timer)
	: Attack(side, position, size), m_life_span_timer(life_span_timer)
{	
}

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
