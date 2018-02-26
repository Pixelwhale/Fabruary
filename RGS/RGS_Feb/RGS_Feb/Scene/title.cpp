//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.24
// 内容　：TitleScene, Effect追加
//-------------------------------------------------------
#include <Scene\title.h>

using namespace Scene;

Title::Title(shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect, std::shared_ptr<GameManager> game_manager)
	:m_background(background), m_scene_effect(scene_effect), m_game_manager(game_manager)
{
	m_next = kGamePlay;
}

void Title::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);

	InitSceneEffect();
	SetWinner();

	m_title_menu = make_shared<UI::TitleStateManager>();
	m_title_menu->Initialize();
}

void Title::InitSceneEffect()
{
	//m_scene_effect = make_shared<SceneEffect>();
	m_scene_effect->Zoom(false);

	if (m_previous == SceneType::kCharaSelect)
		m_scene_effect->SetZoomRate(5.0f);
}

void Title::SetWinner()
{
	m_background->SetWinner(m_game_manager->WinnerMotion());
	m_game_manager->ClearWinnerMotion();
}

void Title::Update()
{
	m_background->Update();					//背景更新
	m_scene_effect->Update();				//Effect更新
	m_title_menu->Update();					//Menu更新

	CheckEnd();								//終了チェック
}

void Title::CheckEnd()
{
	//Effectが終わったら終了
	if (m_scene_effect->IsEnd(true))
	{
		m_is_end = true;
		m_next = m_title_menu->NextScene();
	}

	if (m_title_menu->IsEnd())
	{
		//CharacterSelectならはEffect入る
		if (m_title_menu->NextScene() == SceneType::kCharaSelect)
		{
			m_scene_effect->Zoom(true);
			return;
		}

		//CharacterSelect以外はEffect入らない
		m_is_end = true;
		m_next = m_title_menu->NextScene();
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

	//m_scene_effect = NULL;
}