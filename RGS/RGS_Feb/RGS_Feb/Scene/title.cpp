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
}

void Title::Update()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE))
	{
		m_is_end = true;
		m_next = kGamePlay;
	}

	m_background->Update();					//背景更新
}

void Title::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//背景

	m_renderer->DrawString("Title", Math::Vector2(150, 0));

	m_background->DrawFront();				//前景
	m_renderer->DrawBloom();				//BloomEffect
}

void Title::Shutdown()
{
	m_background = NULL;
}