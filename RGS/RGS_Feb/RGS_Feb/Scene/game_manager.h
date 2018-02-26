//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.20
// ���e�@�F�V�[���̊Ԃɏ������Q�[���}�l�[�W���[
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\character_controller.h>
#include <Character\Controller\ai_controller.h>
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
		std::shared_ptr<Character::VirtualController> m_ai_controller;
		int m_difficulty;
	};

	class GameManager
	{
	public:
		GameManager();
		GameManager(const GameManager&);
		~GameManager();

#pragma region �L�����N�^�[�I���֘A

		///<summary>�L�����N�^�[�I������ǉ�</summary>
		///<param name="job">�W���b�u�A�L����</param>
		///<param name="side">Team</param>
		///<param name="controller">�R���g���[���[</param>
		void AddSelectCharacter(
			std::shared_ptr<Job::JobBase> job,
			Side side,
			std::shared_ptr<Character::VirtualController> controller);

		///<summary>�L�����N�^�[�I������ǉ�</summary>
		///<param name="job">�W���b�u�A�L����</param>
		///<param name="side">Team</param>
		///<param name="player_num">PlayerNumber</param>
		///<param name="difficulty">com�̋����iPlayer�ݒ肵�Ă��Ӗ����Ȃ��j</param>
		void AddSelectAI(
			std::shared_ptr<Job::JobBase> job,
			Side side,
			std::shared_ptr<Character::VirtualController> controller,
			int difficulty);

		///<summary>�L�����N�^�[�I�������擾</summary>
		std::vector<SelectInfo> GetSelectInfo();

		///<summary>List���N���A</summary>
		void Clear();
#pragma endregion

#pragma region Pause�֘A

		///<summary>Pause�������ꂽ��</summary>
		bool IsPause();
		///<summary>Pause���������L����</summary>
		std::shared_ptr<Character::VirtualController> PauseController();

#pragma endregion

#pragma region Winner�֘A

		///<summary>�����҂�ݒ�</summary>
		void SetWinner(std::vector<shared_ptr<MotionSystem::Motion>> motion);
		///<summary>�����҂̃��[�V�������擾</summary>
		std::vector<shared_ptr<MotionSystem::Motion>> WinnerMotion();
		///<summary>���[�V�������폜</summary>
		void ClearWinnerMotion();

#pragma endregion

	private:
		std::vector<SelectInfo> m_player_info;										//�L�����N�^�[�I�����
		std::vector<std::shared_ptr<Character::VirtualController>> m_controller;	//�R���g���[���[

		std::shared_ptr<Character::VirtualController> m_pause_controller;			//Pause���������R���g���[���[
		std::vector<shared_ptr<MotionSystem::Motion>> m_winner_motion;				//WinnerMotion
	};
}