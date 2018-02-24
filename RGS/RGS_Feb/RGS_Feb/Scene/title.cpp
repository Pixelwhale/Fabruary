//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2017.12.22
// 内容　：タイトルのシーン。スタート、ロード、オプション。
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
}

void Title::Update()
{
	CheckEnd();

	m_background->Update();					//背景更新
	m_scene_effect->Update();
}

void Title::CheckEnd() 
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE))
	{
		m_scene_effect->Zoom(true);
		return;
	}

	if (m_scene_effect->IsEnd(true))
	{
		m_is_end = true;
		m_next = kCharaSelect;
	}
}

void Title::Draw()
{
	m_scene_effect->DrawOnEffect();			//DrawSceneChangeEffect
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//背景

	m_renderer->DrawString("Title", Math::Vector2(150, 0));

	m_background->DrawFront();				//前景
	m_renderer->DrawBloom();				//BloomEffect
	m_scene_effect->DrawEffect();			//DrawSceneChangeEffect
}

void Title::Shutdown()
{
	m_background = NULL;
}