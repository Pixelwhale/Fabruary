//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.25
// ���e�@�FTitleMenu��State
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Core\input_state.h>
#include <Scene\scene_type.h>

namespace UI 
{
	enum MenuState
	{
		kTitle = 0,
		kGamePlay,
		kTutorial,
		kCredit,
		kQuit,
		kEnd,
	};

	class TitleState 
	{
	public:
		TitleState();
		TitleState(const TitleState&);
		~TitleState();

		///<summary>������</summary>
		virtual void Initialize(MenuState previous_state)	= 0;
		///<summary>�X�V����</summary>
		virtual void Update()								= 0;
		///<summary>�`��</summary>
		virtual void Draw()									= 0;

		///<summary>����State</summary>
		virtual MenuState NextState()						= 0;
		///<summary>���̃V�[��</summary>
		virtual Scene::SceneType NextScene()				= 0;

		///<summary>�I�����邩</summary>
		bool IsEnd();

	protected:
		///<summary>�����Key�������ꂽ��</summary>
		///<param name="key_input">Keyboard</param>
		///<param name="xinput_button">XboxController</param>
		bool TriggerKey(unsigned int key_input, unsigned char xinput_button);
		///<summary>�m�F�{�^���������ꂽ��</summary>
		bool Enter();
		///<summary>�߂�{�^���������ꂽ��</summary>
		bool Cancel();
		///<summary>���{�^���������ꂽ��</summary>
		bool Down();
		///<summary>���{�^���������ꂽ��</summary>
		bool Up();

	protected:
		std::shared_ptr<Device::Renderer> m_renderer;	//Renderer
		std::shared_ptr<Core::InputState> m_input;		//Input

		bool m_end_flag;								//�I��Flag
	};
}