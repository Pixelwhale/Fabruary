//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�F�L�����R���g���[���[�̃C���^�[�t�F�[�X
//-------------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Color\color.h>
#include <Device\MotionSystem\motion.h>

namespace Character 
{
	class VirtualController 
	{
	public:
		~VirtualController() {}

		///<summary>�ړ���</summary>
		Math::Vector3 virtual Velocity()					= 0;
		///<summary>Punch�����������H</summary>
		bool virtual IsPunchTrigger()						= 0;
		///<summary>Kick�����������H</summary>
		bool virtual IsKickTrigger()						= 0;
		///<summary>Run��������Ă��邩�H</summary>
		bool virtual IsRun()								= 0;
		///<summary>Jump�����������H</summary>
		bool virtual IsJumpTrigger()						= 0;
		///<summary>Defence��������Ă��邩�H</summary>
		bool virtual IsDefence()							= 0;
		///<summary>Pause�������ꂽ��</summary>
		bool virtual IsPause()								= 0;

		///<summary>����L�����̃q���g�`��</summary>
		void virtual Draw()									= 0;
		///<summary>�^�O�̐F�ݒ�i�ŏ��s�������j</summary>
		void virtual SetTagColor(Color color)				= 0;
		///<summary>�^�O�X�V</summary>
		void virtual UpdateMotion(Math::Vector3 draw_pos)	= 0;

		int PlayerNum() { return m_player_num; }

	protected:
		int m_player_num;							//�v���C���[��
		shared_ptr<MotionSystem::Motion> m_tag;		//Tag���[�V����
	};
}