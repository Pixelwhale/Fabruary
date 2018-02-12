//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
// ���e�F�U���̃C���^�[�t�F�[�X�B
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Math\collision_box.h>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack(Math::Vector3 position, Math::Vector3 size) : m_position(position), m_size(size) {};
		virtual void Collide() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
		bool IsEnd() { return m_is_end; }
		Math::CollisionBox GetBox()
		{
			return Math::CollisionBox(m_position - m_size / 2, m_position + m_size / 2);
		}
	private:
		bool m_is_end;

		//CollisionBox�̐����p
		Math::Vector3 m_position;		//CollisionBox�̒��S�ʒu
		Math::Vector3 m_size;			//CollisionBox�̑傫��
	};
}
