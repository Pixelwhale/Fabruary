//-------------------------------------------------------
// �쐬�ҁF�@�[��
// �쐬���F2018.02.22
// ���e�@�F�V�[���̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include "scene_base.h"
#include "game_manager.h"

namespace Scene
{
	enum State
	{
		kControlTypeSelect,
		kCharaSelect,
		kEnd,
	};

	class CharaSelect : public SceneBase
	{
	public:
		CharaSelect();
		void Update();
		void Draw();
		void Shutdown();
	private:
	};
}
