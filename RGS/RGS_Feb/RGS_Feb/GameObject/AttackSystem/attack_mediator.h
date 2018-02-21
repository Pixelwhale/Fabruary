//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.20
//-------------------------------------------------------
#pragma once
#include <memory>
#include "attack.h"

namespace AttackSystem
{
	class AttackMediator
	{
	public:
		virtual void AddAttack(std::shared_ptr<Attack>) = 0;
		virtual const std::vector<std::shared_ptr<Attack>>& GetAttackList() const = 0;
	};
}