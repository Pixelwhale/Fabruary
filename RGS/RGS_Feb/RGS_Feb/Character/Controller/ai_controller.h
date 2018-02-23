//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Aiで制御するキャラコントローラー
//-------------------------------------------------------------
#pragma once
#include <Character\Controller\character_controller.h>

namespace Character 
{
	class AiController : public VirtualController
	{
	public:
		AiController(int player_num);
		AiController(const AiController&);
		~AiController();

		///<summary>移動量</summary>
		Math::Vector3 virtual Velocity();
		///<summary>Punchが押したか？</summary>
		bool virtual IsPunchTrigger();
		///<summary>Kickが押したか？</summary>
		bool virtual IsKickTrigger();
		///<summary>Runが押されているか？</summary>
		bool virtual IsRun();
		///<summary>Jumpが押したか？</summary>
		bool virtual IsJumpTrigger();
		///<summary>Defenceが押されているか？</summary>
		bool virtual IsDefence();

		///<summary>操作キャラのヒント描画</summary>
		void virtual Draw(Math::Vector3 draw_pos);
		///<summary>タグの色設定（最初行うだけ）</summary>
		void virtual SetTagColor(Color color);
		///<summary>タグ更新</summary>
		void virtual UpdateMotion();

	public:
		///<summary>Keyを先にUpdate</summary>
		void Update();
		///<summary>移動量設定</summary>
		void SetVelocity(Math::Vector3 velocity);
		///<summary>パンチする</summary>
		void TriggerPunch();
		///<summary>キックする</summary>
		void TriggerKick();
		///<summary>ジャンプする</summary>
		void TriggerJump();
		///<summary>走る</summary>
		void Run();
		///<summary>防御</summary>
		void Defence();

	private:
		Math::Vector3 m_velocity;	//移動量
		bool m_previous_punch;		//前フレームのパンチキー
		bool m_current_punch;		//今フレームのパンチキー
		bool m_previous_kick;		//前フレームのキックキー
		bool m_current_kick;		//今フレームのキックキー
		bool m_run;					//走るか
		bool m_previous_jump;		//前フレームのジャンプキー
		bool m_current_jump;		//今フレームのジャンプキー
		bool m_defence;				//防御するか
	};
}