//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Device\MotionSystem\motion.h>
#include <Math\vector3.h>
#include <Math\collision_box.h>
#include <Character\side.h>
#include <Character\Controller\character_controller.h>
#include <Character\character_state.h>
#include <GameObject\Job\job_base.h>
#include <GameObject\AttackSystem\attack_manager.h>

namespace Character
{
	class CharacterBase
	{
	public:
		//コンストラクタ（位置、チーム、ID、Hp）
		CharacterBase(Math::Vector3 position,Side side,int id,int hp,
			std::shared_ptr<VirtualController> controller,
			std::shared_ptr<Job::JobBase> job,
			std::shared_ptr<AttackSystem::AttackManager> attackManager);
		~CharacterBase();			//デストラクタ
		void Initialize(Math::Vector3 position, int hp);//初期化
		void Update();				//更新
		void Collide();				//あたり判定
		void Attack();				//攻撃
		void Motion();				//モーション

	public:							//取得関連
		Side	GetSide();			//チームの取得
		int		GetHp();			//Hpの取得
		int		GetMp();			//Mpの取得
		int		GetID();			//IDの取得
		Math::Vector3 GetPosition();//位置の取得
		void	SetPosition(Math::Vector3 position);//位置の設定
		bool	IsRight();			//向きを返す
		bool	IsDead();			//死んだか？
		bool	IsInvincible();		//無敵フラグ
		Math::CollisionBox GetBox();
		

	private:						//更新関連
		void MoveUpdate();			//移動更新
		void GageUpdate();			//ゲージ更新
		void MotionUpdate();		//モーションの更新

	private:
		int		m_hp;				
		int		m_mp;
		float	m_speed;
		bool	m_isDead;
		bool	m_isJump;
		bool	m_isRight;
		bool	m_isInvincible;		//無敵フラグ
		int		m_id;
		Side	m_side;
		CharacterState m_state;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Device::Renderer>		m_renderer;
		std::shared_ptr<VirtualController>		m_controller;
		std::shared_ptr<MotionSystem::Motion>	m_motion;
		std::shared_ptr<Job::JobBase>			m_job;
		std::shared_ptr<AttackSystem::AttackManager> m_attack_manager;
	};


}