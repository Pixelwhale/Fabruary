//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.21
// ���e�@�F�����Ȃ�Ƃ��A�傫���Ȃ�Ƃ��O�ɒ����ɍs���X�L��
//-------------------------------------------------------

#include <GameObject\AttackSystem\laser.h>

using namespace AttackSystem;

Laser::Laser(Math::Vector3 first_position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, Math::Vector3 added_position, Math::Vector3 added_size, float life_span_timer)
	: Attack (first_position, size, side, attack, knockdown, knockback, dbreak), m_life_span_timer(life_span_timer)
{
	m_added_position = added_position;
	m_added_size = added_size;
}

Laser::~Laser() {}

std::vector<std::shared_ptr<Attack>>& Laser::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	attack.clear();
	return attack;
}

void Laser::Update()
{
	m_life_span_timer.Update();
	if (!m_life_span_timer.IsTime())
	{
		m_position += m_added_position;
		m_size += m_added_size;
	}
}

void Laser::Draw()
{

}