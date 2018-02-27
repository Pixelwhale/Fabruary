//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.27
// 内容　：LogoScene
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Device\MotionSystem\motion.h>
#include <Utility\timer.h>

namespace Scene
{
	class Logo : public SceneBase
	{
	public:
		Logo();
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		void CheckEnd();
		void UpdateSchool();
		void UpdateTeam();

	private:
		shared_ptr<MotionSystem::Motion> m_team_logo;		//Team Logo
		Utility::Timer m_logo_timer;						//学校のLogo Timer
	};
}