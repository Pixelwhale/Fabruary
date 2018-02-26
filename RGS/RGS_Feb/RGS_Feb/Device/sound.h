//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.5
// ���e�@�FSound�@�\�𐮗������N���X
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

#pragma region BGM�֘A

		///<summary>BGM�𗬂�</summary>
		void PlayBGM(std::string bgm_name, int volume = 255 * 75 / 100);

		///<summary>BGM���~</summary>
		void StopBGM();

#pragma endregion

#pragma region SE�֘A

		///<summary>SE�𗬂�</summary>
		void PlaySE(std::string se_name, int volume = 255);

#pragma endregion

	private:
		std::shared_ptr<ContentManager> m_contents;			//Content Manager
		std::string m_current_bgm;							//���ݗ���Ă���BGM
	};
}