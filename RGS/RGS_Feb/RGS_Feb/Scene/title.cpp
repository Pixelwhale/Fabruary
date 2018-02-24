//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：TitleScene, Effect追加
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
	m_background->Update();					//背景更新
	m_scene_effect->Update();				//Effect更新
	m_title_menu->Update();

	CheckEnd();
}

void Title::CheckEnd()
{
	if (m_scene_effect->IsEnd(true))
	{
		m_is_end = true;
		m_next = m_title_menu->NextScene();
	}

	if (m_title_menu->IsEnd())
	{
		m_scene_effect->Zoom(true);
		return;
	}
}

void Title::Draw()
{
	m_scene_effect->DrawOnEffect();			//DrawSceneChangeEffect
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//背景
	m_background->DrawFront();				//前景

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