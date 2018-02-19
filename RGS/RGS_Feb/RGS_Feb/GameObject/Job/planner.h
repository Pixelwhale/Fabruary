//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.19
// 内容　：Job Class - プランナー
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
		void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		void Update();

	private :
		int m_punch_count_max = 2; // プログラマーのパンチコンボの最大値
		int m_punch_count = 0; // 今は何番のパンチ
		int m_punch_last_update = 0; // 時間をリセットするために
		Utility::Timer m_next_combo; // 次のコンボに進めるかの制限時間？
		Side m_side;
	};
}