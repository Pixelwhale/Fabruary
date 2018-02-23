//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FPad�Ő��䂷��L�����R���g���[���[
//-------------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\Controller\character_controller.h>

namespace Character
{
	class PadController : public VirtualController
	{
	public:
		///<summary>Pad_ID��0�`3�܂�</summary>
		PadController(int pad_id, int player_num);
		PadController(const PadController&);
		~PadController();

		///<summary>�ړ���</summary>
		Math::Vector3 virtual Velocity();
		///<summary>Punch�����������H</summary>
		bool virtual IsPunchTrigger();
		///<summary>Kick�����������H</summary>
		bool virtual IsKickTrigger();
		///<summary>Run��������Ă��邩�H</summary>
		bool virtual IsRun();
		///<summary>Jump�����������H</summary>
		bool virtual IsJumpTrigger();
		///<summary>Defence��������Ă��邩�H</summary>
		bool virtual IsDefence();

		///<summary>����L�����̃q���g�`��</summary>
		void virtual Draw(Math::Vector3 draw_pos);
		///<summary>�^�O�̐F�ݒ�i�ŏ��s�������j</summary>
		void virtual SetTagColor(Color color);
		///<summary>�^�O�X�V</summary>
		void virtual UpdateMotion();

	private:
		std::shared_ptr<Core::InputState> m_input;
		int m_pad_id;
	};
}