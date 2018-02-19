//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
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

//初期化
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
	//小技
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
			m_renderer->DrawString("パンチの小技", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_renderer->DrawString("キックの小技", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
	}

	//大技
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
			m_renderer->DrawString("パンチの大技", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
		if (m_input->IsKeyTrigger(KEY_INPUT_D))
		{
			m_renderer->DrawString("キックの大技", Math::Vector2(100, 100));
			m_atk_state = 0;
		}
	}

	//10フレーム以内に技を打たないと
	//m_atk_state = 0に
	if (m_atk_state > 0)
	{
		m_atk_cnt++;
		if (m_atk_cnt > 10)
		{
			m_atk_state = 0;
		}
	}
	
}

//モーション
void CharacterBase::Motion()
{
}

//移動更新
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

