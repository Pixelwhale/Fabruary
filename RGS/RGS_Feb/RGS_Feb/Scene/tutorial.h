//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Tutorial : public SceneBase
	{
	public:
		Tutorial();
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		std::shared_ptr<Background> m_background;	//�w�i
	};
}