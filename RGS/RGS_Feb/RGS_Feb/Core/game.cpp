//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2017.12.04
// ���e�@�FGame�̊�{����
//-------------------------------------------------------
#include <Core\game.h>

using namespace Core;

//����������
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
	////�\���ʒu��ݒ�
	//m_ss_player->setPosition(0, 0);
	////�X�P�[���ݒ�
	//m_ss_player->setScale(1.0f, 1.0f);
	////��]��ݒ�
	//m_ss_player->setRotation(0.0f, 0.0f, 0.0f);
	////�����x��ݒ�
	//m_ss_player->setAlpha(255);
	////���]��ݒ�
	//m_ss_player->setFlip(false, false);

}

//���[�h�R���e���c
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

	//m_content_manager->LoadFont("MS UI Gothic", 50, 3);			//Word��Font��������
}

//�R���e���c���
void Game::Unload()
{
	//delete (m_ss_player);
}

//�X�V����
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(KEY_INPUT_ESCAPE))
		m_end_flag = true;

	m_scene_manager->Update();

	position += m_input_state->GetKeyBoardVelocity();
	position += m_input_state->GetLeftStick(0);
}

//�`�揈��
void Game::Draw()
{
	m_renderer->Clear(50, 50, 100);

	m_scene_manager->Draw();

	m_renderer->DrawString("Hellow World", Math::Vector2(0, 0));

	m_renderer->DrawMotion3D("test", 0, position, 5);

	m_renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_end_flag;
}