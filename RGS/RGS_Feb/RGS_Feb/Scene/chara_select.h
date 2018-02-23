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
		kControlTypeSelect,
		kCharaSelect,
		kEnd,
	};

	class CharaSelect : public SceneBase
	{
	public:
		CharaSelect();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}
