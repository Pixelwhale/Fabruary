//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.22
// ���e�@�F�_���[�W��S�����铖���蔻��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class Damage : public Attack
	{
	public :
		///<summary>�R���X�g���N�^</summary>
		///<param name = "side">�L�����N�^�[�͂ǂ�ȃ`�[���ɑ�����</param>
		///<param name = "position">�L�����N�^�[�̈ʒu</param>
		///<param name = "size">�U���̑傫��</param>
		///<param name = "life span">���b�Ɏ���������̂��H</param>
		Damage(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer);
		~Damage();
		virtual std::vector<std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;	// �܂��������Ă��邩�H
	};
}