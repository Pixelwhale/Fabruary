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
		Programmer(Side side);
		~Programmer();
		void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position,bool is_right);
		void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Update();

	private :
		int m_punch_count_max = 3; // �v���O���}�[�̃p���`�R���{�̍ő�l
		int m_punch_count = 0; // ���͉��Ԃ̃p���`
		int m_punch_last_update = 0; // ���Ԃ����Z�b�g���邽�߂�
		Utility::Timer m_next_combo; // ���̃R���{�ɐi�߂邩�̐������ԁH
		Side m_side;
	};
}
