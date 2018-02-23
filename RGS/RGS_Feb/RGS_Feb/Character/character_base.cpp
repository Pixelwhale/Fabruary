//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Character\character_base.h>
#include <GameObject\\Job\programmer.h>
#include <GameObject\\Job\business.h>
#include <GameObject\\Job\planner.h>
#include <GameObject\\Job\com_graphic.h>
#include <Color\color.h>
#include <Def\window_def.h>

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
	m_skill_num = 0;
	m_skill_cnt = 0;
	m_defence_value = 0;
	m_defence_max = 100;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_isStop = false;
	m_isInvincible = false;
	m_isHit = false;
	m_isIntro_end = false;
	m_intro_cnt = 0;
	m_velocity_intro = Math::Vector3(4,0,0);
	m_velocity_jump = Math::Vector3(0, 0, 0);
	m_motion->Initialize();
	m_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_motion->Play("chara_base_anime/idle");
	m_state = CharacterState::kIdle;
	//�L�����N�^�[�摜����
	if (typeid(*m_job) == typeid(Job::Programmer))
	{
		m_motion->ChangeSpriteSheet("chara_programmer");
	}
	else if (typeid(*m_job) == typeid(Job::Business))
	{
		m_motion->ChangeSpriteSheet("chara_bussiness");
	}
	else if (typeid(*m_job) == typeid(Job::ComputerGraphic))
	{
		m_motion->ChangeSpriteSheet("chara_designer");
	}
	else 
	{
		m_motion->ChangeSpriteSheet("chara_planner");
	}
	
	//�F�ݒ�
	Color m_color = Color(1.0f,1.0f,1.0f,1.0f);
	if (m_side == Side::kNoTeam)		//�I�����W
	{
		m_color = Color(220,121,0);
		m_motion->SetColor(m_color);
		m_color = Color(255, 230, 215);
		m_controller->SetTagColor(m_color);
	}
	else if (m_side == Side::kTeam1)	//��
	{
		m_color = Color(36,220,36);
		m_motion->SetColor(m_color);
		m_color = Color(219, 255, 219);
		m_controller->SetTagColor(m_color);
	}
	else if (m_side == Side::kTeam2)	//��
	{
		m_color = Color(49,220,220);
		m_motion->SetColor(m_color);
		m_color = Color(180, 255, 255);
		m_controller->SetTagColor(m_color);
	}
	else if (m_side == Side::kTeam3)	//��
	{
		m_color = Color(220,220,49);
		m_motion->SetColor(m_color);
		m_color = Color(255, 255, 180);
		m_controller->SetTagColor(m_color);
	}
	else if (m_side == Side::kTeam4)	//��
	{
		m_color = Color(220,49,16);
		m_motion->SetColor(m_color);
		m_color = Color(255,210 ,210);
		m_controller->SetTagColor(m_color);
	}

}

//�X�V
void CharacterBase::Update()
{
	if (!m_isIntro_end)
	{
		IntroUpdate();
	}
	else
	{
		if (m_hp > 0)
		{
			Attack();		//�U��
			Skill();		//�X�L�[��
			MoveUpdate();	//�ړ��X�V
			JumpUpdate();	//Jump�X�V
			MpUpdate();	//�Q�[�W�X�V
			StateUpdate();	//��Ԃ̍X�V
			KnockCntUpdate();//�|��l�J�E���g�X�V
			m_job->Update();//Job�̍X�V
			PositionUpdate();//�ʒu�̍X�V
			m_controller->UpdateMotion(m_position + Math::Vector3(10, Size::kCharaY - 80, 0));
		}
	}
	MotionUpdate(); //���[�V�����̍X�V
	//���S�X�V
	if (m_state == CharacterState::kDead)
	{
		if (m_position.y > 128)
		{
			m_gravity.Update(m_velocity_jump);
			m_position += m_velocity_jump;
		}
		if (m_motion->IsCurrentMotionEnd())
		{
			m_isDead = true;
		}
	}
}


//���[�V����
void CharacterBase::Draw()
{
	if (m_hp > 0)
	{
		m_controller->Draw();
	}
	m_motion->Draw();
	//Device::GameDevice::GetInstance()->GetRenderer()->DrawString(std::to_string(m_position.x), Math::Vector2(m_position.x + 500, 0));
}


//�����蔻��
void CharacterBase::Collide(const AttackSystem::Attack& atk)
{
	bool from_right;
	float  knockback_adjust = 14;
	if (atk.GetDamage() == 0) return;
	//�U�����󂯂�����
	if (atk.GetSourceDir() != AttackSystem::kCenter)
	{
		from_right = (atk.GetSourceDir() == AttackSystem::kRight);
	}
	else
	{
		from_right = (atk.GetPosition().x > m_position.x);
	}

	if (from_right)
	{
		m_velocity =Math::Vector3(-(float)atk.GetKnockBack() / knockback_adjust,0,0);
	}
	if (!from_right)
	{
		m_velocity = Math::Vector3((float)atk.GetKnockBack() / knockback_adjust, 0, 0);
	}
	m_knock_cnt = 0;
	m_isStop = true;
	m_isHit = true;

	//�h��̎�,�h��l���ő�l��菬�����ƃ_���[�W���󂯂Ȃ�
	if (m_state == CharacterState::kDefence &&
		m_isRight == from_right &&
		m_defence_value < m_defence_max)
	{
		m_defence_value += 20;		//�����Ŏ󂯂�
		m_isStop = true;
	}
	else
	{
		//���S
		if (m_hp - atk.GetDamage() <= 0)
		{
			m_state = CharacterState::kDead;
			m_motion->Play("chara_base_anime/dead", 1);
			m_hp -= atk.GetDamage();
		}
		//�|��l�𒴂�����A�|���
		else if (m_knock_value > m_job->KnockValue())
		{
			m_state = CharacterState::kKnockDown;
			m_motion->Play("chara_base_anime/knock_down",1);
			m_hp -= atk.GetDamage();
			m_knock_value = 0;
			m_defence_value = 0;
			
		}
		//�U�����󂯂����[�V����
		else
		{
			m_state = CharacterState::kKnockBack;
			m_motion->Play("chara_base_anime/damage",1);
			m_hp -= atk.GetDamage();
			m_knock_value += atk.GetKnockDown();
			m_defence_value = 0;
		}
		//���񂾂�A�����̍X�V���Ȃ�
		//�U�����󂯂����[�V���������̍X�V
		if (m_hp < 0)
		{
			return;
		}
		else
		{
			if (from_right)
			{
				m_isRight = true;
			}
			else
			{
				m_isRight = false;
			}
		}
	}
}

#pragma region �X�V�֘A
//�o��X�V
void CharacterBase::IntroUpdate()
{
	if (m_position.x > 0)
	{
		m_velocity_intro.x *= -1;
		m_isRight = false;
	}
	m_intro_cnt++;
	m_position += m_velocity_intro;
	m_motion->Play("chara_base_anime/walk");
	if (m_intro_cnt > 120)
	{
		m_isIntro_end = true;
		m_motion->Play("chara_base_anime/idle");
	}
}

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
		if (m_state == CharacterState::kKnockDown && m_isStop)
		{
			m_state = CharacterState::kUkemi;
			m_motion->Play("chara_base_anime/ukemi", 1);
			m_isStop = true;
		}
		if (m_state != CharacterState::kUkemi && !m_isStop)
		{
			m_state = CharacterState::kDefence;
			m_motion->Play("chara_base_anime/defence",1);
			m_isStop = true;
		}
	}
}

//�X�L�[��
void CharacterBase::Skill()
{
	m_skill_cnt--;
	if (m_skill_cnt <= 0)
	{
		m_skill_num = 0;
	}

	//���Z
	if (m_controller->IsPunchTrigger() && 
		(m_skill_num == 0 || m_skill_num == 5))
	{
		m_skill_num = 1;
		m_skill_cnt = 60;
	}
		
	if (m_controller->IsPunchTrigger() && 
		m_skill_num == 1 && 
		m_skill_cnt > 0)
	{
		m_skill_num	 = 2;
	}
	if (m_controller->IsDefence() && 
		m_skill_num == 2 &&
		m_skill_cnt > 0)
	{
		m_skill_num = 3;
	}
	if (m_controller->IsPunchTrigger()&&
		m_skill_num == 3 &&
		m_skill_cnt > 0 &&
		m_mp >= 300)
	{
		//�p���`�̏��Z
		/*m_motion->Play(m_job->Skill1(m_attack_mediator, m_position, m_isRight), 1);
		m_state = CharacterState::kPunch_1;*/
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 300;
	}
	if (m_controller->IsKickTrigger() &&
		m_skill_num == 3 &&
		m_skill_cnt > 0 &&
		m_mp >= 300)
	{
		//�L�b�N�̏��Z
		//m_motion->Play(m_job->Skill3(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_1;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 300;
	}
	

	//��Z
	if (m_controller->IsDefence() && 
		(m_skill_num == 0 || m_skill_num ==1))
	{
		m_skill_num = 5;
		m_skill_cnt = 60;
	}
	
	if (m_controller->IsRun() &&
		m_skill_num == 5 &&
		m_skill_cnt > 0)
	{
		m_skill_num = 6;
	}
	if (m_controller->IsPunchTrigger() && 
		m_skill_num == 6 &&
		m_skill_cnt > 0 &&
		m_mp >= 1500)
	{
		//�p���`�̑�Z
		//m_motion->Play(m_job->Skill2(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kPunch_2;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 1500;
	}
	if (m_controller->IsKickTrigger() && 
		m_skill_num == 6 &&
		m_skill_cnt > 0 &&
		m_mp >= 1500)
	{
		//�L�b�N�̑�Z
		//m_motion->Play(m_job->Skill4(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_2;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 1500;
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

	//�����̍X�V(Jump�̎��͂ł��Ȃ�)
	if (!m_isJump && !m_isHit)
	{
		if (m_velocity.x > 0)
		{
			m_isRight = true;
		}
		if (m_velocity.x < 0)
		{
			m_isRight = false;
		}
	}
	m_motion->Flip(m_isRight, false);
	m_motion->SetPosition(m_position);
}

//�ړ��X�V
void CharacterBase::MoveUpdate()
{
	//�U���A�U�����󂯂���Ԃł͂Ȃ��Ɠ��͂ɂ��ړ��\
	if (!m_isStop && !m_isJump)
	{
		m_velocity = m_controller->Velocity();
		if (m_velocity.lengthSqrt() != 0)
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
	}
	if (m_velocity.lengthSqrt() == 0 && !m_isStop)
	{
		m_motion->Play("chara_base_anime/idle");
	}
}

//�ʒu�̍X�V
void CharacterBase::PositionUpdate()
{
	Math::Vector3 min = Math::Vector3(-WindowDef::kScreenWidth / 2 + Size::kCharaX / 12, -Size::kCharaY,
										-WindowDef::kScreenHeight / 2 - Size::kCharaZ);
	Math::Vector3 max = Math::Vector3(WindowDef::kScreenWidth / 2 - Size::kCharaX / 12,  Size::kCharaY * 4,
								      WindowDef::kScreenHeight / 2 - Size::kCharaZ * 6);

	if (m_position.z > -140)
	{
		if (m_position.x < -430)
		{
			m_position.x = -430;
		}
		if (m_position.x > 440)
		{
			m_position.x = 440;
		}
	}
	if ((m_position.x < -430 || m_position.x > 440) && m_position.z > -145)
	{
		m_velocity.z = 0;
	}

	m_position += Math::Vector3(m_velocity.x * m_speed, m_velocity_jump.y, m_velocity.z * m_speed);
	m_position = m_position.Clamp(m_position,min,max);
}

//Jump�X�V
void CharacterBase::JumpUpdate()
{
	if (m_controller->IsJumpTrigger() && !m_isJump)
	{			
		m_state = CharacterState::kJump;
		m_isJump = true;
		m_velocity_jump = Math::Vector3(0, 23, 0);
		m_isStop = false;
	}
	else if (m_position.y < 128)
	{
		m_isJump = false;	
		m_velocity_jump = Math::Vector3(0, 0, 0);
		m_position.y = 128;
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
void CharacterBase::MpUpdate()
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
	if (m_state == CharacterState::kKnockDown || 
		m_state == CharacterState::kGetUp	  ||
		m_state == CharacterState::kUkemi)
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
		if (!m_isJump && !m_isHit)
		{
			m_velocity = Math::Vector3(0, 0, 0);
		}
		//GetUp
		if (m_state == CharacterState::kKnockDown && m_motion->IsCurrentMotionEnd())
		{
			if (m_hp < 0) return;
			m_state = CharacterState::kGetUp;
			m_motion->Play("chara_base_anime/get_up",1);
		}
		else if (m_state == CharacterState::kDefence && m_controller->IsDefence())
		{
			m_velocity = Math::Vector3(0, 0, 0);
		}
		else if (m_motion->IsCurrentMotionEnd())
		{
			m_velocity = Math::Vector3(0, 0, 0);
			m_isStop = false;
			if (m_state == CharacterState::kDead && m_hp < 0)
			{
				return;
			}
			m_state = CharacterState::kIdle;
			m_motion->Play("chara_base_anime/idle");
			m_isHit = false;
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

