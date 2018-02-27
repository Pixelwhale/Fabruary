//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.27
// ���e�@�FLogoScene
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
		Utility::Timer m_logo_timer;						//�w�Z��Logo Timer
	};
}