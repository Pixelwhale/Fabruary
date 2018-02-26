//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.22
// 内容　：Stage背景
//-------------------------------------------------------------
#include <GameObject\Background\background.h>

Background::Background()
{
	m_random = Device::GameDevice::GetInstance()->GetRandom();
	m_renderer = Device::GameDevice::GetInstance()->GetRenderer();
	m_light_alpha = 0;
	m_pc_light = 0.5f;
	m_pc_alpha_switch = true;

	InitializeMotion();
}

Background::Background(const Background&)
{
}

Background::~Background()
{
	m_renderer = NULL;
	m_random = NULL;

	m_programmer = NULL;
	m_damage = NULL;
	m_damage_center = NULL;
	m_damage_left = NULL;
	m_walk = NULL;

	for (auto &motion : m_winner_motion)
	{
		motion = NULL;
	}
	m_winner_motion.clear();
}

void Background::InitializeMotion()
{
	m_programmer = make_shared<MotionSystem::Motion>("Character");
	m_programmer->Initialize();
	m_programmer->Play("chara_base_anime/skill_energy_blast");
	m_programmer->ChangeSpriteSheet("chara_programmer");
	m_programmer->SetPosition(Math::Vector3(605, 55, -450));
	m_programmer->SetScale(Math::Vector2(0.35f, 0.35f));
	m_programmer->SetColor(Color(0.4f, 0.8f, 0.4f));
	m_programmer->Update(1 / 30.0f);

	m_damage = make_shared<MotionSystem::Motion>("Character");
	m_damage->Initialize();
	m_damage->Play("chara_base_anime/knock_down");
	m_damage->ChangeSpriteSheet("chara_planner");
	m_damage->SetPosition(Math::Vector3(190, 55, -450));
	m_damage->SetScale(Math::Vector2(0.35f, 0.35f));
	m_damage->Flip(true, false);
	m_damage->SetColor(Color(0.8f, 0.4f, 0.4f));
	m_damage->SetFrame(36);
	m_damage->Update(1 / 90.0f);

	m_damage_center = make_shared<MotionSystem::Motion>("Character");
	m_damage_center->Initialize();
	m_damage_center->Play("chara_base_anime/knock_down");
	m_damage_center->ChangeSpriteSheet("chara_designer");
	m_damage_center->SetPosition(Math::Vector3(-230, 55, -450));
	m_damage_center->SetScale(Math::Vector2(0.35f, 0.35f));
	m_damage_center->Flip(true, false);
	m_damage_center->SetColor(Color(0.8f, 0.8f, 0.2f));
	m_damage_center->SetFrame(26);
	m_damage_center->Update(1 / 90.0f);

	m_damage_left = make_shared<MotionSystem::Motion>("Character");
	m_damage_left->Initialize();
	m_damage_left->Play("chara_base_anime/knock_down");
	m_damage_left->ChangeSpriteSheet("chara_business");
	m_damage_left->SetPosition(Math::Vector3(-630, 55, -450));
	m_damage_left->SetScale(Math::Vector2(0.35f, 0.35f));
	m_damage_left->Flip(true, false);
	m_damage_left->SetColor(Color(0.2f, 0.8f, 0.8f));
	m_damage_left->SetFrame(16);
	m_damage_left->Update(1 / 90.0f);

	m_walk = make_shared<MotionSystem::Motion>("Character");
	m_walk->Initialize();
	m_walk->Play("chara_base_anime/walk_intro");
	m_walk->ChangeSpriteSheet("chara_business");
	m_walk->SetPosition(Math::Vector3(-645, 0, 150));
	m_walk->SetScale(Math::Vector2(0.35f, 0.35f));
	m_walk->Flip(true, false);
	m_walk->SetColor(Color(0.4f, 0.4f, 0.8f));
	m_walk->Update();

	m_designer = make_shared<MotionSystem::Motion>("Character");
	m_designer->Initialize();
	m_designer->Play("chara_base_anime/skill_color_slash");
	m_designer->ChangeSpriteSheet("chara_designer");
	m_designer->SetPosition(Math::Vector3(590, 0, 170));
	m_designer->SetScale(Math::Vector2(0.15f, 0.15f));
	m_designer->SetColor(Color(0.8f, 0.5f, 0.3f));
	m_designer->Update();
}

void Background::Update()
{
	for (auto &winner : m_winner_motion)
	{
		winner->Update();		//Todo：Pose変更
	}

	m_light_alpha = m_random->NextDouble() + 0.7f;

	if (m_pc_alpha_switch)
	{
		m_pc_light += 0.01f;
		if (m_pc_light >= 1.0f)
			m_pc_alpha_switch = false;
	}
	else
	{
		m_pc_light -= 0.01f;
		if (m_pc_light <= 0.5f)
			m_pc_alpha_switch = true;
	}

	m_programmer->Update(1 / 30.0f);
	m_damage->Update(1 / 90.0f);
	m_damage_center->Update(1 / 90.0f);
	m_damage_left->Update(1 / 90.0f);
	m_walk->Update();
	m_designer->Update();
}

void Background::SetWinner(vector<shared_ptr<MotionSystem::Motion>> winners)
{
	if (winners.size() <= 0)		//ない場合は上書きしない
		return;

	for (auto &motion : m_winner_motion) 
	{
		motion = NULL;
	}
	m_winner_motion.clear();

	m_winner_motion = winners;
}

void Background::DrawBack()
{
	m_renderer->DrawTexture("background", Math::Vector2());
	m_renderer->DrawTexture("background_light", Math::Vector2(592, 201), m_light_alpha);
	m_renderer->DrawTexture("background_pc_light_back", Math::Vector2(), m_pc_light);

	m_renderer->DrawTexture("pc_monitor", Math::Vector2(-13, 215), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(1084, 203), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("monitor", Math::Vector2(246, 113), m_random->NextDouble() + 0.95f);

	m_designer->Draw();
	m_walk->Draw();

	for (auto &winner : m_winner_motion) 
	{
		winner->Draw();
	}
}

void Background::DrawFront()
{
	m_renderer->DrawTexture("background_front", Math::Vector2());
	m_renderer->DrawTexture("background_pc_light_front", Math::Vector2(), m_pc_light);

	m_renderer->DrawTexture("pc_monitor", Math::Vector2(1113, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(736, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(359, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(-7, 562), m_random->NextDouble() + 0.9f);

	m_programmer->Draw();
	m_damage->Draw();
	m_damage_center->Draw();
	m_damage_left->Draw();
}