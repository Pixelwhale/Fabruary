//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>;
#include <Math\vector3.h>;
#include<Character\side.h>;
#include<GameObject\Job\job_base.h>;
#include<Math\collision_box.h>

namespace Character
{
	class CharacterBase
	{
	public:
		CharacterBase();		//�R���X�g���N�^
		CharacterBase(Math::Vector3 position,Side side);
		~CharacterBase();		//�f�X�g���N�^
		void Initialize();		//������
		void Update();			//�X�V
		void Hit();				//�����蔻��
		bool Collision(CharacterBase other);//�����������H
		void Attack();			//�U��
		void MoveUpdate();		//�ړ��X�V
		void GageUpdate();		//�Q�[�W�X�V
		Side GetSide();		//�`�[���̎擾
		void SetSide(Side side);//�`�[���̐ݒ�
		int GetHp();			//Hp�̎擾
		int GetMp();			//Mp�̎擾
		Math::Vector3 GetPosition();//�ʒu�̎擾
		void SetPosition(Math::Vector3 position);//�ʒu�̐ݒ�
		bool IsRight();			//������Ԃ�
		void DirectionUpdate();	//�����̍X�V
		void Motion();			//���[�V����

	private:
		int m_hp;				
		int m_mp;
		int m_atk_state;		//�U�����
		int m_atk_cnt;			//�Z��łJ�E���g
		bool m_isDead;
		bool m_isJump;
		bool m_isRight;
		Side m_side;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Core::InputState> m_input;
		std::shared_ptr<Device::Renderer> m_renderer;
		
	protected:
		Job::JobBase m_job;
	};


}