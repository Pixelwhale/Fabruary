//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FPause�V�[��
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Scene\game_manager.h>

namespace Scene
{
	class Pause : public SceneBase
	{
	public:
		Pause(std::shared_ptr<SceneBase> game_play, shared_ptr<GameManager> game_manager);
		virtual void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>�G�t�F�N�g�X�V</summary>
		void UpdateEffect();
		///<summary>�I�����邩���`�F�b�N</summary>
		bool CheckEnd();

	private:
		shared_ptr<GameManager> m_game_manager;		//GameManager
		std::shared_ptr<SceneBase> m_game_play;		//GamePlay�V�[��
		const int kBlurMax = 1000;					//�ڂ����ő�l

		int m_blur_ratio;							//�ڂ����l
		bool m_blur_switch;							//�ڂ�����Switch
	};
}