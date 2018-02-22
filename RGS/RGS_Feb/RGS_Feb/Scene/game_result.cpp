//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�F�Q�[���I���V�[��
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
	CheckEnd();
}

void GameResult::Draw()
{
	m_game_scene->Draw();

	m_renderer->DrawString("Vector", Math::Vector2());
}

void GameResult::Shutdown()
{
	m_game_scene->Shutdown();
}

void GameResult::CheckEnd()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE)) 
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
	}
}