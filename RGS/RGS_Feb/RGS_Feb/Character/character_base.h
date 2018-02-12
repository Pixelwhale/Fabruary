//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>;
#include <Math\vector3.h>;


namespace Character
{
	class CharacterBase
	{
	public:
		CharacterBase();		//コンストラクタ
		~CharacterBase();		//デストラクタ
		void Initialize();		//初期化
		void Update();			//更新
		void Attack();			//攻撃
		void MoveUpdate();		//移動更新
		void GageUpdate();		//ゲージ更新
		void Draw();			//描画
	private:
		int m_hp;				
		int m_gage;
		int m_atk_state;		//攻撃状態
		int m_atk_cnt;			//技を打つカウント
		bool m_isDead;
		bool m_isJump;
		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_size;
		Math::Vector3 m_rotation;
		std::shared_ptr<Core::InputState> m_input;
		std::shared_ptr<Device::Renderer> m_renderer;
	};


}