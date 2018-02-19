//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
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

//初期化
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

//更新
void CharacterBase::Update()
{
	Attack();		//攻撃
	MoveUpdate();	//移動更新
	GageUpdate();	//ゲージ更新
	//死亡更新
	if (m_hp <= 0)
	{
		m_isDead = true;
	}
}


//あたり判定
void CharacterBase::Collide()
{

}

//攻撃
void CharacterBase::Attack()
{
	//パンチ
	if (m_controller->IsPunchTrigger())
	{

	}
	//キック
	if (m_controller->IsKickTrigger())
	{

	}
	
}

//モーション
void CharacterBase::Motion()
{

}

//移動更新
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

//ゲージ更新
void CharacterBase::GageUpdate()
{
	++m_mp;
	if (m_mp >= 3000)
	{
		m_mp = 3000;
	}
}

//向きの更新
void CharacterBase::DirectionUpdate()
{
}

//向きを返す
bool CharacterBase::IsRight()
{
	return m_isRight;
}

//死んだか？
bool CharacterBase::IsDead()
{
	return m_isDead;
}

//チームの取得
Side CharacterBase::GetSide()
{
	return m_side;
}


//Hpの取得
int CharacterBase::GetHp()
{
	return m_hp;
}

//Mpの取得
int CharacterBase::GetMp()
{
	return m_mp;
}

//位置の取得
Math::Vector3 CharacterBase::GetPosition()
{
	return m_position;
}

//位置の設定
void CharacterBase::SetPosition(Math::Vector3 position)
{
	m_position = position;
}

//IDの取得
int CharacterBase::GetID()
{
	return m_id;
}

Math::CollisionBox CharacterBase::GetBox()
{
	return Math::CollisionBox(m_position - Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), m_position + Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
}
