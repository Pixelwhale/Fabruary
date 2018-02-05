//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.02.05
//-------------------------------------------------------
#include "gravity.h";

using namespace System;

void Gravity::Update(Math::Vector3& velocity)
{
	velocity.y -= kG / 60;
}