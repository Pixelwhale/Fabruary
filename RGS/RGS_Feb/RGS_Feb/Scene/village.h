//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：村のシーン。冒険(Battle)、ショップ、チーム整頓、オプション。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Village : public SceneBase
	{
	public:
		Village();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}