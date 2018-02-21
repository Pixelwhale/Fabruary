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
	enum Direction
	{
		kCenter,
		kRight,
		kLeft,
	};
	struct Attacked
	{
		Attacked(int id, int cool_down) : id(id), cool_down(cool_down) {}
		int id;
		int cool_down;
	};

	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size, Side side, int dmg, int knockdown, int knockback, int dbreak, int cool_down = -1, Direction source_dir = kCenter);

		//�L�����ɓ������Attack���g�̃��A�N�V����
		//Attacks�����AttackManager�ɓ����B
		virtual std::vector<std::shared_ptr<Attack>>& Collide() = 0;

		virtual void Update()
		{
			//attacked cool down��Update
			for (auto attacked : m_attacked_list) { --attacked.cool_down; }
		};

		virtual void Draw() = 0;

		Math::CollisionBox GetBox() const
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}

		const Math::Vector3& GetPosition() const { return m_position; }
		Side GetSide() const { return m_side; }
		int GetAtk() const { return m_atk; }
		int GetKnockBack() const { return m_knockback; }
		int GetKnockDown() const { return m_knockdown; }
		int GetBreak() const { return m_break; }

		//�d������ɂ������
		int IsRepeat() const { return m_cool_down; }
		void AddID(int id) { m_attacked_list.push_back(Attacked(id, m_cool_down)); }
		const std::vector<Attacked>& GetAttackedList() const { return m_attacked_list; }

		Direction GetSourceDir() const { return m_source_dir; }

		bool IsEnd() const { return m_is_end; }

	protected:
		//CollisionBox�̐����p
		Math::Vector3 m_position;		//CollisionBox�̒��S�ʒu
		Math::Vector3 m_size;			//CollisionBox�̑傫��

		Side m_side;

		int m_dmg;			//�U����
		int m_knockback;	//���ނ̋���
		int m_knockdown;	//�|���l
		int m_break;		//�h�������l

		bool m_is_end;

		int m_cool_down;		//�L�����̓t���[�����Ƃɔ��肷��B�d�����肵�Ȃ��X�L����-1�ɐݒ肷��
		std::vector<Attacked> m_attacked_list;

		Direction m_source_dir;
	};
}
