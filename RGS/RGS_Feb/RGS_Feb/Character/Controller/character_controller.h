//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：キャラコントローラーのインターフェース
//-------------------------------------------------------------
#pragma once
#include <Math\vector3.h>

namespace Character 
{
	class VirtualController 
	{
	public:
		~VirtualController() {}

		///<summary>移動量</summary>
		Math::Vector3 virtual Velocity()	= 0;
		///<summary>Punchが押したか？</summary>
		bool virtual IsPunchTrigger()		= 0;
		///<summary>Kickが押したか？</summary>
		bool virtual IsKickTrigger()		= 0;
		///<summary>Runが押されているか？</summary>
		bool virtual IsRun()				= 0;
		///<summary>Jumpが押したか？</summary>
		bool virtual IsJumpTrigger()		= 0;
		///<summary>Defenceが押されているか？</summary>
		bool virtual IsDefence()			= 0;

	private:
	};
}