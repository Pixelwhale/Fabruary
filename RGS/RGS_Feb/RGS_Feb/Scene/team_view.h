//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：チームの整頓。キャラのデータ、アイテム、スキル、装備。
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class TeamView : public SceneBase
	{
	public:
		TeamView();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}
