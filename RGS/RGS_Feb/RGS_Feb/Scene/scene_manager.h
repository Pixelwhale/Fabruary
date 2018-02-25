//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.18
// 内容　：シーンを管理するマネージャー
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class SceneManager
	{
	public:
		SceneManager();

		///<summary>シーンの実体を生成する</summary>
		void Initialize();

		void Update();
		void Draw();

		bool IsEnd();

	private:
		std::map<SceneType, std::shared_ptr<SceneBase>> m_map;
		SceneType m_current_type;
		std::weak_ptr<SceneBase> m_current_scene;
		
		void Add(SceneType type, const std::shared_ptr<SceneBase> scene);
		void Change(SceneType type);
	};
}