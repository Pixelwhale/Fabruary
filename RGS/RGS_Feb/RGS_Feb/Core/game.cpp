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

	m_game_device->GetContent()->LoadSSFile("Character_base/Character.ssbp");
	m_test_motion = std::make_shared<MotionSystem::Motion>("Character");
	m_test_motion->Initialize();
	m_test_motion->SetScale(Math::Vector2(1.0f, 1.0f));
	m_test_motion->Play("chara_base_anime/idle");
	m_test_motion2 = std::make_shared<MotionSystem::Motion>("Character");
	m_test_motion2->Initialize();
	m_test_motion2->SetScale(Math::Vector2(1.0f, 1.0f));
	m_test_motion2->Play("chara_base_anime/idle");
	m_test_motion->SetColor(Color(1.0f, 0.0f, 0.0f, 1.0f));
	m_motion_right = false;
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
	/*m_game_device->GetContent()->LoadBGM("Battle-FatalBlood", ".mp3");
	m_game_device->GetContent()->LoadSE("press2", ".wav");
	m_game_device->GetContent()->LoadSE("attack1", ".wav");*/

	//m_content_manager->LoadFont("MS UI Gothic", 50, 3);			//WordでFont名を見る
}

//コンテンツ解放
void Game::Unload()
{
	m_test_motion = NULL;
	m_test_motion2 = NULL;
}

//更新処理
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(KEY_INPUT_ESCAPE))
		m_end_flag = true;

	m_scene_manager->Update();

	m_test_motion->Update();
	m_test_motion2->Update();
	Math::Vector3 velocity = m_game_device->GetInput()->GetKeyBoardVelocity() * 8;
	m_position += velocity;
	if (velocity.lengthSqrt() != 0) 
	{
		m_test_motion->Play("chara_base_anime/run");
		if (velocity.x > 0) 
		{
			m_test_motion->Flip(true, false);
			m_motion_right = true;
		}
		if (velocity.x < 0) 
		{
			m_test_motion->Flip(false, false);
			m_motion_right = false;
		}
	}
	else
	{
		m_test_motion->Play("chara_base_anime/idle");
		m_test_motion->Flip(m_motion_right, false);
	}
	m_test_motion->SetPosition(m_position);
}

//描画処理
void Game::Draw()
{
	m_renderer->Clear(100, 149, 237);

	m_scene_manager->Draw();
	
	m_test_motion2->Draw();
	m_test_motion->Draw();

	m_renderer->Swap();
}

//終わっているか
bool Game::IsEnd()
{
	return m_end_flag;
}