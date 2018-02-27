//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2017.12.04
// 内容　：Gameの基本処理
//-------------------------------------------------------
#include <Core\game.h>

using namespace Core;

//初期化処理
void Game::Initialize()
{
	m_end_flag = false;
	m_renderer = m_game_device->GetRenderer();
	
	m_game_device->GetContent()->LoadSSFile("Character_base/Character.ssbp");
	m_game_device->GetContent()->LoadSSFile("Logo/Logo.ssbp");
	m_scene_manager = std::make_shared<Scene::SceneManager>();
	m_scene_manager->Initialize();
}

//ロードコンテンツ
void Game::Load()
{
}

//コンテンツ解放
void Game::Unload()
{
	m_scene_manager = NULL;
}

//更新処理
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(KEY_INPUT_ESCAPE))
		m_end_flag = true;

	m_scene_manager->Update();

	if(m_scene_manager->IsEnd())
		m_end_flag = true;
}

//描画処理
void Game::Draw()
{
	m_renderer->Clear(100, 149, 237);

	m_scene_manager->Draw();

	m_renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_end_flag;
}