//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：Keyboardで制御するキャラコントローラー
//-------------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\Controller\character_controller.h>

namespace Character 
{
	class KeyboardController : public VirtualController
	{
	public:
		KeyboardController(int player_num);
		KeyboardController(const KeyboardController&);
		~KeyboardController();

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

	private:
		std::shared_ptr<Core::InputState> m_input;
	};
}