//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.21
// 内容　：長くなるとか、大きくなるとか前に直線に行くスキル
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\summoning_type.h>

using namespace AttackSystem;

//コンストラクタ
SummoningType::SummoningType(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, float life_span_timer)
	: Attack(position, size, side, attack, knockdown, knockback), m_life_span_timer(life_span_timer)
{

}

//デストラクタ
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