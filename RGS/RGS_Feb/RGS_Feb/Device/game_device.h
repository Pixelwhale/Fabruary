//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.10
// 内容　：Device系をまとめたクラス
//-------------------------------------------------------
#pragma once
#include <memory>
#include <Core\input_state.h>
#include <Device\renderer.h>
#include <Device\projector.h>
#include <Device\content_manager.h>
#include <Device\random.h>

namespace Device
{
	static class GameDevice
	{
	public:
		~GameDevice();
		///<summary>インスタンスを取得</summary>
		static GameDevice* GetInstance() 
		{
			return m_instance;
		}

		///<summary>初期化</summary>
		bool Initialize();
		///<summary>解放処理</summary>
		void ShutDown();

		///<summary>入力装置</summary>
		std::shared_ptr<Core::InputState>	GetInput();
		///<summary>レンダラー</summary>
		std::shared_ptr<Renderer>			GetRenderer();
		///<summary>カメラ</summary>
		std::shared_ptr<Projector>			GetProjector();
		///<summary>コンテントマネージャー</summary>
		std::shared_ptr<ContentManager>		GetContent();
		///<summary>ランダム</summary>
		Random*								GetRandom();

	private:
		static GameDevice* m_instance;
		GameDevice();
		GameDevice(const GameDevice&);

	private:
		std::shared_ptr<Core::InputState>	m_input;			//入力装置
		std::shared_ptr<Renderer>			m_renderer;			//レンダラー
		std::shared_ptr<Projector>			m_projector;		//カメラ
		std::shared_ptr<ContentManager>		m_content;			//コンテンツ
		Random								m_rand;				//ランダム
	};
}
