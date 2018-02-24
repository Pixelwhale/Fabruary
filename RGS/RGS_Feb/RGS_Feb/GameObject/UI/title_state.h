//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.25
// 内容　：TitleMenuのState
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Core\input_state.h>
#include <Scene\scene_type.h>

namespace UI 
{
	enum MenuState
	{
		kTitle = 0,
		kGamePlay,
		kTutorial,
		kQuit,
		kEnd,
	};

	class TitleState 
	{
	public:
		TitleState();
		TitleState(const TitleState&);
		~TitleState();

		///<summary>初期化</summary>
		virtual void Initialize(MenuState previous_state)	= 0;
		///<summary>更新処理</summary>
		virtual void Update()								= 0;
		///<summary>描画</summary>
		virtual void Draw()									= 0;

		///<summary>次のState</summary>
		virtual MenuState NextState()						= 0;
		///<summary>次のシーン</summary>
		virtual Scene::SceneType NextScene()				= 0;

		///<summary>終了するか</summary>
		bool IsEnd();

	protected:
		std::shared_ptr<Device::Renderer> m_renderer;	//Renderer
		std::shared_ptr<Core::InputState> m_input;		//Input

		bool m_end_flag;								//終了Flag
	};
}