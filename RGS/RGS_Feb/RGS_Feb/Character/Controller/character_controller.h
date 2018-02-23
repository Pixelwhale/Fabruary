//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：キャラコントローラーのインターフェース
//-------------------------------------------------------------
#pragma once
#include <Math\vector3.h>
#include <Color\color.h>
#include <Device\MotionSystem\motion.h>

namespace Character 
{
	class VirtualController 
	{
	public:
		~VirtualController() {}

		///<summary>移動量</summary>
		Math::Vector3 virtual Velocity()					= 0;
		///<summary>Punchが押したか？</summary>
		bool virtual IsPunchTrigger()						= 0;
		///<summary>Kickが押したか？</summary>
		bool virtual IsKickTrigger()						= 0;
		///<summary>Runが押されているか？</summary>
		bool virtual IsRun()								= 0;
		///<summary>Jumpが押したか？</summary>
		bool virtual IsJumpTrigger()						= 0;
		///<summary>Defenceが押されているか？</summary>
		bool virtual IsDefence()							= 0;
		///<summary>Pauseが押されたか</summary>
		bool virtual IsPause()								= 0;

		///<summary>操作キャラのヒント描画</summary>
		void virtual Draw()									= 0;
		///<summary>タグの色設定（最初行うだけ）</summary>
		void virtual SetTagColor(Color color)				= 0;
		///<summary>タグ更新</summary>
		void virtual UpdateMotion(Math::Vector3 draw_pos)	= 0;

		int PlayerNum() { return m_player_num; }

	protected:
		int m_player_num;							//プレイヤー数
		shared_ptr<MotionSystem::Motion> m_tag;		//Tagモーション
	};
}