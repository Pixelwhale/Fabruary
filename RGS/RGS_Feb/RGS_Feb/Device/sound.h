//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.5
// 内容　：Sound機能を整理したクラス
//-------------------------------------------------------
#pragma once
#include <DX\DXLib\DxLib.h>
#include <Device\content_manager.h>

namespace Device
{
	class Sound
	{
	public:
		Sound(std::shared_ptr<ContentManager> contents);
		Sound(const Sound&);
		~Sound();

#pragma region BGM関連

		///<summary>BGMを流す</summary>
		void PlayBGM(std::string bgm_name, int volume = 255 * 75 / 100);

		///<summary>BGMを停止</summary>
		void StopBGM();

#pragma endregion

#pragma region SE関連

		///<summary>SEを流す</summary>
		void PlaySE(std::string se_name, int volume = 255);

#pragma endregion

	private:
		std::shared_ptr<ContentManager> m_contents;			//Content Manager
		std::string m_current_bgm;							//現在流れているBGM
	};
}