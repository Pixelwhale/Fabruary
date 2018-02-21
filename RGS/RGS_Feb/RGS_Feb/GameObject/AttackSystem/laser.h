//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.21
// ���e�@�F�����Ȃ�Ƃ��A�傫���Ȃ�Ƃ��O�ɒ����ɍs���X�L��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>

namespace AttackSystem
{
	class Laser : public Attack
	{
	public :
		///<summary>�R���X�g���N�^</summary>
		///<param name = "first position">�ŏ��̈ʒu</param>
		///<param name = "size">�X�L���̃T�C�Y</param>
		///<param name = "side">�T�C�h</param>
		///<param name = "attack">�U���|�C���g</param>
		///<param name = "knockdown">�G��|�����邩�H</param>
		///<param name = "knockback">�G��������邩�H</param>
		///<param name = "added position">�O�ɓ������邽��</param>
		///<param name = "added size">�T�C�Y���ύX�ł��邽��</param>
		///<param name = "life span">���b�Ɏ���������̂��H</param>
		Laser(Math::Vector3 first_position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, Math::Vector3 added_position, Math::Vector3 added_size, float life_span_timer);
		~Laser();
		virtual std::vector < std::shared_ptr<Attack>>& Collide();
		virtual void Update();
		virtual void Draw();

	private :
		Utility::Timer m_life_span_timer;
		Math::Vector3 m_added_position;
		Math::Vector3 m_added_size;
	};
}