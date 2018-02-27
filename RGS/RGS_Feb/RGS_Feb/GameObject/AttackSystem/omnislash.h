//-------------------------------------------------------
// �쐬�ҁF�V�X�����g���T
// �쐬���F2018.02.23
// ���e�@�F�U���i�I���j�X���b�V���j�̓����蔻��
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>
#include <Device\MotionSystem\motion.h>

namespace AttackSystem
{
	class OmniSlash : public Attack
	{
	public :
		///<summary>�R���X�g���N�^</summary>
		///<param name = "side">�L�����N�^�[�͂ǂ�ȃ`�[���ɑ�����</param>
		///<param name = "position">�L�����N�^�[�̈ʒu</param>
		///<param name = "size">�U���̑傫��</param>
		///<param name = "side">�L�����N�^�[�͂ǂ�ȃ`�[���ɑ�����</param>
		///<param name = "attack">�U���|�C���g</param>
		///<param name = "knockdown">�G��|�����邩�H</param>
		///<param name = "knockback">�G��������邩�H</param>
		///<param name = "life span">���b�Ɏ���������̂��H</param>
		OmniSlash(Math::Vector3 position, Math::Vector3 size, Side side, int attack, int knockdown, int knockback, int dbreak, int attackCount, std::string animationToPlay, float life_span_timer, Direction source_dir);
		~OmniSlash();
		virtual std::vector < std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		int m_c_attack;
		int m_c_knockdown;
		int m_c_knockback;
		int m_c_dbreak;
		int m_attack_count;

		std::string m_animationToPlay;

		Utility::Timer m_life_span_timer;

		std::shared_ptr<MotionSystem::Motion> m_motion;
	};
}

