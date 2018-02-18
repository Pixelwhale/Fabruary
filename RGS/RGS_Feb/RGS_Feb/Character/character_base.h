//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>;
#include <Math\vector3.h>;
#include<Character\side.h>;
#include<GameObject\Job\job_base.h>;
#include<Math\collision_box.h>

namespace Character
{
	class CharacterBase
	{
	public:
		CharacterBase();		//コンストラクタ
		CharacterBase(Math::Vector3 position,Side side);
		~CharacterBase();		//デストラクタ
		void Initialize();		//初期化
		void Update();			//更新
		void Hit();				//あたり判定
		bool Collision(CharacterBase other);//当たったか？
		void Attack();			//攻撃
		void MoveUpdate();		//移動更新
		void GageUpdate();		//ゲージ更新
		Side GetSide();		//チームの取得
		void SetSide(Side side);//チームの設定
		int GetHp();			//Hpの取得
		int GetMp();			//Mpの取得
		Math::Vector3 GetPosition();//位置の取得
		void SetPosition(Math::Vector3 position);//位置の設定
		bool IsRight();			//向きを返す
		void DirectionUpdate();	//向きの更新
		void Motion();			//モーション

	private:
		int m_hp;				
		int m_mp;
		int m_atk_state;		//攻撃状態
		int m_atk_cnt;			//技を打つカウント
		bool m_isDead;
		bool m_isJump;
		bool m_isRight;
		Side m_side;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Core::InputState> m_input;
		std::shared_ptr<Device::Renderer> m_renderer;
		
	protected:
		Job::JobBase m_job;
	};


}