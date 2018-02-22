//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：Pauseシーン
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Pause : public SceneBase
	{
	public:
		Pause(std::shared_ptr<SceneBase> game_play);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>エフェクト更新</summary>
		void UpdateEffect();
		///<summary>終了するかをチェック</summary>
		bool CheckEnd();

	private:
		std::shared_ptr<SceneBase> m_game_play;		//GamePlayシーン
		const int kBlurMax = 1000;					//ぼかし最大値

		int m_blur_ratio;							//ぼかし値
		bool m_blur_switch;							//ぼかしのSwitch
	};
}