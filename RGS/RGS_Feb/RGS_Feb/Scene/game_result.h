//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：ゲーム終了シーン
//-------------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class GameResult : public SceneBase
	{
	public:
		GameResult(std::shared_ptr<SceneBase> game_scene);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		void CheckEnd();

	private:
		std::shared_ptr<SceneBase> m_game_scene;				//GamePlayシーン
	};
}