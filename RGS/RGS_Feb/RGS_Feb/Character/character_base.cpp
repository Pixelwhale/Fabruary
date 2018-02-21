//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#include <Character\character_base.h>
#include <Device\game_device.h>

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
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_position = position;
	m_size = Math::Vector3(Size::kCharaX, Size::kCharaY, Size::kCharaZ);
	m_rotation = Math::Vector3(0, 0, 0);
	m_hp = m_job->GetHp();
	m_mp = 0;
	m_speed = 4;
	m_knock_value = 0;
	m_knock_cnt = 0;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_isInvincible = false;
	m_isStop = false;
	m_side = side;
	m_id = id;
	m_state = CharacterState::kIdle;
}

CharacterBase::~CharacterBase()
{
	m_controller = NULL;
	m_motion = NULL;
	m_renderer = NULL;
	m_job = NULL;
	m_attack_mediator = NULL;
}

//初期化
void CharacterBase::Initialize(Math::Vector3 position)
{
	m_position = position;
	m_hp = m_job->GetHp();
	m_mp = 0;
	m_speed = 4;
	m_knock_value = 0;
	m_knock_cnt = 0;
	m_velocity_y = 0;
	m_isDead = false;
	m_isJump = false;
	m_isRight = true;
	m_isStop = false;
	m_isInvincible = false;
	m_motion->Initialize();
	m_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_motion->Play("chara_base_anime/idle");
	m_motion->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	m_state = CharacterState::kIdle;
}

//更新
void CharacterBase::Update()
{
	Attack();		//攻撃
	MoveUpdate();	//移動更新
	GageUpdate();	//ゲージ更新
	MotionUpdate(); //モーションの更新
	StateUpdate();	//状態の更新
	KnockCntUpdate();//倒れ値カウント更新
	m_job->Update();//Jobの更新
	//死亡更新
	if (m_hp <= 0)
	{
		m_isDead = true;
	}
}

//倒れ値カウント更新
void CharacterBase::KnockCntUpdate()
{
	m_knock_cnt++;
	//180(3秒)を超えたら、倒れ値が下がる
	if (m_knock_cnt >= 180)
	{
		m_knock_value--;
		m_knock_cnt = 180;
	}
}


//あたり判定
void CharacterBase::Collide(int damage,int knockBack, int knockDown, bool fromRight)
{
	if (m_state == CharacterState::kDefence && m_isRight == fromRight)
	{
		return;
	}

	m_knock_cnt = 0;
	m_isStop = true;
	m_hp -= damage;
	m_knock_value += knockBack;

	if (fromRight)
	{
		m_velocity.x = -knockBack;
	}
	else if (!fromRight)
	{
		m_velocity.x = knockBack;
	}

	//倒れ値を超えたら、倒れる
	if (m_knock_value > m_job->KnockValue())
	{
		m_state = CharacterState::kKnockDown;
		m_motion->Play("chara_base_anime/knock_down",1);
		m_isStop = true;
		m_knock_value = 0;
	}
	else
	{
		m_state = CharacterState::kKnockBack;
		m_motion->Play("chara_base_anime/damage",1);
		m_isStop = true;
	}
}

//攻撃
void CharacterBase::Attack()
{
	//パンチ
	if (m_controller->IsPunchTrigger())
	{
		m_motion->Play(m_job->Punch(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kPunch;
		m_isStop = true;
	}
	//キック
	if (m_controller->IsKickTrigger())
	{
		m_motion->Play(m_job->Kick(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kKick;
		m_isStop = true;
	}
	//防御
	if (m_controller->IsDefence())
	{
		m_state = CharacterState::kDefence;
		m_motion->Play("chara_base_anime/defence", 1);
		m_isStop = true;

	}
	
}

//モーション
void CharacterBase::Draw()
{
	m_motion->Draw();
	//Device::GameDevice::GetInstance()->GetRenderer()->DrawString(m_velocity.y, Math::Vector2(100, 0));
}

//モーションの更新
void CharacterBase::MotionUpdate()
{
	m_motion->Update();

	//向き
	if (m_velocity.x > 0)
	{
		m_isRight = true;
	}
	if (m_velocity.x < 0)
	{
		m_isRight = false;
	}
	m_motion->Flip(m_isRight, false);
	m_motion->SetPosition(m_position);
}

//移動更新
void CharacterBase::MoveUpdate()
{
	//攻撃、攻撃を受けた状態ではないと入力による移動可能
	if (!m_isStop)
	{
		m_velocity = m_controller->Velocity();
		m_velocity.y = m_velocity_y;
	}
	
	m_speed = 4;
	if (m_velocity.lengthSqrt() != 0 && !m_isStop)
	{
		//run
		if (m_controller->IsRun())
		{
			m_state = CharacterState::kRun;
			m_motion->Play("chara_base_anime/run");
			m_speed = 8;
		}
		else
		{
			//歩き
			m_state = CharacterState::kWalk;
			m_motion->Play("chara_base_anime/walk");
			m_speed = 4;
		}
	}
	else if (m_velocity.lengthSqrt() == 0 && !m_isStop)
	{
		m_motion->Play("chara_base_anime/idle");
	}
	

	//jump
	if (m_controller->IsJumpTrigger() && !m_isJump)
	{
		m_state = CharacterState::kJump;
		m_motion->Play("chara_base_anime/jump",1);
		m_isJump = true;
		m_velocity_y = 30;
	}
	if (m_position.y <= 0)
	{
		m_isJump = false;
		m_velocity_y = 0;
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

//状態の更新
void CharacterBase::StateUpdate()
{
	//防御か倒られた時は無敵
	if (m_state == CharacterState::kKnockDown)
	{
		m_isInvincible = true;
	}
	else
	{
		m_isInvincible = false;
	}

	//モーションが終わったら、待機状態に
	if (m_isStop)
	{
		m_velocity = Math::Vector3(0, 0, 0);
		if (m_motion->IsCurrentMotionEnd())
		{
			m_state = CharacterState::kIdle;
			m_motion->Play("chara_base_anime/idle");
			m_isStop = false;
		}
	}
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

//無敵フラグ
bool CharacterBase::IsInvincible()
{
	return m_isInvincible;
}

Math::CollisionBox CharacterBase::GetBox()
{
	return Math::CollisionBox(m_position - Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), m_position + Math::Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
}
