//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Character\character_base.h>

using namespace Character;


CharacterBase::CharacterBase(Math::Vector3 position,Side side,int id,int hp, std::shared_ptr<VirtualController> controller)
{
	m_controller = controller;
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_position = position;
	m_size = Math::Vector3(Size::kCharaX, Size::kCharaY, Size::kCharaZ);
	m_rotation = Math::Vector3(0, 0, 0);
	m_hp = hp;
	m_mp = 0;
	m_speed = 4;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_side = side;
	m_id = id;
}

CharacterBase::~CharacterBase()
{
	m_controller = NULL;
}

//������
void CharacterBase::Initialize(Math::Vector3 position, int hp)
{
	m_position = position;
	m_hp = hp;
	m_mp = 0;
	m_speed = 4;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
}

//�X�V
void CharacterBase::Update()
{
	Attack();		//�U��
	MoveUpdate();	//�ړ��X�V
	GageUpdate();	//�Q�[�W�X�V
	//���S�X�V
	if (m_hp <= 0)
	{
		m_isDead = true;
	}
}


//�����蔻��
void CharacterBase::Collide()
{

}

//�U��
void CharacterBase::Attack()
{
	//�p���`
	if (m_controller->IsPunchTrigger())
	{

	}
	//�L�b�N
	if (m_controller->IsKickTrigger())
	{

	}
	
}

//���[�V����
void CharacterBase::Motion()
{

}

//�ړ��X�V
void CharacterBase::MoveUpdate()
{
	m_velocity = m_controller->Velocity();
	if (m_controller->IsJumpTrigger())
	{
		m_isJump = true;
		m_velocity.y = 3;
	}

	m_speed = 4;
	if (m_controller->IsRun())
	{
		m_speed = 8;
	}
	else
	{
		
		m_speed = 5;
		
	}
	m_position += m_velocity * m_speed;
}

//�Q�[�W�X�V
void CharacterBase::GageUpdate()
{
	++m_mp;
	if (m_mp >= 3000)
	{
		m_mp = 3000;
	}
}

//�����̍X�V
void CharacterBase::DirectionUpdate()
{
}

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

Math::CollisionBox CharacterBase::GetBox()
{
	return Math::CollisionBox(m_position - Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), m_position + Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
}
