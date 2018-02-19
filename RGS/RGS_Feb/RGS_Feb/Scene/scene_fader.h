//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.19
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Utility\timer.h>

namespace Scene
{
	enum FadeState
	{
		kIn,
		kNone,
		kOut,
	};

	class SceneFader : public SceneBase
	{
	public:
		SceneFader(std::shared_ptr<SceneBase> scene, float fade_in_sec, float fade_out_sec);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		FadeState state;
		std::shared_ptr<SceneBase> m_scene;
		Utility::Timer m_fade_in;
		Utility::Timer m_fade_out;
	};
}
