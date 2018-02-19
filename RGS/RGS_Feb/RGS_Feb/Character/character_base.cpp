//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Character\character_base.h>

using namespace Character;


CharacterBase::CharacterBase(Math::Vector3 position,Side side,int id,int hp)
{
	m_input = Device::GameDevice::GetInstance()->GetInput();
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_position = position;
	m_size = Math::Vector3(64, 128, 20);
	m_rotation = Math::Vector3(0, 0, 0);
	m_hp = hp;
	m_mp = 0;
	m_atk_state = 0;
	m_atk_cnt = 0;
	m_speed = 5;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_side = side;
	m_id = id;
}

CharacterBase::~CharacterBase()
{
}

//������
void CharacterBase::Initialize(Math::Vector3 position, int hp)
{
	m_position = position;
	m_hp = hp;
	m_mp = 0;
	m_speed = 5;
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
	//���Z
	if (m_input->IsKeyDown(KEY_INPUT_RIGHT) ||
		m_input->IsKeyDown(KEY_INPUT_LEFT))
	{
		m_atk_state = 1;
	}
	if (m_atk_state == 1 && 
		(m_input->IsKeyTrigger(KEY_INPUT_LEFT) || 
		 m_input->IsKeyTrigger(KEY_INPUT_RIGHT)) )
	{
		m_atk_state = 2;
	}
	if (m_atk_state == 2)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_renderer->DrawString("�p���`�̏��Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_renderer->DrawString("�L�b�N�̏��Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
	}

	//��Z
	if (m_input->IsKeyDown(KEY_INPUT_UP) ||
		m_input->IsKeyDown(KEY_INPUT_DOWN))
	{
		m_atk_state = 4;
	}
	if (m_atk_state == 4 &&
		(m_input->IsKeyTrigger(KEY_INPUT_UP) ||
			m_input->IsKeyTrigger(KEY_INPUT_DOWN)))
	{
		m_atk_state = 5;
	}
	if (m_atk_state == 5)
	{
		if (m_input->IsKeyTrigger(KEY_INPUT_A))
		{
			m_renderer->DrawString("�p���`�̑�Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_renderer->DrawString("�L�b�N�̑�Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
	}

	//10�t���[���ȓ��ɋZ��ł��Ȃ���
	//m_atk_state = 0��
	if (m_atk_state > 0)
	{
		m_atk_cnt++;
		if (m_atk_cnt > 10)
		{
			m_atk_state = 0;
		}
	}
	
}

//���[�V����
void CharacterBase::Motion()
{
}

//�ړ��X�V
void CharacterBase::MoveUpdate()
{
	m_velocity = m_input->GetKeyBoardVelocity();
	if (m_input->IsKeyDown(KEY_INPUT_SPACE))
	{
		m_isJump = true;
		m_velocity.y = 3;
	}

	m_speed = 5;
	if (m_input->IsKeyDown(KEY_INPUT_E))
	{
		m_speed += 0.2f;
		if (m_speed >= 8)
		{
			m_speed = 8;
		}
	}
	else
	{
		m_speed -= 0.2f;
		if (m_speed <= 5)
		{
			m_speed = 5;
		}
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

