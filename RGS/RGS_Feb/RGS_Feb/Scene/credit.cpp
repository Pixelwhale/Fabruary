//-------------------------------------------------------
// ì¬ÒF—Ñ‰À‰b
// ì¬“úF2018.2.27
// “à—e@FCredit Scene
//-------------------------------------------------------
#include <Scene\credit.h>

using namespace Scene;

Credit::Credit(shared_ptr<Background> background)
	:m_background(background)
{
}

void Credit::Initialize(SceneType previous)
{
	SceneBase::Initialize(previous);

	m_alpha_switch = true;
	m_credit_alpha = 0.0f;
}

void Credit::Update()
{
	m_background->Update();

	if (m_alpha_switch)
	{
		m_credit_alpha += 0.07f;
		if (m_credit_alpha >= 1.0f)
			m_credit_alpha = 1.0f;
	}
	else
	{
		m_credit_alpha -= 0.07f;
		if (m_credit_alpha <= 0.0f)
			m_credit_alpha = 0.0f;
	}

	CheckEnd();
}

void  Credit::CheckEnd()
{
	if (m_alpha_switch == false && m_credit_alpha <= 0.0f)
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

void Credit::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//”wŒi
	m_background->DrawFront();				//‘OŒi
	m_renderer->DrawBloom();				//BloomEffect

	m_renderer->DrawTexture("credit", Math::Vector2(), m_credit_alpha);
}

void Credit::Shutdown()
{
}