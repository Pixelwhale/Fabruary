//-------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：GamePlayシーン
//-------------------------------------------------------
#include <Scene\gameplay.h>
#include <Character\Controller\keyboard_controller.h>
#include <GameObject\Job\programmer.h>
#include <GameObject\Job\planner.h>
#include <GameObject\Job\com_graphic.h>
#include <GameObject\Job\business.h>

using namespace Scene;

GamePlay::GamePlay(std::shared_ptr<GameManager> game_manager)
	:m_game_manager(game_manager)
{
}

void GamePlay::Initialize(SceneType previous)
{
	m_is_end = false;
	m_previous = previous;

	if (previous == SceneType::kPause ||
		previous == SceneType::kGamePlay)
		return;

	m_attack_manager = make_shared<AttackSystem::AttackManager>();
	m_character_manager = make_shared<Character::CharacterManager>();
	m_attack_manager->Initialize();

	m_character_manager->Initialize();
	m_character_manager->Add(Math::Vector3(), Side::kTeam1, make_shared<Character::KeyboardController>(), make_shared<Job::Programmer>(Side::kTeam1), m_attack_manager);

	m_meta_ai = make_shared<AI::MetaAI>(m_character_manager, m_attack_manager);
	m_meta_ai->AddCom(Math::Vector3(400, 0, 20), Side::kTeam3, make_shared<Job::Business>(Side::kTeam3), 2);
}

void GamePlay::Update()
{
	m_meta_ai->Update();
	m_character_manager->Update();
	m_attack_manager->Update(m_character_manager);

	CheckEnd();
}

void GamePlay::CheckEnd()
{
	if (m_character_manager->GetEnd() ||
		m_input->IsKeyTrigger(KEY_INPUT_N))
	{
		m_is_end = true;
		m_next = SceneType::kGameResult;
		return;
	}

	if (m_input->IsKeyTrigger(KEY_INPUT_P))
	{
		m_is_end = true;
		m_next = SceneType::kPause;
		return;
	}
}

void GamePlay::Draw()
{
	m_renderer->DrawString("GamePlay", Math::Vector2(150, 0));
	m_character_manager->Draw();
	m_attack_manager->Draw();
}

void GamePlay::Shutdown()
{
	if (m_next == SceneType::kPause ||
		(m_next == SceneType::kGameResult && m_previous != SceneType::kGamePlay))
		return;

	m_meta_ai = NULL;
	m_character_manager = NULL;
	m_attack_manager = NULL;
}