//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.20
// 内容　：シーンの間に情報を持つゲームマネージャー
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

		///<summary>キャラクター選択情報を追加</summary>
		///<param name="job">ジョッブ、キャラ</param>
		///<param name="side">Team</param>
		///<param name="controller">コントローラー</param>
		void AddSelectCharacter(
			std::shared_ptr<Job::JobBase> job,
			Side side,
			std::shared_ptr<Character::VirtualController> controller);

		///<summary>キャラクター選択情報を取得</summary>
		std::vector<SelectInfo> GetSelectInfo();

		///<summary>Listをクリア</summary>
		void Clear();

		///<summary>Pauseが押されたか</summary>
		bool IsPause();
		///<summary>Pauseを押したキャラ</summary>
		std::shared_ptr<Character::VirtualController> PauseController();

	private:
		std::vector<SelectInfo> m_player_info;										//キャラクター選択情報
		std::vector<std::shared_ptr<Character::VirtualController>> m_controller;	//コントローラー

		std::shared_ptr<Character::VirtualController> m_pause_controller;
	};
}