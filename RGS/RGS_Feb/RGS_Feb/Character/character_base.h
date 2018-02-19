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
		//�R���X�g���N�^�i�ʒu�A�`�[���AID�AHp�j
		CharacterBase(Math::Vector3 position,Side side,int id,int hp);
		~CharacterBase();			//�f�X�g���N�^
		void Initialize(Math::Vector3 position, int hp);//������
		void Update();				//�X�V
		void Collide();				//�����蔻��
		void Attack();				//�U��
		void Motion();				//���[�V����

	public:							//�擾�֘A
		Side	GetSide();			//�`�[���̎擾
		int		GetHp();			//Hp�̎擾
		int		GetMp();			//Mp�̎擾
		Math::Vector3 GetPosition();//�ʒu�̎擾
		void	SetPosition(Math::Vector3 position);//�ʒu�̐ݒ�
		bool	IsRight();			//������Ԃ�
		bool	IsDead();			//���񂾂��H
		Math::CollisionBox GetBox();
		

	private:						//�X�V�֘A
		void MoveUpdate();			//�ړ��X�V
		void GageUpdate();			//�Q�[�W�X�V
		void DirectionUpdate();		//�����̍X�V

	private:
		int		m_hp;				
		int		m_mp;
		int		m_atk_state;		//�U�����͏��
		int		m_atk_cnt;			//�A�����̓J�E���g
		float	m_speed;
		bool	m_isDead;
		bool	m_isJump;
		bool	m_isRight;
		int		m_id;
		Side	m_side;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Core::InputState> m_input;
		std::shared_ptr<Device::Renderer> m_renderer;
		
	protected:
	};


}