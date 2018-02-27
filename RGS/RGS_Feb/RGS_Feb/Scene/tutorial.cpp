//-------------------------------------------------------
// çÏê¨é“ÅFú@å[èü
// çÏê¨ì˙ÅF2018.02.05
//-------------------------------------------------------
#include <Scene\tutorial.h>

using namespace Scene;

Tutorial::Tutorial(shared_ptr<Background> background)
	:m_background(background)
{
}

void Tutorial::Initialize(SceneType previous) 
{
	SceneBase::Initialize(previous);

	m_alpha_switch = true;
	m_tutorial_alpha = 0.0f;
}

void Tutorial::Update()
{
	m_background->Update();

	if (m_alpha_switch) 
	{
		m_tutorial_alpha += 0.07f;
		if (m_tutorial_alpha >= 1.0f)
			m_tutorial_alpha = 1.0f;
	}
	else
	{
		m_tutorial_alpha -= 0.07f;
		if (m_tutorial_alpha <= 0.0f)
			m_tutorial_alpha = 0.0f;
	}

	CheckEnd();
}

void  Tutorial::CheckEnd()
{
	if (m_alpha_switch == false && m_tutorial_alpha <= 0.0f) 
	{
		m_next = SceneType::kTitle;
		m_is_end = true;
		return;
	}

	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE) ||
		m_input->IsKeyTrigger(KEY_INPUT_A) ||
		m_input->IsKeyTrigger(KEY_INPUT_D))
	{
		m_alpha_switch = false;
		m_next = SceneType::kTitle;
		return;
	}

	for (int i = 0; i < m_input->CurrentPadCount(); ++i)
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_B) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_A) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_X) ||
			m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_START))
		{
			m_alpha_switch = false;
			m_next = SceneType::kTitle;
			return;
		}
	}
}

void Tutorial::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//îwåi
	m_background->DrawFront();				//ëOåi
	m_renderer->DrawBloom();				//BloomEffect

	m_renderer->DrawTexture("tutorial", Math::Vector2(), m_tutorial_alpha);
}

void Tutorial::Shutdown()
{
}