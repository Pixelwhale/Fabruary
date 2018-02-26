//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.24
// ���e�@�FTitleScene, Effect�ǉ�
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <Scene\game_manager.h>
#include <GameObject\Background\background.h>
#include <GameObject\Background\change_scene_effect.h>
#include <GameObject\UI\title_state_manager.h>

namespace Scene
{
	class Title : public SceneBase
	{
	public:
		Title(shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect,
			std::shared_ptr<GameManager> game_manager);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>�I���`�F�b�N</summary>
		void CheckEnd();
		///<summary>SceneChangeEffect��������</summary>
		void InitSceneEffect();
		///<summary>Menu��������</summary>
		void InitMenu();
		///<summary>Winner��w�i�ɐݒ�</summary>
		void SetWinner();

	private:
		std::shared_ptr<GameManager> m_game_manager;		//GameManager
		shared_ptr<Background> m_background;				//�w�i
		shared_ptr<SceneEffect> m_scene_effect;				//SceneChangeEffect

		shared_ptr<UI::TitleStateManager> m_title_menu;		//TitleMenu
	};
}