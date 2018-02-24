//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.22
// 内容　：シーンのベースクラス
//-------------------------------------------------------
#pragma once
#include "scene_base.h"
#include "game_manager.h"
#include <Utility\timer.h>

namespace Scene
{
	enum SceneState
	{
		kStartAnim,
		kCharaSelect,
		kCountToGo,
		kReturnSelectInfo,
		kEndAnim,
	};

	class CharaSelect : public SceneBase
	{
	public:
		CharaSelect(std::shared_ptr<GameManager> game_mgr);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		SceneState m_scene_state;
		std::shared_ptr<GameManager> m_game_mgr;

		int m_player_count;

		//参戦した？
		//first index:controller
		//second index: state(not join,select,lock)(-1~1) and"1P~4P(0~3) 
		int **m_controller;

		//index: [0~3] 1P~4P
		bool *m_occupied;
		bool *m_lock;
		//value: 0:planner 1:business 2:CG 3:programmer
		int *m_job;

		Utility::Timer timer;

		int MinIndex();		//return 0~3 (1P~4P)
		void KbSelect();
		void PadSelect(int index);
		void CheckPlayerSet();
		void AddChara();
	};
}
