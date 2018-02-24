//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitleState�̊Ǘ���
//-------------------------------------------------------
#pragma once
#include <GameObject\UI\title_state.h>
#include <map>

namespace UI 
{
	class TitleStateManager 
	{
	public:
		TitleStateManager();
		TitleStateManager(const TitleStateManager&);
		~TitleStateManager();

		///<summary>������</summary>
		void Initialize();
		///<summary>�������</summary>
		void Clear();
		///<summary>�X�V����</summary>
		void Update();
		///<summary>�`��</summary>
		void Draw();

		///<summary>�I�����邩</summary>
		bool IsEnd();
		///<summary>���̃V�[��</summary>
		Scene::SceneType NextScene();

	private:
		map<MenuState, shared_ptr<TitleState>> m_states;	//MenuState
		weak_ptr<TitleState> m_current_state;				//���݂�State

		MenuState m_current_menu;							//���݂̏��
	};
}