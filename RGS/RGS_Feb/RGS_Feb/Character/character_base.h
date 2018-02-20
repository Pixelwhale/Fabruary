//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Device\MotionSystem\motion.h>
#include <Math\vector3.h>
#include <Math\collision_box.h>
#include <Character\side.h>
#include <Character\Controller\character_controller.h>
#include <Character\character_state.h>
#include <GameObject\Job\job_base.h>
#include <GameObject\AttackSystem\attack_mediator.h>

namespace Character
{
	class CharacterBase
	{
	public:
		//�R���X�g���N�^�i�ʒu�A�`�[���AID�AHp,controller, job, attackMediator�j
		CharacterBase(Math::Vector3 position,Side side,int id,
			std::shared_ptr<VirtualController> controller,
			std::shared_ptr<Job::JobBase> job,
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator);
		~CharacterBase();			//�f�X�g���N�^
		void Initialize(Math::Vector3 position);//������
		void Update();				//�X�V
		void Collide(int damage, int knockback, int knockdown, bool isright);//�����蔻��

	public:							//�擾�֘A
		Side	GetSide();			//�`�[���̎擾
		int		GetHp();			//Hp�̎擾
		int		GetMp();			//Mp�̎擾
		int		GetID();			//ID�̎擾
		bool	IsRight();			//������Ԃ�
		bool	IsDead();			//���񂾂��H
		bool	IsInvincible();		//���G�t���O
		void	SetPosition(Math::Vector3 position);//�ʒu�̐ݒ�
		Math::Vector3 GetPosition();//�ʒu�̎擾
		Math::CollisionBox GetBox();
		

	private:						//�X�V�֘A
		void Attack();				//�U��
		void MoveUpdate();			//�ړ��X�V
		void GageUpdate();			//�Q�[�W�X�V
		void MotionUpdate();		//���[�V�����̍X�V
		void Motion();				//���[�V����
		void StateUpdate();			//��Ԃ̍X�V
		void KnockCntUpdate();		//�|��l�J�E���g�X�V

	private:
		int		m_hp;				
		int		m_mp;
		int		m_knock_value;		//�|��l
		int		m_knock_cnt;		//��莞�ԍU�����󂯂Ȃ��Ɠ|��l��������
		float	m_speed;
		int		m_id;

		bool	m_isDead;
		bool	m_isJump;
		bool	m_isRight;
		bool	m_isInvincible;		//���G�t���O
		bool	m_isStop;			//�U����ԂƂ��U�����󂯂����A���͂ɂ��ړ���h��

		Side	m_side;
		CharacterState m_state;

		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;

		std::shared_ptr<Device::Renderer>		m_renderer;
		std::shared_ptr<VirtualController>		m_controller;
		std::shared_ptr<MotionSystem::Motion>	m_motion;
		std::shared_ptr<Job::JobBase>			m_job;
		std::shared_ptr<AttackSystem::AttackMediator> m_attack_mediator;
	};


}