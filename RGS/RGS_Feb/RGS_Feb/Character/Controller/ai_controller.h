//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FAi�Ő��䂷��L�����R���g���[���[
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\character_controller.h>

namespace Character 
{
	class AiController : public VirtualController
	{
	public:
		AiController(int player_num);
		AiController(const AiController&);
		~AiController();

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

	public:
		///<summary>Key����Update</summary>
		void Update();
		///<summary>�ړ��ʐݒ�</summary>
		void SetVelocity(Math::Vector3 velocity);
		///<summary>�p���`����</summary>
		void TriggerPunch();
		///<summary>�L�b�N����</summary>
		void TriggerKick();
		///<summary>�W�����v����</summary>
		void TriggerJump();
		///<summary>����</summary>
		void Run();
		///<summary>�h��</summary>
		void Defence();

	private:
		Math::Vector3 m_velocity;	//�ړ���
		bool m_previous_punch;		//�O�t���[���̃p���`�L�[
		bool m_current_punch;		//���t���[���̃p���`�L�[
		bool m_previous_kick;		//�O�t���[���̃L�b�N�L�[
		bool m_current_kick;		//���t���[���̃L�b�N�L�[
		bool m_run;					//���邩
		bool m_previous_jump;		//�O�t���[���̃W�����v�L�[
		bool m_current_jump;		//���t���[���̃W�����v�L�[
		bool m_defence;				//�h�䂷�邩
	};
}