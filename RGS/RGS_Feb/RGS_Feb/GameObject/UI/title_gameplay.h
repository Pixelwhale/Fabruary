//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FGamePlay��I����������State
//-------------------------------------------------------
#pragma once
#include <GameObject\UI\title_state.h>

namespace UI
{
	class MenuGamePlay : public TitleState
	{
	public:
		MenuGamePlay();
		MenuGamePlay(const MenuGamePlay&);
		~MenuGamePlay();

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

		///<summary>�m�F�{�^���������ꂽ��</summary>
		bool Enter();
		///<summary>�߂�{�^���������ꂽ��</summary>
		bool Cancel();
		///<summary>���{�^���������ꂽ��</summary>
		bool Down();

	private:
		bool m_next_flag;			//�L�[�������ꂽ��

		float m_push_alpha;			//�`��Alpha
		MenuState m_next_state;		//����State
	};
}