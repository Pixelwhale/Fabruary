//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：TitleStateの管理者
//-------------------------------------------------------
#pragma once
#include <GameObject\UI\title_state.h>
#include <map>

namespace UI 
{
	class TitleStateManager 
	{
	public:
		TitleStateManager();
		TitleStateManager(const TitleStateManager&);
		~TitleStateManager();

		///<summary>初期化</summary>
		void Initialize();
		///<summary>解放処理</summary>
		void Clear();
		///<summary>更新処理</summary>
		void Update();
		///<summary>描画</summary>
		void Draw();

		///<summary>終了するか</summary>
		bool IsEnd();
		///<summary>次のシーン</summary>
		Scene::SceneType NextScene();

	private:
		map<MenuState, shared_ptr<TitleState>> m_states;	//MenuState
		weak_ptr<TitleState> m_current_state;				//現在のState

		MenuState m_current_menu;							//現在の状態
	};
}