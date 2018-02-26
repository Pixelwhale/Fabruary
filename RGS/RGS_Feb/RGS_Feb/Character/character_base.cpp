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
#include <Def\character_color.h>

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
	m_gravity = NULL;
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
	m_gravity = std::make_shared<System::Gravity>();
	ChangeSheet();			//�L�����N�^�[�V�[�g����
	SetColor();				//�F�ݒ�
	m_controller->UpdateMotion(m_position + Math::Vector3(10, Size::kCharaY - 80, 0));
	m_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_motion->SetPosition(m_position);
	m_motion->Play("chara_base_anime/idle");
	m_state = CharacterState::kIdle;
}

//�X�V
void CharacterBase::Update()
{
	
	IntroUpdate();
	MotionUpdate(); //���[�V�����̍X�V
	if (m_hp > 0 && m_isIntro_end)
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
	//���S�X�V
	if (m_state == CharacterState::kDead)
	{
		if (m_position.y > 128)
		{
			m_gravity->Update(m_velocity_jump);
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
}


//�����蔻��
void CharacterBase::Collide(const AttackSystem::Attack& atk)
{
	bool from_right;
	float  knockback_adjust = 14;
	if (atk.GetDamage() == 0) m_isStop = true;
	//�X�L�[�����̎��́A�_���[�W���󂯂邾��
	if (m_state == CharacterState::kSkill)
	{
		// ���S
		if (m_hp - atk.GetDamage() <= 0)
		{
			m_state = CharacterState::kDead;
			m_motion->Play("chara_base_anime/dead", 1);
			m_hp -= atk.GetDamage();
		}
		m_hp -= atk.GetDamage();
		return;
	}
	//�U�����󂯂�����
	if (atk.GetSourceDir() != AttackSystem::kCenter)
	{
		from_right = (atk.GetSourceDir() == AttackSystem::kRight);
	}
	else
	{
		from_right = (atk.GetPosition().x > m_position.x);
	}
	//knockback�ɂ�邸��鏈��
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
				m_motion->Flip(true, false);
			}
			else
			{
				m_motion->Flip(false, false);
			}
		}
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
	}
}

//�L�����N�^�[�摜����
void CharacterBase::ChangeSheet()
{
	if (typeid(*m_job) == typeid(Job::Programmer))
	{
		m_character_face = 3;
		m_motion->ChangeSpriteSheet("chara_programmer");
		m_sheet_name = "chara_programmer";
	}
	else if (typeid(*m_job) == typeid(Job::Business))
	{
		m_character_face = 1;
		m_motion->ChangeSpriteSheet("chara_business");
		m_sheet_name = "chara_business";
	}
	else if (typeid(*m_job) == typeid(Job::ComputerGraphic))
	{
		m_character_face = 2;
		m_motion->ChangeSpriteSheet("chara_designer");
		m_sheet_name = "chara_designer";
	}
	else
	{
		m_character_face = 0;
		m_motion->ChangeSpriteSheet("chara_planner");
		m_sheet_name = "chara_planner";
	}
}

//�F�ݒ�
void CharacterBase::SetColor()
{
	m_motion->SetColor(CharacterColor::GetTeamColor(m_side));
	m_controller->SetTagColor(CharacterColor::GetIconColor(m_side));
}


#pragma region �X�V�֘A
//�o��X�V
void CharacterBase::IntroUpdate()
{
	//�o�ꂵ����A
	if (m_isIntro_end) return;
	//�o�ꃂ�[�V�����̌����̐ݒ�
	if (m_position.x > 0 && m_intro_cnt < 1)
	{
		m_velocity_intro.x *= -1;
		m_isRight = false;
	}
	m_intro_cnt++;
	m_position += m_velocity_intro;
	m_motion->Play("chara_base_anime/walk_intro");
	if (m_intro_cnt > 120 && m_intro_cnt < 150)
	{
		m_velocity_intro.x = 0;
		m_motion->Play("chara_base_anime/idle");
	}
	else if (m_intro_cnt >= 150)
	{
		m_intro_cnt = 0;
		m_isIntro_end = true;
	}
	m_controller->UpdateMotion(m_position + Math::Vector3(10, Size::kCharaY - 80, 0));
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
			m_velocity = Math::Vector3(0, 0, 0);
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
	if (m_state == CharacterState::kSkill && !m_motion->IsCurrentMotionEnd()) return;
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
		m_isStop = true;
		m_motion->Play(m_job->Skill1(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kPunch_1;
		m_state = CharacterState::kSkill;
		m_skill_num = 0;
		m_mp -= 300;
	}
	if (m_controller->IsKickTrigger() &&
		m_skill_num == 3 &&
		m_skill_cnt > 0 &&
		m_mp >= 300)
	{
		//�L�b�N�̏��Z
		m_isStop = true;
		//m_motion->Play(m_job->Skill3(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_1;
		//m_state = CharacterState::kSkill;
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
		m_isStop = true;
		//m_motion->Play(m_job->Skill2(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kPunch_2;
		//m_state = CharacterState::kSkill;
		m_skill_num = 0;
		m_mp -= 1500;
	}
	if (m_controller->IsKickTrigger() && 
		m_skill_num == 6 &&
		m_skill_cnt > 0 &&
		m_mp >= 1500)
	{
		//�L�b�N�̑�Z
		m_isStop = true;
		//m_motion->Play(m_job->Skill4(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_2;
		//m_state = CharacterState::kSkill;
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

	if (m_position.x < -430 || m_position.x > 440)
	{
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
		else if (m_position.z + m_velocity.z > -150)
		{
			m_position.z = -150;
		}
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
		m_gravity->Update(m_velocity_jump);
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
		if ((!m_isJump && !m_isHit) ||
			 m_state == CharacterState::kSkill)
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

//�L�����N�^�[�摜���Ԏ擾
int CharacterBase::GetFaceNum()
{
	return m_character_face;
}

//sheet���擾
string CharacterBase::GetSheetName()
{
	return m_sheet_name;
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

std::shared_ptr<Job::JobBase> CharacterBase::GetCharacterJob()
{
	return m_job;
}


