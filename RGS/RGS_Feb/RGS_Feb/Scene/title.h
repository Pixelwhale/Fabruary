//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：タイトルのシーン。スタート、ロード、オプション。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Title : public SceneBase
	{
	public:
		Title();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}