//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitle��State
//-------------------------------------------------------
#pragma once
#include <GameObject\UI\title_state.h>

namespace UI 
{
	class TitleEnter : public TitleState 
	{
	public:
		TitleEnter();
		TitleEnter(const TitleEnter&);
		~TitleEnter();

		///<summary>������</summary>
		virtual void Initialize(MenuState previous_state);
		///<summary>�X�V����</summary>
		virtual void Update();
		///<summary>�`��</summary>
		virtual void Draw();

		///<summary>����State</summary>
		virtual MenuState NextState();
		///<summary>���̃V�[��</summary>
		virtual Scene::SceneType NextScene();

	private:
		///<summary>�����x�X�V</summary>
		void UpdateAlpha();
		///<summary>�I���`�F�b�N</summary>
		void CheckEnd();

	private:
		bool m_next_flag;			//�L�[�������ꂽ��

		bool m_push_alpha_switch;	//�`��Alpha��Switch
		float m_push_alpha;			//�`��Alpha
	};
}