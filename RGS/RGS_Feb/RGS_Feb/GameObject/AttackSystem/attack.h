//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
// ���e�F�U���̃C���^�[�t�F�[�X�B
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Math\collision_box.h>
#include <Character\side.h>
#include <Def\size.h>
#include <vector>
#include <memory>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size, Side side, int atk, int knockdown, int knockback, bool repeat_hit = false);

		//�L�����ɓ������Attack���g�̃��A�N�V����
		//Attacks�����AttackManager�ɓ����B
		virtual std::vector<std::shared_ptr<Attack>>& Collide() = 0;

		virtual void Update() = 0;
		virtual void Draw() = 0;

		Math::CollisionBox GetBox()
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}

		float GetPositionX() { return m_position.x; }
		Side GetSide() { return m_side; }
		int GetAtk() { return m_atk; }
		int GetKnockBack() { return m_knockback; }
		int GetKnockDown() { return m_knockdown; }

		//�d������ɂ������
		bool IsRepeat() { return m_repeat_hit; }
		void AddID(int ID) { m_attacked_list.push_back(ID); }
		std::vector<int>& GetAttackedList() { return m_attacked_list; }

		bool IsEnd() { return m_is_end; }

	protected:
		//CollisionBox�̐����p
		Math::Vector3 m_position;		//CollisionBox�̒��S�ʒu
		Math::Vector3 m_size;			//CollisionBox�̑傫��

		Side m_side;

		int m_atk;			//�U����
		int m_knockback;	//���ނ̋���
		int m_knockdown;	//�|���l�A�L�����̏���l������Ɠ|���

		bool m_is_end;

		bool m_repeat_hit;		//�d������ł���X�L����true
		std::vector<int> m_attacked_list;
	};
}
