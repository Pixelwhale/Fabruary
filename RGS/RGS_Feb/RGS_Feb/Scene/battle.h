//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：戦いのシーン。オプション。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Battle : public SceneBase
	{
	public:
		Battle();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}