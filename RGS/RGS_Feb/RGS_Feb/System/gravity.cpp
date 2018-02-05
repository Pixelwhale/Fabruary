//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.02.05
//-------------------------------------------------------
#include "gravity.h";

using namespace System;

Gravity::Gravity()
{
	m_on_ground = true;
}

Gravity::~Gravity()
{
}

void Gravity::Update(Math::Vector3& velocity)
{
	if (!m_on_ground) velocity.y -= kG / 60;
}