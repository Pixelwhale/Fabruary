//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.8
// ���e�@�FSpriteStudio�̋@�\���ȒP�ɂ܂Ƃ߂����[�V�����N���X
//-------------------------------------------------------------
#include <Device\MotionSystem\motion.h>

using namespace MotionSystem;

MotionSystem::Motion::Motion(string asset_name)
{
	m_motion_player = ss::Player::create();
	m_motion_player->setData(asset_name);
	m_position = Math::Vector3();
}

MotionSystem::Motion::Motion(const Motion &)
{
}

MotionSystem::Motion::~Motion()
{
	Release();
}

void MotionSystem::Motion::Initialize()
{
	m_motion_player->setPosition(0, 0);						//�\���ʒu��ݒ�
	m_motion_player->setScale(1.0f, 1.0f);					//�X�P�[���ݒ�
	m_motion_player->setRotation(0.0f, 0.0f, 0.0f);			//��]��ݒ�
	m_motion_player->setAlpha(255);							//�����x��ݒ�
	m_motion_player->setFlip(false, false);					//���]��ݒ�
}

void MotionSystem::Motion::Release()
{
	if(m_motion_player)
		delete(m_motion_player);
}

void MotionSystem::Motion::Play(string motion_name)
{
	m_motion_player->play(motion_name);
}

void MotionSystem::Motion::Update()
{
	m_motion_player->update(1 / 60.0f);
}

void MotionSystem::Motion::Draw() 
{
	m_motion_player->draw();
}

void MotionSystem::Motion::SetPosition(Math::Vector3 position)
{
	m_position = position;
}

void MotionSystem::Motion::SetColor(Color color)
{
	m_motion_player->setColor(color.r, color.g, color.b);
	m_motion_player->setAlpha(color.a);
}

void MotionSystem::Motion::SetScale(Math::Vector2 scale)
{
	m_motion_player->setScale(scale.x, scale.y);
}
