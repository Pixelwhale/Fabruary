//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
//-------------------------------------------------------
#pragma once
#include "attack.h"

namespace AttackSystem
{
	class AttackMediator
	{
		virtual void AddAttack(std::shared_ptr<Attack>) = 0;
	};
}