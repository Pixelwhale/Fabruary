//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：ショップのシーン。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Shop : public SceneBase
	{
	public:
		Shop();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}