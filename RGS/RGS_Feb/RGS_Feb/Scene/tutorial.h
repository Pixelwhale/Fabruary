//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Tutorial : public SceneBase
	{
	public:
		Tutorial();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}