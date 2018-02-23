//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：タイトルのシーン。スタート、ロード、オプション。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Title : public SceneBase
	{
	public:
		Title();
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		shared_ptr<Background> m_background;		//背景
	};
}