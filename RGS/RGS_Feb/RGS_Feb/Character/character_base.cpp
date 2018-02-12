//-------------------------------------------------------
// �쐬�ҁF���@�~��
// �쐬���F2018.02.05
// ���e�@�F�L�����N�^�[�̃x�[�X�N���X
//-------------------------------------------------------
#include <Character\character_base.h>

using namespace Character;


CharacterBase::CharacterBase()
{
	m_input = Device::GameDevice::GetInstance()->GetInput();
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_position = Math::Vector3(0, 0, 0);
	m_size = Math::Vector3(10, 0, 10);
	m_rotation = Math::Vector3(0, 0, 0);
	m_hp = 500;
	m_gage = 0;
	m_atk_state = 0;
	m_atk_cnt = 0;
	m_isDead = false;
	m_isJump = false;
}

CharacterBase::~CharacterBase()
{
}

//������
void CharacterBase::Initialize()
{
	m_position = Math::Vector3(0, 0, 0);
	m_hp = 500;
	m_gage = 0;
	m_atk_state = 0;
	m_isDead = false;
	m_isJump = false;
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
		if (m_input->IsKeyTrigger(KEY_INPUT_X))
		{
			m_renderer->DrawString("�p���`�̏��Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_Z))
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
		if (m_input->IsKeyTrigger(KEY_INPUT_X))
		{
			m_renderer->DrawString("�p���`�̑�Z", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_Z))
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

//�ړ��X�V
void CharacterBase::MoveUpdate()
{
	m_velocity = m_input->GetKeyBoardVelocity();
	if (m_input->IsKeyDown(KEY_INPUT_SPACE))
	{
		m_isJump = true;
		m_velocity.y = 3;
	}

	float speed = 5;
	if (true)
	{
		speed += 0.2;
		if (speed >= 8)
		{
			speed = 8;
		}
	}
	m_position += m_velocity * speed;
}

//�Q�[�W�X�V
void CharacterBase::GageUpdate()
{
	++m_gage;
	if (m_gage >= 3000)
	{
		m_gage = 3000;
	}
}

//�`��
void CharacterBase::Draw()
{
	m_renderer->DrawModel("test", m_position,m_size,m_rotation);
}


