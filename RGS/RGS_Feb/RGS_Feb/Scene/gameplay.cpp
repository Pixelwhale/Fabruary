//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
//-------------------------------------------------------
#include <Scene\gameplay.h>
#include <Character\Controller\keyboard_controller.h>
#include <GameObject\Job\programmer.h>

using namespace Scene;

GamePlay::GamePlay()
{
}

void GamePlay::Initialize(SceneType previous)
{
	m_is_end = false;
	m_previous = previous;

	if (previous == SceneType::kPause)
		return;

	m_attack_manager = make_shared<AttackSystem::AttackManager>();
	m_character_manager = make_shared<Character::CharacterManager>();

	m_character_manager->Initialize();
	m_character_manager->Add(Math::Vector3(), Side::kTeam1, 1000, make_shared<Character::KeyboardController>(), make_shared<Job::Programmer>(Side::kTeam1), m_attack_manager);
}

void GamePlay::Update()
{
	m_character_manager->Update();
}

void GamePlay::Draw()
{
	m_renderer->DrawString("GamePlay", Math::Vector2(150, 0));
	//m_character_manager->
}

void GamePlay::Shutdown()
{
}