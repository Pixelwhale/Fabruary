//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.05
// 内容：Attackの更新と描画
//-------------------------------------------------------
#pragma once
#include <Math\collision_box.h>
#include <memory>
#include <vector>

namespace Character
{
	class CharacterBase;
}

namespace AttackSystem
{
	class Attack;

	class AttackManager
	{
	public:
		AttackManager();
		~AttackManager();
		void Initialize();

		void AddAttack(std::shared_ptr<Attack>);
		void Update();
		void Draw();

		//attackとcharacterのcollision boxを生成して判定する
		bool IsCollision(std::shared_ptr<Attack> a, std::shared_ptr<Character::CharacterBase> c);
	private:
		void AddAttack();
		void Remove();

		std::vector<std::shared_ptr<Attack>> m_atk_list;
		std::vector<std::shared_ptr<Attack>> m_add_list;
	};
}