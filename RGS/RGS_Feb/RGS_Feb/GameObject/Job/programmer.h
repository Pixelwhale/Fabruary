//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2017.02.15
// ���e�@�FJob Class - �v���O���}�[
//-------------------------------------------------------
#pragma once
#include <GameObject\Job\job_base.h>

namespace Job
{
	class Programmer : public JobBase
	{
	public :
		Programmer(int punch_count, int kick_count);
		~Programmer();
		void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
		void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
		void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
		void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
		void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
		void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, int knockdown, int knockback, bool is_left, float life_span_timer);
	};
}
