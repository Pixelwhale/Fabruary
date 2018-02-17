//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2017.02.05
// 内容　：キャラクターのジョブのインタフェース
// 最後の更新　: 2017.02.15
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AttackSystem\punch.h>
#include <memory>
#include <Math\vector3.h>

namespace Job
{
	class JobBase
	{
	public:
		virtual void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		virtual void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		virtual void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		virtual void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		virtual void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		virtual void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, Math::Vector3 size, bool is_left, float life_span_timer);
		void CharacterTraits(int punch_count, int kick_count)
		{
			m_punch_count = punch_count;
			m_kick_count = kick_count;
		};
		Side GetSide()
		{
			return side;
		}
	private:
		int m_punch_count;
		int m_kick_count;
		Side side;
	};
}