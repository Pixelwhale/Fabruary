//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>;
#include <Math\vector3.h>;


namespace Character
{
	class CharacterBase
	{
	public:
		CharacterBase();		//�R���X�g���N�^
		~CharacterBase();		//�f�X�g���N�^
		void Initialize();		//������
		void Update();			//�X�V
		void Attack();			//�U��
		void MoveUpdate();		//�ړ��X�V
		void GageUpdate();		//�Q�[�W�X�V
		void Draw();			//�`��
	private:
		int m_hp;				
		int m_gage;
		int m_atk_state;		//�U�����
		int m_atk_cnt;			//�Z��łJ�E���g
		bool m_isDead;
		bool m_isJump;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Core::InputState> m_input;
		std::shared_ptr<Device::Renderer> m_renderer;
	};


}