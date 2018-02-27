//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.21
// ���e�@�F�����Ȃ�Ƃ��A�傫���Ȃ�Ƃ��O�ɒ����ɍs���X�L��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>
#include <Device\MotionSystem\motion.h>

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
		///<param name = "take damage at">
		Laser(Math::Vector3 first_position, Math::Vector3 size, Side side, std::string animation_to_play, int attack, int knockdown, int knockback, int dbreak, int damage_combo, float life_span_timer, float take_damage_at, Direction source_dir);
		~Laser();
		virtual std::vector <std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		int m_c_attack;
		int m_c_knockdown;
		int m_c_knockback;
		int m_c_dbreak;
		int m_damage_combo;
		float m_take_damage_at; // ���_���[�W���󂯂邩�H

		Math::Vector3 m_add_size;
		Math::Vector3 m_add_position;
		Utility::Timer m_life_span_timer;
		std::shared_ptr<MotionSystem::Motion> m_motion;
	};
}