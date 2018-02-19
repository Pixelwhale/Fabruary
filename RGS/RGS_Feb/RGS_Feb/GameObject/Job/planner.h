//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.19
// ���e�@�FJob Class - �v�����i�[
//-------------------------------------------------------

#pragma once
#include <GameObject\Job\job_base.h>
namespace Job
{
	class Planner : public JobBase
	{
	public :
		Planner(Side side);
		~Planner();
		virtual void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Update();

	private :
		int m_punch_count_max = 2; // �v���O���}�[�̃p���`�R���{�̍ő�l
		int m_punch_count = 0; // ���͉��Ԃ̃p���`
		int m_punch_last_update = 0; // ���Ԃ����Z�b�g���邽�߂�
		Utility::Timer m_next_combo; // ���̃R���{�ɐi�߂邩�̐������ԁH
		Side m_side;
	};
}