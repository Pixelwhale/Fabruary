//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.19
// 内容　：Job Class - プランナー
// 最後の更新 : 2018.02.21
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
		int m_punch_count_max = 5; // プランナーのパンチコンボの最大値
		int m_punch_count = 0; // 今は何番のパンチ
		Utility::Timer m_next_combo; // 次のコンボに進めるかの制限時間？
		int m_hp = 550;
		Side m_side;


		std::shared_ptr<Device::Sound> m_sound;
	};
}