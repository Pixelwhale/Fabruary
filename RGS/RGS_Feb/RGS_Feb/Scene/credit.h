//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.27
// 内容　：Credit Scene
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Credit : public SceneBase
	{
	public:
		Credit(shared_ptr<Background> background);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>終了チェック</summary>
		void CheckEnd();

	private:
		shared_ptr<Background> m_background;				//背景
	};
}