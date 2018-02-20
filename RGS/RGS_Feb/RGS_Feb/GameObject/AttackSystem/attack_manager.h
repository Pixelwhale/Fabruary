//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
// ���e�FAttack�̍X�V�ƕ`��
//-------------------------------------------------------
#pragma once
#include "attack_mediator.h"
#include <Math\collision_box.h>
#include <memory>
#include <vector>

namespace Character
{
	class CharacterBase;
	class CharacterManager;
}

namespace AttackSystem
{
	class Attack;

	class AttackManager : AttackMediator
	{
	public:
		AttackManager();
		~AttackManager();
		void Initialize();

		void AddAttack(std::shared_ptr<Attack>);
		void Update(std::shared_ptr<Character::CharacterManager> chara_mgr);
		void Draw();

		//attack��character��collision box�𐶐����Ĕ��肷��
		bool IsCollision(std::shared_ptr<Attack> atk, std::shared_ptr<Character::CharacterBase> c);
	private:
		void AddAttack();
		void Remove();

		std::vector<std::shared_ptr<Attack>> m_atk_list;
		std::vector<std::shared_ptr<Attack>> m_add_list;
	};
}