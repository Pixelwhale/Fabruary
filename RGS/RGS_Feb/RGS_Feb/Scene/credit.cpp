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
}

void Credit::Update()
{
	m_background->Update();

	CheckEnd();
}

void  Credit::CheckEnd()
{
	if (m_input->IsKeyTrigger(KEY_INPUT_SPACE))
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
		return;
	}

	if (m_input->IsKeyTrigger(KEY_INPUT_A))
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
		return;
	}

	if (m_input->IsKeyTrigger(KEY_INPUT_D))
	{
		m_is_end = true;
		m_next = SceneType::kTitle;
		return;
	}

	for (int i = 0; i < m_input->CurrentPadCount(); ++i)
	{
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_B))
		{
			m_is_end = true;
			m_next = SceneType::kTitle;
			return;
		}
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_A))
		{
			m_is_end = true;
			m_next = SceneType::kTitle;
			return;
		}
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_X))
		{
			m_is_end = true;
			m_next = SceneType::kTitle;
			return;
		}
		if (m_input->IsPadButtonTrigger(i, XINPUT_BUTTON_START))
		{
			m_is_end = true;
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


}

void Credit::Shutdown()
{
}