//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2017.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class Pause : public SceneBase
	{
	public:
		Pause();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}