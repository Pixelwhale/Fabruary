//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.19
// ���e�@�FJob Class - �v�����i�[
// �Ō�̍X�V : 2018.02.21
//-------------------------------------------------------

#pragma once
#include <GameObject\Job\job_base.h>
#include <Character\side.h>
#include <Device/sound.h>

namespace Job
{
	class Planner : public JobBase
	{
	public :
		Planner(Side side);
		~Planner();
		virtual std::string Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual int KnockValue();
		virtual int GetHp();
		virtual void Update();

	private :
		int m_punch_count_max = 5; // �v�����i�[�̃p���`�R���{�̍ő�l
		int m_punch_count = 0; // ���͉��Ԃ̃p���`
		Utility::Timer m_next_combo; // ���̃R���{�ɐi�߂邩�̐������ԁH
		int m_hp = 550;
		Side m_side;


		std::shared_ptr<Device::Sound> m_sound;
	};
}