//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FGamePlay�V�[��
//-------------------------------------------------------
#include <Scene\gameplay.h>
#include <Character\Controller\keyboard_controller.h>
#include <GameObject\Job\programmer.h>
#include <GameObject\Job\planner.h>
#include <GameObject\Job\com_graphic.h>
#include <GameObject\Job\business.h>
#include <GameObject\UI\chara_hp_ui.h>
#include <Def\start_position.h>
#include <Def\window_def.h>

using namespace Scene;

GamePlay::GamePlay(shared_ptr<Background> background, std::shared_ptr<SceneEffect> scene_effect, std::shared_ptr<GameManager> game_manager)
	:m_background(background), m_scene_effect(scene_effect), m_game_manager(game_manager)
{
}

void GamePlay::Initialize(SceneType previous)
{
	m_is_end = false;
	m_previous = previous;

	if (previous == SceneType::kPause ||
		previous == SceneType::kGamePlay)
		return;

	//m_scene_effect = make_shared<SceneEffect>();
	m_scene_effect->Zoom(false);
	m_scene_effect->SetZoomRate(5.0f);

	m_attack_manager = make_shared<AttackSystem::AttackManager>();
	m_character_manager = make_shared<Character::CharacterManager>();
	m_attack_manager->Initialize();
	m_character_manager->Initialize();
	m_meta_ai = make_shared<AI::MetaAI>(m_character_manager, m_attack_manager);

	AddCharacter();
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
	m_background->Update();
	m_scene_effect->Update();
	if (!m_scene_effect->IsEnd(false))
		return;

	m_meta_ai->Update();
	m_character_manager->Update();
	m_attack_manager->Update(m_character_manager);

	CheckEnd();
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

	for (auto &character : m_character_manager->GetWinnerList())
	{
		std::shared_ptr<MotionSystem::Motion> motion =
			make_shared<MotionSystem::Motion>("Character");

		motion->Initialize();
		motion->Play("chara_base_anime/skill_energy_blast");
		motion->ChangeSpriteSheet("chara_programmer");
		motion->SetPosition(winner_position);
		motion->SetColor(Color(0.4f, 0.8f, 0.4f));
		motion->Update();

		winner_motion.push_back(motion);
		winner_position += Math::Vector3(Size::kCharaX, 0, 0);
	}

	m_game_manager->SetWinner(winner_motion);
}

void GamePlay::Draw()
{
	if (!m_scene_effect->IsEnd(false))		//SceneChangeEffect����
		m_scene_effect->DrawOnEffect();

	m_renderer->DrawOnBloomFilter();		//DrawFilter

	m_background->DrawBack();				//�w�i

	m_character_manager->Draw();			//Character
	m_attack_manager->Draw();				//�U��Effect

	m_background->DrawFront();				//�O�i

	m_renderer->DrawBloom();				//BloomEffect

	if (!m_scene_effect->IsEnd(false))		//SceneChangeEffect����
		m_scene_effect->DrawEffect();
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
	//m_scene_effect = NULL;
	m_game_manager->Clear();
}