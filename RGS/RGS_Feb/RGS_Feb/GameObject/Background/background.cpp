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
}

Background::Background(const Background&) 
{
}

Background::~Background() 
{
	m_renderer = NULL;
	m_random = NULL;
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
}

void Background::DrawBack() 
{
	m_renderer->DrawTexture("background", Math::Vector2());
	m_renderer->DrawTexture("background_light", Math::Vector2(592, 202), m_light_alpha);
	m_renderer->DrawTexture("background_pc_light_back", Math::Vector2(), m_pc_light);

	m_renderer->DrawTexture("pc_monitor", Math::Vector2(-13, 215), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(1084, 203), m_random->NextDouble() + 0.9f);
}

void Background::DrawFront() 
{
	m_renderer->DrawTexture("background_front", Math::Vector2());
	m_renderer->DrawTexture("background_pc_light_front", Math::Vector2(), m_pc_light);

	m_renderer->DrawTexture("pc_monitor", Math::Vector2(1113, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(736, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(359, 562), m_random->NextDouble() + 0.9f);
	m_renderer->DrawTexture("pc_monitor", Math::Vector2(-7, 562), m_random->NextDouble() + 0.9f);
}