//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.22
// 内容　：シーンのベースクラス
//-------------------------------------------------------
#pragma once
#include "scene_base.h"
#include "game_manager.h"

namespace Scene
{
	enum State
	{
		kStartAnim,
		kCharaSelect,
		kPlayerSetCheck,
		kReturnSelectInfo,
		kEndAnim,
	};

	class CharaSelect : public SceneBase
	{
	public:
		CharaSelect();
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		State m_state;
		SelectInfo m_select_info[4];

		//参戦した？
		//index: [0]:keyboard , [1~4]:gamepad
		//value: 0: not join yet , 1~4:player num
		int m_controller[5];
		int m_player_count;

		//index: [1~4] player num
		bool m_enter[4];
		//value: 0:unselect 1:programmer 2:planner 3:CG 4:business
		int m_job[4];

		int MinIndex();
		void KbSelect();
		void PadSelect(int index);
		void CheckPlayerSet();
	};
}
