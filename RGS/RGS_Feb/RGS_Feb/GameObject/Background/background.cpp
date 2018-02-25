//-------------------------------------------------------------
// çÏê¨é“ÅFó—â¿âb
// çÏê¨ì˙ÅF2018.2.22
// ì‡óeÅ@ÅFStageîwåi
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
	m_walk = NULL;
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
	m_programmer->Update();

	m_damage = make_shared<MotionSystem::Motion>("Character");
	m_damage->Initialize();
	m_damage->Play("chara_base_anime/knock_down");
	m_damage->ChangeSpriteSheet("chara_planner");
	m_damage->SetPosition(Math::Vector3(190, 55, -450));
	m_damage->SetScale(Math::Vector2(0.35f, 0.35f));
	m_damage->Flip(true, false);
	m_damage->SetColor(Color(0.8f, 0.4f, 0.4f));
	m_damage->SetFrame(40);
	m_damage->Update(1 / 180.0f);

	m_walk = make_shared<MotionSystem::Motion>("Character");
	m_walk->Initialize();
	m_walk->Play("chara_base_anime/walk_intro");
	m_walk->ChangeSpriteSheet("chara_business");
	m_walk->SetPosition(Math::Vector3(-230, 55, -450));
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
	m_designer->SetColor(Color(0.8f, 0.8f, 0.2f));
	m_designer->Update();
}

void Background::Update() 
{
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

	m_programmer->Update();
	m_damage->Update(1 / 180.0f);
	m_walk->Update();
	m_designer->Update();
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
	m_walk->Draw();
}