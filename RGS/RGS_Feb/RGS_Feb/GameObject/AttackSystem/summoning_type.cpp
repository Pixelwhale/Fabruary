//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.21
// ���e�@�F�����Ȃ�Ƃ��A�傫���Ȃ�Ƃ��O�ɒ����ɍs���X�L��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\summoning_type.h>

using namespace AttackSystem;

//�R���X�g���N�^
SummoningType::SummoningType(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, attack, knockdown, knockback), m_life_span_timer(life_span_timer)
{

}

//�f�X�g���N�^
SummoningType::~SummoningType() {};

std::vector<std::shared_ptr<Attack>>& SummoningType::Collide()
{
	std::vector<std::shared_ptr<Attack>> attack;
	return attack;
}

void SummoningType::Update()
{
	m_life_span_timer.Update();
}

void SummoningType::Draw()
{

}