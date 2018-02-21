//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Character\character_base.h>

using namespace Character;


CharacterBase::CharacterBase(Math::Vector3 position,Side side,int id, 
							std::shared_ptr<VirtualController> controller,
							std::shared_ptr<Job::JobBase> job,
							std::shared_ptr<AttackSystem::AttackMediator> attackMediator)
{
	m_controller = controller;
	m_job = job;
	m_attack_mediator = attackMediator;
	m_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_size = Math::Vector3(Size::kCharaX, Size::kCharaY, Size::kCharaZ);
	m_side = side;
	m_id = id;
	Initialize(position);
}

CharacterBase::~CharacterBase()
{
	m_controller = NULL;
	m_motion = NULL;
	m_job = NULL;
	m_attack_mediator = NULL;
}

//������
void CharacterBase::Initialize(Math::Vector3 position)
{
	m_position = position;
	m_hp = m_job->GetHp();
	m_mp = 3000;
	m_speed = 4;
	m_knock_value = 0;
	m_knock_cnt = 0;
	m_defence_value = 0;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_isStop = false;
	m_isInvincible = false;
	m_velocity_jump = Math::Vector3(0, 0, 0);
	m_rotation = Math::Vector3(0, 0, 0);
	m_motion->Initialize();
	m_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_motion->Play("chara_base_anime/idle");
	m_motion->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	m_state = CharacterState::kIdle;
}

//�X�V
void CharacterBase::Update()
{
	Attack();		//�U��
	MoveUpdate();	//�ړ��X�V
	JumpUpdate();	//Jump�X�V
	GageUpdate();	//�Q�[�W�X�V
	MotionUpdate(); //���[�V�����̍X�V
	StateUpdate();	//��Ԃ̍X�V
	KnockCntUpdate();//�|��l�J�E���g�X�V
	m_job->Update();//Job�̍X�V
	//���S�X�V
	if (m_hp <= 0)
	{
		m_isDead = true;
	}
	m_position += Math::Vector3(m_velocity.x * m_speed, m_velocity_jump.y, m_velocity.z * m_speed);
}


//���[�V����
void CharacterBase::Draw()
{
	m_motion->Draw();
	
}


//�����蔻��
void CharacterBase::Collide(int damage,int knockBack, int knockDown, bool fromRight)
{
	if (fromRight)
	{
		m_velocity.x = -knockBack;
	}
	else if (!fromRight)
	{
		m_velocity.x = knockBack;
	}
	m_knock_cnt = 0;
	m_isStop = true;

	//�h��̎�
	if (m_state == CharacterState::kDefence && m_isRight == fromRight && m_defence_value <100)
	{
		m_knock_value += knockBack;
		m_defence_value += 20;		//�����Ŏ󂯂�
	}
	else
	{
		//�|��l�𒴂�����A�|���
		if (m_knock_value > m_job->KnockValue())
		{
			m_state = CharacterState::kKnockDown;
			m_motion->Play("chara_base_anime/knock_down",1);
			m_hp -= damage;
			m_knock_value = 0;
			m_defence_value = 0;
		}
		else
		{
			m_state = CharacterState::kKnockBack;
			m_motion->Play("chara_base_anime/damage",1);
			m_hp -= damage;
			m_knock_value += knockBack;
			m_defence_value = 0;
		}
	}
}

#pragma region �X�V�֘A

//�U��
void CharacterBase::Attack()
{
	//�p���`
	if (m_controller->IsPunchTrigger() && !m_isStop)
	{
		m_motion->Play(m_job->Punch(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kPunch;
		m_isStop = true;
	}
	//�L�b�N
	if (m_controller->IsKickTrigger() && !m_isStop)
	{
		m_motion->Play(m_job->Kick(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kKick;
		m_isStop = true;
	}
	//�h��
	if (m_controller->IsDefence())
	{
		m_state = CharacterState::kDefence;
		m_motion->Play("chara_base_anime/defence");
		m_isStop = true;
	}
	
}

//�|��l�J�E���g�X�V
void CharacterBase::KnockCntUpdate()
{
	m_knock_cnt++;
	//180(3�b)�𒴂�����A�|��l��������
	if (m_knock_cnt >= 180)
	{
		m_knock_value--;
		m_knock_cnt = 180;
	}
}

//���[�V�����̍X�V
void CharacterBase::MotionUpdate()
{
	m_motion->Update();

	//�����̍X�V
	if (m_velocity.x > 0)
	{
		m_isRight = true;
	}
	if (m_velocity.x < 0)
	{
		m_isRight = false;
	}
	m_motion->Flip(m_isRight, false);
	m_motion->SetPosition(m_position);
}

//�ړ��X�V
void CharacterBase::MoveUpdate()
{
	//�U���A�U�����󂯂���Ԃł͂Ȃ��Ɠ��͂ɂ��ړ��\
	if (!m_isStop)
	{
		m_velocity = m_controller->Velocity();
	}
	
	m_speed = 4;
	if (m_velocity.lengthSqrt() != 0 && !m_isStop && !m_isJump)
	{
		//run
		if (m_controller->IsRun())
		{
			m_speed = 8;
			m_state = CharacterState::kRun;
			m_motion->Play("chara_base_anime/run");
		}
		else
		{
			//����
			m_speed = 4;
			m_state = CharacterState::kWalk;
			m_motion->Play("chara_base_anime/walk");
		}
	}
	else if (m_velocity.lengthSqrt() == 0 && !m_isStop)
	{
		m_motion->Play("chara_base_anime/idle");
	}
	else if (m_isJump && m_controller->IsRun())
	{
		m_speed = 8;
	}
}

//Jump�X�V
void CharacterBase::JumpUpdate()
{
	if (m_controller->IsJumpTrigger() && !m_isJump)
	{
		m_state = CharacterState::kJump;
		m_isJump = true;
		m_velocity_jump = Math::Vector3(0, 8, 0);
		m_isStop = false;
	}
	else if (m_position.y < 0)
	{
		m_isJump = false;
		m_velocity_jump = Math::Vector3(0, 0, 0);
		m_state = CharacterState::kIdle;
	}
	if (m_isJump)
	{
		if (m_state == CharacterState::kJump)
		{
			m_motion->Play("chara_base_anime/jump");
		}
		m_gravity.Update(m_velocity_jump);
	}
}

//�Q�[�W�X�V
void CharacterBase::GageUpdate()
{
	++m_mp;
	if (m_mp >= 6000)
	{
		m_mp = 6000;
	}
}

//��Ԃ̍X�V
void CharacterBase::StateUpdate()
{
	//�h�䂩�|��ꂽ���͖��G
	if (m_state == CharacterState::kKnockDown)
	{
		m_isInvincible = true;
	}
	else
	{
		m_isInvincible = false;
	}

	//���[�V�������I�������A�ҋ@��Ԃ�
	if (m_isStop)
	{
		//Jump�̎��͓�����
		if (!m_isJump)
		{
			m_velocity = Math::Vector3(0, 0, 0);
		}
		if (m_motion->IsCurrentMotionEnd())
		{
			m_state = CharacterState::kIdle;
			m_motion->Play("chara_base_anime/idle");
			m_isStop = false;
			//Jump���Ă���ƁAJump���[�V�����ɖ߂�
			if (m_isJump)
			{
				m_state = CharacterState::kJump;
			}
		}
	}
}

#pragma endregion


//Get�ASet�֘A

//������Ԃ�
bool CharacterBase::IsRight()
{
	return m_isRight;
}

//���񂾂��H
bool CharacterBase::IsDead()
{
	return m_isDead;
}

//�`�[���̎擾
Side CharacterBase::GetSide()
{
	return m_side;
}


//Hp�̎擾
int CharacterBase::GetHp()
{
	return m_hp;
}

//Mp�̎擾
int CharacterBase::GetMp()
{
	return m_mp;
}

//MaxMp�̎擾
int CharacterBase::GetMaxHp()
{
	return m_job->GetHp();
}

//�ʒu�̎擾
Math::Vector3 CharacterBase::GetPosition()
{
	return m_position;
}

//�ʒu�̐ݒ�
void CharacterBase::SetPosition(Math::Vector3 position)
{
	m_position = position;
}

//ID�̎擾
int CharacterBase::GetID()
{
	return m_id;
}

//���G�t���O
bool CharacterBase::IsInvincible()
{
	return m_isInvincible;
}

Math::CollisionBox CharacterBase::GetBox()
{
	return Math::CollisionBox(m_position - Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), m_position + Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
}

