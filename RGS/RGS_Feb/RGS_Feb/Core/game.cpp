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
	
	m_game_device->GetContent()->LoadSSFile("Character_base/Character.ssbp");
	m_game_device->GetContent()->LoadSSFile("Logo/Logo.ssbp");
	m_scene_manager = std::make_shared<Scene::SceneManager>();
	m_scene_manager->Initialize();
}

//���[�h�R���e���c
void Game::Load()
{
}

//�R���e���c���
void Game::Unload()
{
	m_scene_manager = NULL;
}

//�X�V����
void Game::Update()
{
	if (m_input_state->IsKeyTrigger(KEY_INPUT_ESCAPE))
		m_end_flag = true;

	m_scene_manager->Update();

	if(m_scene_manager->IsEnd())
		m_end_flag = true;
}

//�`�揈��
void Game::Draw()
{
	m_renderer->Clear(100, 149, 237);

	m_scene_manager->Draw();

	m_renderer->Swap();
}

//�I����Ă��邩
bool Game::IsEnd()
{
	return m_end_flag;
}