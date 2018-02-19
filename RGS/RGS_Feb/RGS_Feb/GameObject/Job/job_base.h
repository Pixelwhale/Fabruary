//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：キャラクターのジョブのインタフェース
// 最後の更新　: 2017.02.15
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack_manager.h>
#include <GameObject\AttackSystem\punch.h>
#include <GameObject\AttackSystem\kick.h>
#include <Utility\timer.h>
#include <memory>
#include <Math\vector3.h>

namespace Job
{
	class JobBase
	{
	public:
		virtual void Punch(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Kick(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Skill1(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Skill2(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Skill3(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Skill4(AttackSystem::AttackManager &attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual void Update() = 0;
	};
}