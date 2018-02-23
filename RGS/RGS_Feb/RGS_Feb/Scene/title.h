//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.12.22
// ���e�@�F�^�C�g���̃V�[���B�X�^�[�g�A���[�h�A�I�v�V�����B
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Title : public SceneBase
	{
	public:
		Title();
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();
	private:
		shared_ptr<Background> m_background;		//�w�i
	};
}