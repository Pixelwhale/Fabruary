//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：ゲーム終了シーン
//-------------------------------------------------------------
#include <Scene\game_result.h>

using namespace Scene;

GameResult::GameResult(std::shared_ptr<SceneBase> game_scene)
	:m_game_scene(game_scene)
{
}

void GameResult::Initialize(SceneType previous)
{
	m_is_end = false;
	m_previous = previous;

	m_game_scene->Initialize(previous);
}

void GameResult::Update()
{
	m_game_scene->Update();

	CheckEnd();
}

void GameResult::Draw()
{
	m_game_scene->Draw();
}

void GameResult::Shutdown()
{
	m_game_scene->Shutdown();
}

void GameResult::CheckEnd()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE) ||
		m_input->IsKeyTrigger(KEY_INPUT_A) ||
		m_input->IsKeyTrigger(KEY_INPUT_D))
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
		return;
	}

	for (int i = 0; i < m_input->CurrentPadCount(); ++i) 
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_B) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_A) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_X) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_START))
		{
			m_is_end = true;
			m_next = SceneType::kTitle;
			return;
		}
	}
}