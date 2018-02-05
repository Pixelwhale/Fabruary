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

	m_scene_manager = std::make_shared<Scene::SceneManager>();
	m_scene_manager->Initialize();

	//m_game_device->GetContent()->LoadSSFile("TestCharacter/player.ssbp");
	//m_ss_player = ss::Player::create();
	//m_ss_player->setData("player");
	//m_ss_player->play("player_idle/idle");
	////表示位置を設定
	//m_ss_player->setPosition(0, 0);
	////スケール設定
	//m_ss_player->setScale(1.0f, 1.0f);
	////回転を設定
	//m_ss_player->setRotation(0.0f, 0.0f, 0.0f);
	////透明度を設定
	//m_ss_player->setAlpha(255);
	////反転を設定
	//m_ss_player->setFlip(false, false);

}

//ロードコンテンツ
void Game::Load()
{
	/*m_game_device->GetContent()->LoadTexture("load", ".png");
	m_game_device->GetContent()->LoadTexture("test", ".png");
	m_game_device->GetContent()->LoadTexture("block_ground", ".png");
	m_game_device->GetContent()->LoadTexture("player", ".png");
	m_game_device->GetContent()->LoadTexture("moemoe", ".png");
	m_game_device->GetContent()->LoadTexture("moemoe_mask", ".png");
	m_game_device->GetContent()->LoadTexture("mask", ".png");
	m_game_device->GetContent()->LoadTexture("test", ".png", 6, 6, 1, 64, 64);*/
	m_game_device->GetContent()->LoadTexture("test", ".png", 6, 6, 1, 64, 64);

	//m_content_manager->LoadFont("MS UI Gothic", 50, 3);			//WordでFont名を見る
}

//コンテンツ解放
void Game::Unload()
{
	//delete (m_ss_player);
}

//更新処理
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(KEY_INPUT_ESCAPE))
		m_end_flag = true;

	m_scene_manager->Update();

	position += m_input_state->GetKeyBoardVelocity();
	position += m_input_state->GetLeftStick(0);
}

//描画処理
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_scene_manager->Draw();

	m_renderer->DrawString("Hellow World", Math::Vector2(0, 0));

	m_renderer->DrawMotion3D("test", 0, position, 5);

	m_renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_end_flag;
}