//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Tutorial : public SceneBase
	{
	public:
		Tutorial(shared_ptr<Background> background);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		void CheckEnd();

	private:
		std::shared_ptr<Background> m_background;	//”wŒi
	};
}