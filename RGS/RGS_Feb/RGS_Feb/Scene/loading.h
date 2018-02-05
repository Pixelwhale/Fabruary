//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.19
// 内容　：テクスチャ、音などをロードするシーン
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Scene\scene_base.h>

namespace Scene
{
	class Loading : public SceneBase
	{
	public:
		Loading();
		void LoadContents();
		void UnloadContents();
		void Update();
		void Draw();
		void Shutdown();
	private:
		std::shared_ptr<Device::ContentManager> m_content;
	};
}