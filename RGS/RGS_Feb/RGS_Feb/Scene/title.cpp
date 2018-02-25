//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.24
// ���e�@�FTitleScene, Effect�ǉ�
//-------------------------------------------------------
#include <Scene\title.h>

using namespace Scene;

Title::Title()
{
	m_next = kGamePlay;
}

void Title::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);

	m_background = make_shared<Background>();
	m_scene_effect = make_shared<SceneEffect>();
	m_scene_effect->Zoom(false);

	m_title_menu = make_shared<UI::TitleStateManager>();
	m_title_menu->Initialize();
}

void Title::Update()
{
	m_background->Update();					//�w�i�X�V
	m_scene_effect->Update();				//Effect�X�V
	m_title_menu->Update();					//Menu�X�V

	CheckEnd();								//�I���`�F�b�N
}

void Title::CheckEnd()
{
	//Effect���I�������I��
	if (m_scene_effect->IsEnd(true))
	{
		m_is_end = true;
		m_next = m_title_menu->NextScene();
	}

	if (m_title_menu->IsEnd())
	{
		//CharacterSelect�Ȃ��Effect����
		if (m_title_menu->NextScene() == SceneType::kCharaSelect) 
		{
			m_scene_effect->Zoom(true);
			return;
		}

		//CharacterSelect�ȊO��Effect����Ȃ�
		m_is_end = true;
		m_next = m_title_menu->NextScene();
		return;
	}
}

void Title::Draw()
{
	m_scene_effect->DrawOnEffect();			//DrawSceneChangeEffect
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//�w�i
	m_background->DrawFront();				//�O�i

	m_title_menu->Draw();

	m_renderer->DrawBloom();				//BloomEffect
	m_scene_effect->DrawEffect();			//DrawSceneChangeEffect
}

void Title::Shutdown()
{
	m_title_menu->Clear();
	m_title_menu = NULL;

	m_background = NULL;
	m_scene_effect = NULL;
}