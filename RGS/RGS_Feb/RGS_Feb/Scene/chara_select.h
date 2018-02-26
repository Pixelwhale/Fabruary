//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.22
// 内容　：シーンのベースクラス
//-------------------------------------------------------
#pragma once
#include "scene_base.h"
#include "game_manager.h"
#include <Utility\timer.h>
#include <GameObject\Background\background.h>
#include <GameObject\Background\change_scene_effect.h>

namespace Scene
{
	enum SceneState
	{
		kStartAnim,
		kJobSelect,
		kCountToGo,
		kReturnSelectInfo,
		kEndAnim,
	};

	struct Player
	{
		int controller_num = -1;
		bool occupied = false;
		int job = 0;
		bool lock = false;
	};

	class CharaSelect : public SceneBase
	{
	public:
		CharaSelect(std::shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect, std::shared_ptr<GameManager> game_mgr);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		SceneState m_scene_state;
		std::shared_ptr<GameManager> m_game_mgr;
		std::shared_ptr<Background> m_background;
		std::shared_ptr<SceneEffect> m_scene_effect;
		float m_ui_alpha;

		Player *m_player;
		bool m_controller[5];	//check if controller is bind. (avoid repeat bind)

		Utility::Timer m_timer;
		bool m_back_to_title;

		bool CheckBackToTitle();
		int MinIndex();		//return 0~3 (1P~4P)
		bool CheckJoin();
		void JobSelect(int player_num);
		void KbSelect(int player_num);
		void PadSelect(int player_num, int pad_num);
		bool CheckKbUnlock(int player_num);
		bool CheckPadUnlock(int player_num, int pad_num);
		bool CheckAllLock();
		void AddChara();
	};
}
