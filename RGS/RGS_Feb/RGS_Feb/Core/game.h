//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：Gameの基本処理
//-------------------------------------------------------
#pragma once
#include <Core\application.h>
#include <Device\game_device.h>
#include <Scene\scene_manager.h>

namespace Core
{
	class Game : public Application
	{
	public:
		Game() {}						//コンストラクタ
		~Game() {}						//デストラクター

	protected:
		virtual void Initialize();		//初期化
		virtual void Load();			//リソース読み込む
		virtual void Unload();			//リソース解放
		virtual void Update();			//ゲーム更新
		virtual void Draw();			//描画
		virtual bool IsEnd();			//終了確認するメソッド

	private:
		bool m_end_flag;					//ゲーム終了のフラグ

		std::shared_ptr<Device::Renderer> m_renderer;

		std::shared_ptr<Scene::SceneManager> m_scene_manager;

		//ss::Player* m_ss_player;
	};
}