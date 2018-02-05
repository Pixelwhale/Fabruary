//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2017.02.05
// 内容　：キャラクターのジョブのインタフェース
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack_manager.h>
#include <memory>
#include <Math\vector3.h>

namespace Job
{
	class JobBase
	{
	public:
		virtual void Skill1(AttackManager::AttackManager &attack_manager, Math::Vector3 position);
		virtual void Skill2(AttackManager::AttackManager &attack_manager, Math::Vector3 position);
		virtual void Skill3(AttackManager::AttackManager &attack_manager, Math::Vector3 position);
		virtual void Skill4(AttackManager::AttackManager &attack_manager, Math::Vector3 position);
	};
}