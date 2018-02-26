//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.27
// ���e�@�FCredit Scene
//-------------------------------------------------------
#pragma once
#include <Scene\scene_base.h>
#include <GameObject\Background\background.h>

namespace Scene
{
	class Credit : public SceneBase
	{
	public:
		Credit(shared_ptr<Background> background);
		void Initialize(SceneType previous);
		void Update();
		void Draw();
		void Shutdown();

	private:
		///<summary>�I���`�F�b�N</summary>
		void CheckEnd();

	private:
		shared_ptr<Background> m_background;				//�w�i
	};
}