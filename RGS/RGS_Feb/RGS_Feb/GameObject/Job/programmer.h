#pragma once
#include <GameObject\Job\job_base.h>

namespace Job
{
	class Programmer : public JobBase
	{
	public :
		void Skill1(AttackManager::AttackManager &attack_manager, Math::Vector3 position);

		void Skill2(AttackManager::AttackManager &attack_manager, Math::Vector3 position);

		void Skill3(AttackManager::AttackManager &attack_manager, Math::Vector3 position);

		void Skill4(AttackManager::AttackManager &attack_manager, Math::Vector3 position);
	};
}
