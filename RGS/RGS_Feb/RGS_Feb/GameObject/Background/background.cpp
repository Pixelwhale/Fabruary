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
}

void Background::DrawFront() 
{
	m_renderer->DrawTexture("background_front", Math::Vector2());
	m_renderer->DrawTexture("background_pc_light_front", Math::Vector2(), m_pc_light);
}