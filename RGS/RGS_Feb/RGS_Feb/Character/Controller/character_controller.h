//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�F�L�����R���g���[���[�̃C���^�[�t�F�[�X
//-------------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace Character 
{
	class VirtualController 
	{
	public:
		~VirtualController() {}

		///<summary>�ړ���</summary>
		Math::Vector3 virtual Velocity()	= 0;
		///<summary>Punch�����������H</summary>
		bool virtual IsPunchTrigger()		= 0;
		///<summary>Kick�����������H</summary>
		bool virtual IsKickTrigger()		= 0;
		///<summary>Run��������Ă��邩�H</summary>
		bool virtual IsRun()				= 0;
		///<summary>Jump�����������H</summary>
		bool virtual IsJumpTrigger()		= 0;
		///<summary>Defence��������Ă��邩�H</summary>
		bool virtual IsDefence()			= 0;

	private:
	};
}