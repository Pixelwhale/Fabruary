//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.05
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>

namespace Scene
{
	class GamePlay : public SceneBase
	{
	public:
		GamePlay();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}