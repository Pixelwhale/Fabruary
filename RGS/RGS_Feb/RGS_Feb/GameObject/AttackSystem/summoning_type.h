//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.21
// ���e�@�F���̃X�L���͍U���_���[�W���낾���A���̃X�L���ʂ𐶐�����B
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class SummoningType : public Attack
	{
	public :
		///<summary>�R���X�g���N�^</summary>
		///<param name = "side">�L�����N�^�[�͂ǂ�ȃ`�[���ɑ�����</param>
		///<param name = "position">�L�����N�^�[�̈ʒu</param>
		///<param name = "size">�U���̑傫��</param>
		///<param name = "attack">�U���|�C���g</param>
		///<param name = "knockdown">�G��|�����邩�H</param>
		///<param name = "knockback">�G��������邩�H</param>
		///<param name = "life span">���b�Ɏ���������̂��H</param>
		SummoningType(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, float life_span_timer);
		~SummoningType();
		virtual std::vector <std::shared_ptr<Attack>>& Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;
	};
}
