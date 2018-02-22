//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�F�Q�[���I���V�[��
//-------------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class GameResult : public SceneBase
	{
	public:
		GameResult(std::shared_ptr<SceneBase> game_scene);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		void CheckEnd();

	private:
		std::shared_ptr<SceneBase> m_game_scene;				//GamePlay�V�[��
	};
}