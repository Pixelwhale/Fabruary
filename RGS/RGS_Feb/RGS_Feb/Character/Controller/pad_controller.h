//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Padで制御するキャラコントローラー
//-------------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\Controller\character_controller.h>

namespace Character
{
	class PadController : public VirtualController
	{
	public:
		///<summary>Pad_IDは0～3まで</summary>
		PadController(int pad_id);
		PadController(const PadController&);
		~PadController();

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

	private:
		std::shared_ptr<Core::InputState> m_input;
		int m_pad_id;
	};
}