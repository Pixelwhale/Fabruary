//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.8
// 内容　：SpriteStudioの機能を簡単にまとめたモーションクラス
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
	m_motion_player->setPosition(0, 0);						//表示位置を設定
	m_motion_player->setScale(1.0f, 1.0f);					//スケール設定
	m_motion_player->setRotation(0.0f, 0.0f, 0.0f);			//回転を設定
	m_motion_player->setAlpha(255);							//透明度を設定
	m_motion_player->setFlip(false, false);					//反転を設定
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
