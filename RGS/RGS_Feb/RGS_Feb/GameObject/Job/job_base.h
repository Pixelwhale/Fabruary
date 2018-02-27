//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.05
// 内容　：キャラクターのジョブのインタフェース
// 最後の更新　: 2017.02.15
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack_mediator.h>
#include <Def\size.h>
#include <Utility\timer.h>
#include <memory>
#include <Math\vector3.h>

namespace Job
{
	struct SoundEffectStorage
	{
		Utility::Timer play_time;
		std::string sound_name;
	};

	class JobBase
	{
	public:
		virtual std::string Punch(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual std::string Kick(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual std::string Skill1(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual std::string Skill2(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual std::string Skill3(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual std::string Skill4(std::shared_ptr<AttackSystem::AttackMediator> attack_manager, Math::Vector3 position, bool is_right) = 0;
		virtual int KnockValue() = 0;
		virtual int GetHp() = 0;
		virtual void Update() = 0;


	protected:
		std::vector<SoundEffectStorage> m_sound_storage;
	};
}