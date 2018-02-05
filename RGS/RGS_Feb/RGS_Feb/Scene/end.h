//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2017.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class End : public SceneBase
	{
	public:
		End();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}