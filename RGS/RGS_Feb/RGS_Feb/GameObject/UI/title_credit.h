//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.27
// 内容　：Creditを選択した時のState
//-------------------------------------------------------
#pragma once
#include <GameObject\UI\title_state.h>

namespace UI
{
	class MenuCredit : public TitleState
	{
	public:
		MenuCredit();
		MenuCredit(const MenuCredit&);
		~MenuCredit();

		///<summary>初期化</summary>
		virtual void Initialize(MenuState previous_state);
		///<summary>更新処理</summary>
		virtual void Update();
		///<summary>描画</summary>
		virtual void Draw();

		///<summary>次のState</summary>
		virtual MenuState NextState();
		///<summary>次のシーン</summary>
		virtual Scene::SceneType NextScene();

	private:
		///<summary>透明度更新</summary>
		void UpdateAlpha();
		///<summary>終了チェック</summary>
		void CheckEnd();

	private:
		bool m_next_flag;			//キーが押されたか

		float m_push_alpha;			//描画Alpha
		MenuState m_next_state;		//次のState
	};
}