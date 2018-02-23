//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#include <Character\character_base.h>

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
}

//初期化
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
	m_velocity_jump = Math::Vector3(0, 0, 0);
	//m_rotation = Math::Vector3(0, 0, 0);
	m_motion->Initialize();
	m_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_motion->Play("chara_base_anime/idle");
	m_motion->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	m_state = CharacterState::kIdle;
	
	//色設定
	if (m_side == Side::kNoTeam)		//白
	{
		m_motion->SetColor(Color(1.0f, 1.0f, 1.0f, 1.0f));
	}
	else if (m_side == Side::kTeam1)	//赤
	{
		m_motion->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	}
	else if (m_side == Side::kTeam2)	//緑
	{
		m_motion->SetColor(Color(0.0f, 1.0f, 0.0f, 1.0f));
	}
	else if (m_side == Side::kTeam3)	//青
	{
		m_motion->SetColor(Color(0.0f, 0.0f, 1.0f, 1.0f));
	}
	else if (m_side == Side::kTeam4)	//黒
	{
		m_motion->SetColor(Color(0.0f, 0.0f, 0.0f, 1.0f));
	}

}

//更新
void CharacterBase::Update()
{
	if (m_hp > 0)
	{
		Attack();		//攻撃
		Skill();		//スキール
		MoveUpdate();	//移動更新
		JumpUpdate();	//Jump更新
		MpUpdate();	//ゲージ更新
		StateUpdate();	//状態の更新
		KnockCntUpdate();//倒れ値カウント更新
		m_job->Update();//Jobの更新
		PositionUpdate();//位置の更新
	}
		MotionUpdate(); //モーションの更新
	//死亡更新
	if (m_hp <= 0 && m_motion->IsCurrentMotionEnd())
	{
		m_isDead = true;
	}
}


//モーション
void CharacterBase::Draw()
{
	m_motion->Draw();
	//Device::GameDevice::GetInstance()->GetRenderer()->DrawString(std::to_string(m_ukemi_cnt),Math::Vector2(m_position.x,m_position.z));
}


//あたり判定
void CharacterBase::Collide(const AttackSystem::Attack& atk)
{
	bool from_right;
	float  knockback_adjust = 10;
	if (atk.GetDamage() == 0) return;
	//攻撃を受けた方向
	if (atk.GetSourceDir() != AttackSystem::kCenter)
	{
		from_right = (atk.GetSourceDir() == AttackSystem::kRight);
	}
	else
	{
		from_right = (atk.GetPosition().x > m_position.x);
	}

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

	//防御の時,防御値が最大値より小さいとダメージを受けない
	if (m_state == CharacterState::kDefence &&
		m_isRight == from_right &&
		m_defence_value < m_defence_max)
	{
		m_defence_value += 20;		//引数で受ける
		m_isStop = true;
	}
	else
	{
		//死亡
		if (m_hp - atk.GetDamage() <= 0)
		{
			m_state = CharacterState::kDead;
			m_motion->Play("chara_base_anime/dead", 1);
			m_hp -= atk.GetDamage();
		}
		//倒れ値を超えたら、倒れる
		else if (m_knock_value > m_job->KnockValue())
		{
			m_state = CharacterState::kKnockDown;
			m_motion->Play("chara_base_anime/knock_down",1);
			m_hp -= atk.GetDamage();
			m_knock_value = 0;
			m_defence_value = 0;
			
		}
		//攻撃を受けたモーション
		else
		{
			m_state = CharacterState::kKnockBack;
			m_motion->Play("chara_base_anime/damage",1);
			m_hp -= atk.GetDamage();
			m_knock_value += atk.GetKnockDown();
			m_defence_value = 0;
		}
		//死んだら、向きの更新しない
		//攻撃を受けたモーション向きの更新
		if (m_hp < 0)
		{
			return;
		}
		else
		{
			if (from_right)
			{
				m_isRight = true;
			}
			else
			{
				m_isRight = false;
			}
		}
	}
}

#pragma region 更新関連

//攻撃
void CharacterBase::Attack()
{
	//パンチ
	if (m_controller->IsPunchTrigger() && !m_isStop)
	{
		m_motion->Play(m_job->Punch(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kPunch;
		m_isStop = true;
	}
	//キック
	if (m_controller->IsKickTrigger() && !m_isStop)
	{
		m_motion->Play(m_job->Kick(m_attack_mediator, m_position, m_isRight),1);
		m_state = CharacterState::kKick;
		m_isStop = true;
	}
	//防御
	if (m_controller->IsDefence())
	{
		if (m_state == CharacterState::kKnockDown)
		{
			m_state = CharacterState::kUkemi;
			m_motion->Play("chara_base_anime/ukemi", 1);
			m_isStop = true;
		}
		if (m_state != CharacterState::kUkemi)
		{
			m_state = CharacterState::kDefence;
			m_motion->Play("chara_base_anime/defence");
			m_isStop = true;
		}

	}
}

//スキール
void CharacterBase::Skill()
{
	m_skill_cnt--;
	if (m_skill_cnt <= 0)
	{
		m_skill_num = 0;
	}

	//小技
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
		//パンチの小技
		//m_motion->Play(m_job->Skill1(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kPunch_1;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 300;
	}
	if (m_controller->IsKickTrigger() &&
		m_skill_num == 3 &&
		m_skill_cnt > 0 &&
		m_mp >= 300)
	{
		//キックの小技
		//m_motion->Play(m_job->Skill3(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_1;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 300;
	}
	

	//大技
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
		//パンチの大技
		//m_motion->Play(m_job->Skill2(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kPunch_2;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 1500;
	}
	if (m_controller->IsKickTrigger() && 
		m_skill_num == 6 &&
		m_skill_cnt > 0 &&
		m_mp >= 1500)
	{
		//キックの大技
		//m_motion->Play(m_job->Skill4(m_attack_mediator, m_position, m_isRight), 1);
		//m_state = CharacterState::kKick_2;
		m_isStop = true;
		m_skill_num = 0;
		m_mp -= 1500;
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

//モーションの更新
void CharacterBase::MotionUpdate()
{
	m_motion->Update();

	//向きの更新(Jumpの時はできない)
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

//移動更新
void CharacterBase::MoveUpdate()
{
	//攻撃、攻撃を受けた状態ではないと入力による移動可能
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
				//歩き
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

//位置の更新
void CharacterBase::PositionUpdate()
{
	Math::Vector3 min = Math::Vector3(-WindowDef::kScreenWidth / 2 + Size::kCharaX / 12, -Size::kCharaY,
										-WindowDef::kScreenHeight / 2 - Size::kCharaZ * 3);
	Math::Vector3 max = Math::Vector3(WindowDef::kScreenWidth / 2 - Size::kCharaX / 12,  Size::kCharaY * 4,
								      WindowDef::kScreenHeight / 2 - Size::kCharaZ * 2);

	m_position += Math::Vector3(m_velocity.x * m_speed, m_velocity_jump.y, m_velocity.z * m_speed);

	m_position = m_position.Clamp(m_position,min,max);
}

//Jump更新
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
		m_gravity.Update(m_velocity_jump);
	}
}

//ゲージ更新
void CharacterBase::MpUpdate()
{
	++m_mp;
	if (m_mp >= 6000)
	{
		m_mp = 6000;
	}
}

//状態の更新
void CharacterBase::StateUpdate()
{
	//防御か倒られた時は無敵
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

	//モーションが終わったら、待機状態に
	if (m_isStop)
	{
		//Jumpの時は動ける
		if (!m_isJump && !m_isHit)
		{
			m_velocity = Math::Vector3(0, 0, 0);
		}
		if (m_motion->IsCurrentMotionEnd())
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
			
			//Jumpしていると、Jumpモーションに戻る
			if (m_isJump)
			{
				m_state = CharacterState::kJump;
			}
		}
		
	}
}

#pragma endregion


//Get、Set関連

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

//MaxMpの取得
int CharacterBase::GetMaxHp()
{
	return m_job->GetHp();
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

