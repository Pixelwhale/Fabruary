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

#pragma region BGM�֘A

//BGM�𗬂ꂷ
void Sound::PlayBGM(std::string bgm_name) 
{
	if (bgm_name != m_current_bgm) 
	{
		StopBGM();
		m_current_bgm = bgm_name;
	}

	int handle = m_contents->BGMHandle(bgm_name);
	if (CheckMusic() == 1)					//1�͍Đ���
		return;

	PlayMusicMem(handle, DX_PLAYTYPE_LOOP);
}

//BGM���~
void  Sound::StopBGM()
{
	int handle = m_contents->BGMHandle(m_current_bgm);

	if (CheckMusic() == 1)					//1�͍Đ���
	{
		StopMusicMem(handle);
		m_current_bgm.clear();
	}
}

#pragma endregion

#pragma region SE

//SE�𗬂�
void Device::Sound::PlaySE(std::string se_name)
{
	int handle = DuplicateSoundMem(m_contents->SEHandle(se_name));

	PlaySoundMem(handle, DX_PLAYTYPE_BACK);
	SetPlayFinishDeleteSoundMem(true, handle);
}

#pragma endregion
