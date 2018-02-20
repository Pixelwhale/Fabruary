//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：Job Class - プログラマー
// 最後の更新 : 2018.02.19
//-------------------------------------------------------
#pragma once
#include <GameObject\Job\job_base.h>
#include <Character\side.h>

namespace Job
{
	class Programmer : public JobBase
	{
	public :
		Programmer(Side side);
		~Programmer();
		virtual std::string Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position,bool is_right);
		virtual std::string Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual std::string Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right);
		virtual int KnockValue() = 0;
		virtual int GetHp();
		virtual void Update();

	private :
		int m_punch_count_max = 3; // プログラマーのパンチコンボの最大値
		int m_punch_count = 0; // 今は何番のパンチ
		int m_punch_last_update = 0; // 時間をリセットするために
		Utility::Timer m_next_combo; // 次のコンボに進めるかの制限時間？
		int m_hp;
		Side m_side;
	};
}
