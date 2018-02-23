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

	m_background = make_shared<Background>();

	m_attack_manager = make_shared<AttackSystem::AttackManager>();
	m_character_manager = make_shared<Character::CharacterManager>();
	m_attack_manager->Initialize();

	m_character_manager->Initialize();
	m_character_manager->Add(Math::Vector3(0, 128, 0), Side::kTeam1, make_shared<Character::KeyboardController>(1), make_shared<Job::Programmer>(Side::kTeam1), m_attack_manager);

	m_meta_ai = make_shared<AI::MetaAI>(m_character_manager, m_attack_manager);
	m_meta_ai->AddCom(Math::Vector3(400, 128, 20), Side::kTeam3, make_shared<Job::Business>(Side::kTeam3), 9, 2);
	m_meta_ai->AddCom(Math::Vector3(-400, 128, 20), Side::kTeam4, make_shared<Job::Planner>(Side::kTeam4), 9, 3);
	m_meta_ai->AddCom(Math::Vector3(0, 128, 0), Side::kTeam2, make_shared<Job::ComputerGraphic>(Side::kTeam2), 9, 4);
}

void GamePlay::Update()
{
	m_background->Update();

	m_meta_ai->Update();
	m_character_manager->Update();
	m_attack_manager->Update(m_character_manager);

	CheckEnd();
}

void GamePlay::CheckEnd()
{
	if (m_character_manager->GetEnd())
	{
		m_is_end = true;
		m_next = SceneType::kGameResult;
		return;
	}

	if (m_game_manager->IsPause() || 
		m_input->IsKeyTrigger(KEY_INPUT_P))
	{
		m_is_end = true;
		m_next = SceneType::kPause;
		return;
	}
}

void GamePlay::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter

	m_background->DrawBack();				//背景

	m_character_manager->Draw();			//Character
	m_attack_manager->Draw();				//攻撃Effect

	m_background->DrawFront();				//前景

	m_renderer->DrawBloom();				//BloomEffect
}

void GamePlay::Shutdown()
{
	//次がPauseだったらShutDownしない
	//次が勝利シーンだったらShutDownしないが、勝利シーンがShutDownできるように
	//Initializeの時記録した前のシーンがGamePlay（勝利シーンになる）の場合は
	//ShutDownする
	if (m_next == SceneType::kPause ||
		(m_next == SceneType::kGameResult && m_previous != SceneType::kGamePlay))
		return;

	m_meta_ai = NULL;
	m_character_manager = NULL;
	m_attack_manager = NULL;
	m_background = NULL;
	m_game_manager->Clear();
}