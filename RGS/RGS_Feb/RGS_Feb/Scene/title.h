//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.24
// ���e�@�FTitleScene, Effect�ǉ�
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>
#include <GameObject\Background\change_scene_effect.h>
#include <GameObject\UI\title_state_manager.h>

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
		///<summary>�I���`�F�b�N</summary>
		void CheckEnd();

	private:
		shared_ptr<Background> m_background;		//�w�i
		shared_ptr<SceneEffect> m_scene_effect;		//SceneChangeEffect

		shared_ptr<UI::TitleStateManager> m_title_menu;		//TitleMenu
	};
}