//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
// ���e�F�U���̃C���^�[�t�F�[�X�B
//-------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace AttackSystem
{
	class Attack
	{
	public:
		Attack();
		virtual void Update() = 0;
		virtual void Draw() = 0;
		bool IsEnd() { return m_is_end; }
	private:
		short timer;		//�P�ʁFframe
		bool m_is_end;
		Math::Vector3 m_position;		//CollisionBox�̒��S�ʒu
	};
}
