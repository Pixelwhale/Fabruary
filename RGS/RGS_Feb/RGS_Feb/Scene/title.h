//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：TitleScene, Effect追加
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
		///<summary>終了チェック</summary>
		void CheckEnd();
		///<summary>SceneChangeEffectを初期化</summary>
		void InitSceneEffect();
		///<summary>Menuを初期化</summary>
		void InitMenu();
		///<summary>Winnerを背景に設定</summary>
		void SetWinner();

	private:
		std::shared_ptr<GameManager> m_game_manager;		//GameManager
		shared_ptr<Background> m_background;				//背景
		shared_ptr<SceneEffect> m_scene_effect;				//SceneChangeEffect

		shared_ptr<UI::TitleStateManager> m_title_menu;		//TitleMenu
	};
}