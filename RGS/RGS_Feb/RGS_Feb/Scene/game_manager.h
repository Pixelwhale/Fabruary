//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.20
// ���e�@�F�V�[���̊Ԃɏ������Q�[���}�l�[�W���[
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\character_controller.h>
#include <Character\side.h>
#include <memory>
#include <vector>

namespace Job
{
	class JobBase;
}

namespace Scene
{
	struct SelectInfo
	{
		Side m_side;
		std::shared_ptr<Job::JobBase> m_job;
		std::shared_ptr<Character::VirtualController> m_controller;
	};

	class GameManager
	{
	public:
		GameManager();
		GameManager(const GameManager&);
		~GameManager();

		///<summary>�L�����N�^�[�I������ǉ�</summary>
		///<param name="job">�W���b�u�A�L����</param>
		///<param name="side">Team</param>
		///<param name="controller">�R���g���[���[</param>
		void AddSelectCharacter(
			std::shared_ptr<Job::JobBase> job,
			Side side,
			std::shared_ptr<Character::VirtualController> controller);

		///<summary>�L�����N�^�[�I�������擾</summary>
		std::vector<SelectInfo> GetSelectInfo();

		///<summary>List���N���A</summary>
		void Clear();

		///<summary>Pause�������ꂽ��</summary>
		bool IsPause();
		///<summary>Pause���������L����</summary>
		std::shared_ptr<Character::VirtualController> PauseController();

	private:
		std::vector<SelectInfo> m_player_info;										//�L�����N�^�[�I�����
		std::vector<std::shared_ptr<Character::VirtualController>> m_controller;	//�R���g���[���[

		std::shared_ptr<Character::VirtualController> m_pause_controller;
	};
}