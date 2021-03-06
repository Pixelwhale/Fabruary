#include <Device\sound.h>

using namespace Device;

Sound::Sound(std::shared_ptr<ContentManager> contents) 
{
	m_contents = contents;
}

Sound::Sound(const Sound&) 
{
}

Sound::~Sound() 
{
}

#pragma region BGM関連

//BGMを流れす
void Sound::PlayBGM(std::string bgm_name, int volume)
{
	if (bgm_name != m_current_bgm) 
	{
		StopBGM();
		m_current_bgm = bgm_name;
	}

	int handle = m_contents->BGMHandle(bgm_name);
	if (CheckMusic() == 1)					//1は再生中
		return;

	ChangeVolumeSoundMem(volume, handle);
	PlayMusicMem(handle, DX_PLAYTYPE_LOOP);
}

//BGMを停止
void  Sound::StopBGM()
{
	int handle = m_contents->BGMHandle(m_current_bgm);

	if (CheckMusic() == 1)					//1は再生中
	{
		StopMusicMem(handle);
		m_current_bgm.clear();
	}
}

#pragma endregion

#pragma region SE

//SEを流す
void Device::Sound::PlaySE(std::string se_name, int volume)
{
	int handle = DuplicateSoundMem(m_contents->SEHandle(se_name));

	ChangeVolumeSoundMem(volume, handle);
	PlaySoundMem(handle, DX_PLAYTYPE_BACK);
	SetPlayFinishDeleteSoundMem(true, handle);
}

#pragma endregion
