//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.15
// 内容　：Job Class - ビジネス
// 最後の更新 : 2018.02.19
//-------------------------------------------------------
#pragma once
#include <GameObject\Job\job_base.h>
#include <Math\vector3.h>

namespace Job
{
	class Business : public JobBase
	{
	public:
		Business(Side side);
		~Business();
		virtual void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right);
		virtual void Update();

	private:
		int m_punch_count_max = 3; // プログラマーのパンチコンボの最大値
		int m_punch_count = 0; // 今は何番のパンチ
		int m_punch_last_update = 0; // 時間をリセットするために
		Utility::Timer m_next_combo; // 次のコンボに進めるかの制限時間？
		Side m_side;
	};
}
