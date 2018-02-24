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
#include <GameObject\UI\chara_hp_ui.h>
#include <Def\start_position.h>

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
	m_meta_ai = make_shared<AI::MetaAI>(m_character_manager, m_attack_manager);

	//--------------------------あとで削除--------------------------------
	m_game_manager->AddSelectCharacter(
		make_shared<Job::Programmer>(Side::kTeam1),
		Side::kTeam1, make_shared<Character::KeyboardController>(1));
	m_game_manager->AddSelectAI(
		make_shared<Job::Business>(Side::kTeam3),
		Side::kTeam3, 2, 9);
	m_game_manager->AddSelectAI(
		make_shared<Job::Planner>(Side::kTeam4),
		Side::kTeam4, 3, 9);
	m_game_manager->AddSelectAI(
		make_shared<Job::ComputerGraphic>(Side::kTeam2),
		Side::kTeam2, 4, 9);
	//--------------------------あとで削除--------------------------------

	AddCharacter();
}

void GamePlay::AddCharacter() 
{
	vector<int> pos_num = {1, 2, 3, 4};				//使用する位置

	Device::Random* random = Device::GameDevice::GetInstance()->GetRandom();

	for (auto &chara_info : m_game_manager->GetSelectInfo()) 
	{
		int pos = 0;								//使用する位置の添え字
		Math::Vector3 position = Math::Vector3();	//生成位置
		if (pos_num.size() > 0)						//まだ使っていない位置があれば
		{
			pos = random->Next(0, pos_num.size());	//添え字をランダム選出
			position = StartPosition::GetStartPos(pos_num[pos]);		//位置取得
			pos_num.erase(pos_num.begin() + pos);	//同じ位置を使われないように削除
		}
		else
		{
			pos = random->Next(5, 7);				//それ以外は左か右かの位置に設定
			position = StartPosition::GetStartPos(pos);
		}

		if (chara_info.m_controller == NULL)		//Comの場合
		{
			//Com追加
			m_meta_ai->AddCom(position, chara_info.m_side, chara_info.m_job, 
				chara_info.m_difficulty, chara_info.m_player_num);
			continue;
		}

		//Player追加
		m_character_manager->Add(position, chara_info.m_side, 
			chara_info.m_controller, chara_info.m_job, m_attack_manager);
	}
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

	if (m_game_manager->IsPause())
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

	m_meta_ai->Clear();
	m_meta_ai = NULL;
	m_character_manager = NULL;
	m_attack_manager->Initialize();
	m_attack_manager = NULL;
	m_background = NULL;
	m_game_manager->Clear();
}