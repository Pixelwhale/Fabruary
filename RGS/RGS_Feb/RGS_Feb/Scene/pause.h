//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FPause�V�[��
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Pause : public SceneBase
	{
	public:
		Pause(std::shared_ptr<SceneBase> game_play);
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
		std::shared_ptr<SceneBase> m_game_play;		//GamePlay�V�[��
		const int kBlurMax = 1000;					//�ڂ����ő�l

		int m_blur_ratio;							//�ڂ����l
		bool m_blur_switch;							//�ڂ�����Switch
	};
}