//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.05
// 内容：Attackの更新と描画
//-------------------------------------------------------
#pragma once
#include "attack_mediator.h"
#include "attack.h"
#include <Character\character_base.h>
#include <Character\character_manager.h>
#include <Math\collision_box.h>
#include <memory>
#include <vector>

namespace AttackSystem
{
	class AttackManager : public AttackMediator
	{
	public:
		AttackManager();
		~AttackManager();
		void Initialize();

		void AddAttack(std::shared_ptr<Attack>);
		const std::vector<std::shared_ptr<Attack>>& GetAttackList() const { return m_atk_list; }
		void Update(std::shared_ptr<Character::CharacterManager> chara_mgr);
		void Draw();
	private:
		void AddAttack();
		void Remove();

		//attackとcharacterのcollision boxを生成して判定する
		bool IsCollision(const std::shared_ptr<const Attack> atk, const std::shared_ptr<Character::CharacterBase> c);

		std::vector<std::shared_ptr<Attack>> m_atk_list;
		std::vector<std::shared_ptr<Attack>> m_add_list;
	};
}