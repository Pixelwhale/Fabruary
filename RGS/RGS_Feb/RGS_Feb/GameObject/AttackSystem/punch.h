//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2017.02.15
// ���e�@�F�U���i�p���`�j�̓����蔻��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class Punch : public Attack
	{
	public:
		///<summary>�R���X�g���N�^</summary>
		///<param name = "side">�L�����N�^�[�͂ǂ�ȃ`�[���ɑ�����</param>
		///<param name = "position">�L�����N�^�[�̈ʒu</param>
		///<param name = "size">�U���̑傫��</param>
		///<param name = "life span">���b�Ɏ���������̂��H</param>
		Punch(Side side, Math::Vector3 position, Math::Vector3 size, float life_span_timer);
		~Punch();
		virtual void Collide();
		virtual void Update();
		virtual void Draw();

	private:
		Utility::Timer m_life_span_timer; // �܂��������Ă��邩�H
	};
}