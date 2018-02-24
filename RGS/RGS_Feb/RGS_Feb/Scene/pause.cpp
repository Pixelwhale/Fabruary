//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：Pauseシーン
//-------------------------------------------------------
#include <Scene\pause.h>
#include <Def\window_def.h>

using namespace Scene;

Pause::Pause(std::shared_ptr<SceneBase> game_play, shared_ptr<GameManager> game_manager)
	:m_game_play(game_play), m_game_manager(game_manager)
{
}

void Pause::Initialize(SceneType previous)
{
	m_previous = previous;

	m_blur_ratio = 10;
	m_blur_switch = true;
	m_is_end = false;
}

void Pause::Update()
{
	if (CheckEnd())
		return;

	if(m_game_manager->PauseController()->IsPause())
		m_blur_switch = false;

	UpdateEffect();
}

void Pause::UpdateEffect()
{
	if (m_blur_switch)
	{
		m_blur_ratio += 100;
		m_blur_ratio = (m_blur_ratio >= kBlurMax) ? kBlurMax : m_blur_ratio;
	}
	else
	{
		m_blur_ratio -= 100;
	}
}

bool Pause::CheckEnd()
{
	if (m_blur_ratio > 0)						//ぼかしが元に戻るまで待つ
		return false;

	m_is_end = true;
	m_next = m_previous;
	return true;
}

void Pause::Draw()
{
	m_renderer->DrawOnGaussFilter();			//RenderTargetに描画

	m_game_play->Draw();						//ゲームシーン描画

	m_renderer->GaussFilter(m_blur_ratio);		//Filter効果で描画

	m_renderer->DrawTexture(
		"pause",
		Math::Vector2(WindowDef::kScreenWidth / 2 - 256, WindowDef::kScreenHeight / 2 - 128),
		m_blur_ratio * 1.0f / kBlurMax);
}

void Pause::Shutdown()
{
}