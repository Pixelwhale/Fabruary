//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.8
// ���e�@�FSpriteStudio�̋@�\���ȒP�ɂ܂Ƃ߂����[�V�����N���X
//-------------------------------------------------------------
#include <Device\MotionSystem\motion.h>
#include <Device\game_device.h>

using namespace MotionSystem;

Motion::Motion(string asset_name)
{
	m_motion_player = ss::Player::create();
	m_motion_player->setData(asset_name);

	m_projector = Device::GameDevice::GetInstance()->GetProjector();
}

Motion::Motion(const Motion &)
{
}

Motion::~Motion()
{
	Release();
}

void Motion::Initialize()
{
	m_position = Math::Vector3();
	m_scale = Math::Vector2(1, 1);
	m_motion_player->setPosition(m_position.x, m_position.y);	//�\���ʒu��ݒ�
	m_motion_player->setScale(m_scale.x, m_scale.y);			//�X�P�[���ݒ�
	m_motion_player->setRotation(0.0f, 0.0f, 0.0f);				//��]��ݒ�
	m_motion_player->setAlpha(255);								//�����x��ݒ�
	m_motion_player->setFlip(false, false);						//���]��ݒ�
}

void Motion::Release()
{
	if(m_motion_player)
		delete(m_motion_player);
}

void Motion::Play(string motion_name, int loop)
{
	if (m_current_motion == motion_name && !IsCurrentMotionEnd())
		return;

	m_current_motion = motion_name;
	m_motion_player->play(motion_name, loop);
}

void Motion::Update()
{
	m_motion_player->update(1 / 60.0f);
}

void Motion::Draw()
{
	m_projector->SetTargetDepth(m_position.z);
	m_motion_player->draw();
	m_projector->PopSetting();
}

void Motion::SetPosition(Math::Vector3 position)
{
	m_position = position;
	m_motion_player->setPosition(position.x, position.y);
}

void Motion::SetColor(Color color)
{
	m_motion_player->setColor(color.r, color.g, color.b);
	m_motion_player->setAlpha(color.a);
}

void Motion::SetScale(Math::Vector2 scale)
{
	m_scale = scale;
	m_motion_player->setScale(scale.x, scale.y);
}

void  Motion::Flip(bool x, bool y) 
{
	if ((x && m_scale.x > 0) ||
		(!x && m_scale.x < 0))
		m_scale.x *= -1;
	if ((y && m_scale.y > 0) ||
		(!y && m_scale.y < 0))
		m_scale.y *= -1;

	SetScale(m_scale);
}

//���݂̃t���[�����ő�t���[���i�Ō�܂Ńv���C�����j
bool Motion::IsCurrentMotionEnd()
{
	return m_motion_player->getFrameNo() == m_motion_player->getMaxFrame();
}
