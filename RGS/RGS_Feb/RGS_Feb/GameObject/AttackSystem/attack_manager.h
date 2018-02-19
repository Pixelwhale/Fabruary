//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
// ���e�FAttack�̍X�V�ƕ`��
//-------------------------------------------------------
#pragma once
#include "attack.h"
#include "attack_mediator.h"
#include <Math\collision_box.h>
#include <memory>
#include <vector>

namespace Character
{
	class CharacterBase;
}

namespace AttackSystem
{
	

	class AttackManager
	{
	public:
		AttackManager();
		~AttackManager();
		void Initialize();

		void AddAttack(std::shared_ptr<Attack>);
		void Update();
		void Draw();

		//attack��character��collision box�𐶐����Ĕ��肷��
		bool IsCollision(Attack& a, Character::CharacterBase* c);
	private:
		void AddAttack();

		std::vector<std::shared_ptr<Attack>> m_atk_list;
		std::vector<std::shared_ptr<Attack>> m_add_list;
	};
}