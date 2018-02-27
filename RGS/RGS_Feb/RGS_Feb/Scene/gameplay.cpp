//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FGamePlay�V�[��
//-------------------------------------------------------
#include <Scene\gameplay.h>
#include <Def\window_def.h>
#include <Def\start_position.h>
#include <Def\character_color.h>

using namespace Scene;

GamePlay::GamePlay(shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect, std::shared_ptr<GameManager> game_manager)
	:m_background(background), m_scene_effect(scene_effect), m_game_manager(game_manager)
{
	m_sound = Device::GameDevice::GetInstance()->GetInstance()->GetSound();
}

void GamePlay::Initialize(SceneType previous)
{
	m_is_end = false;
	m_previous = previous;

	if (previous == SceneType::kPause ||
		previous == SceneType::kGamePlay)
		return;

	m_scene_effect->Zoom(false);
	m_scene_effect->SetZoomRate(5.0f);

	m_attack_manager = make_shared<AttackSystem::AttackManager>();
	m_character_manager = make_shared<Character::CharacterManager>();
	m_attack_manager->Initialize();
	m_character_manager->Initialize();
	m_meta_ai = make_shared<AI::MetaAI>(m_character_manager, m_attack_manager);

	AddCharacter();

	m_is_fight = false;
	m_fight_se_timer = Utility::Timer(2.2f);
	m_fight_se_timer.Reset();

	m_fight_string_timer = Utility::Timer(1);
	m_fight_string_timer.Reset();
}

void GamePlay::AddCharacter()
{
	vector<int> pos_num = { 1, 2, 3, 4 };				//�g�p����ʒu

	Device::Random* random = Device::GameDevice::GetInstance()->GetRandom();

	for (auto &chara_info : m_game_manager->GetSelectInfo())
	{
		int pos = 0;								//�g�p����ʒu�̓Y����
		Math::Vector3 position = Math::Vector3();	//�����ʒu
		if (pos_num.size() > 0)						//�܂��g���Ă��Ȃ��ʒu�������
		{
			pos = random->Next(0, pos_num.size());	//�Y�����������_���I�o
			position = StartPosition::GetStartPos(pos_num[pos]);		//�ʒu�擾
			pos_num.erase(pos_num.begin() + pos);	//�����ʒu���g���Ȃ��悤�ɍ폜
		}
		else
		{
			pos = random->Next(5, 7);				//����ȊO�͍����E���̈ʒu�ɐݒ�
			position = StartPosition::GetStartPos(pos);
		}

		if (chara_info.m_controller == NULL)		//Com�̏ꍇ
		{
			//Com�ǉ�
			m_meta_ai->AddCom(position, chara_info.m_side, chara_info.m_job,
				chara_info.m_ai_controller, chara_info.m_difficulty);
			continue;
		}

		//Player�ǉ�
		m_character_manager->Add(position, chara_info.m_side,
			chara_info.m_controller, chara_info.m_job, m_attack_manager);
	}
}

void GamePlay::Update()
{
	m_sound->PlayBGM("tw052");

	m_background->Update();							//�w�i�X�V
	m_scene_effect->Update();						//SceneChange�X�V
	if (!m_scene_effect->IsEnd(false))				//SceneChange��
		return;

	UpdateMonitor();

	m_meta_ai->Update();
	m_character_manager->Update();
	m_attack_manager->Update(m_character_manager);

	CheckEnd();
}

void GamePlay::UpdateMonitor()
{
	if (m_is_fight)
	{
		m_fight_string_timer.Update();
		if (m_fight_string_timer.IsTime())
			m_fight_string_timer.Reset();
		return;
	}

	m_fight_se_timer.Update();
	if (m_fight_se_timer.IsTime())
	{
		m_is_fight = true;
		Device::GameDevice::GetInstance()->GetSound()->PlaySE("�S���O_onjin");
	}
}

void GamePlay::CheckEnd()
{
	if (m_character_manager->GetEnd())
	{
		SetWinner();
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

void GamePlay::SetWinner()
{
	m_game_manager->ClearWinnerMotion();
	vector<std::shared_ptr<MotionSystem::Motion>> winner_motion;
	Math::Vector3 winner_position = Math::Vector3(
		100, 128,
		WindowDef::kScreenHeight / 2 - Size::kCharaZ * 6);

	Device::Random* rand = Device::GameDevice::GetInstance()->GetRandom();
	for (auto &character : m_character_manager->GetWinnerList())
	{
		std::shared_ptr<MotionSystem::Motion> motion =
			make_shared<MotionSystem::Motion>("Character");

		motion->Initialize();
		motion->Play("chara_base_anime/win_pose_" + std::to_string(rand->Next(1, 3)), 1);
		motion->ChangeSpriteSheet(character->GetSheetName());
		motion->SetPosition(winner_position);
		motion->SetColor(CharacterColor::GetTeamColor(character->GetSide()));
		motion->Update();

		winner_motion.push_back(motion);
		winner_position += Math::Vector3(Size::kCharaX, 0, 0);
	}
	rand = NULL;

	m_game_manager->SetWinner(winner_motion);
}

void GamePlay::Draw()
{
	if (!m_scene_effect->IsEnd(false))		//SceneChangeEffect����
		m_scene_effect->DrawOnEffect();

	m_renderer->DrawOnBloomFilter();		//DrawFilter

	m_background->DrawBack();				//�w�i

	DrawMonitor();							//Monitor�`��

	m_character_manager->Draw();			//Character
	m_attack_manager->Draw();				//�U��Effect

	m_background->DrawFront();				//�O�i

	m_renderer->DrawBloom();				//BloomEffect

	if (!m_scene_effect->IsEnd(false))		//SceneChangeEffect����
		m_scene_effect->DrawEffect();
}

void GamePlay::DrawMonitor()
{
	if (!m_is_fight)
	{
		m_renderer->DrawTexture("select_chara_ready",
			Math::Vector2(380, 170), Math::Vector2(256, 128),
			Math::Vector2(0.5f, 0.5f), 0, Color(1.0f, 1.0f, 1.0f));
		return;
	}

	if (m_is_end == true && m_next == SceneType::kGameResult)
	{

		return;
	}

	if (m_fight_string_timer.GetCurrentTimes() % 20 < 10)
		m_renderer->DrawTexture("fight",
			Math::Vector2(380, 190), Math::Vector2(256, 128),
			Math::Vector2(0.5f, 0.5f), 0, Color(1.0f, 1.0f, 1.0f));
}

void GamePlay::Shutdown()
{
	//����Pause��������ShutDown���Ȃ�
	//���������V�[����������ShutDown���Ȃ����A�����V�[����ShutDown�ł���悤��
	//Initialize�̎��L�^�����O�̃V�[����GamePlay�i�����V�[���ɂȂ�j�̏ꍇ��
	//ShutDown����
	if (m_next == SceneType::kPause ||
		(m_next == SceneType::kGameResult && m_previous != SceneType::kGamePlay))
		return;

	m_meta_ai->Clear();
	m_meta_ai = NULL;
	m_character_manager = NULL;
	m_attack_manager->Initialize();
	m_attack_manager = NULL;
	m_game_manager->Clear();
}