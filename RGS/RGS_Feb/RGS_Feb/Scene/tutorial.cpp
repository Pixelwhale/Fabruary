//-------------------------------------------------------
// ì¬ÒFœ@Œ[Ÿ
// ì¬“úF2018.02.05
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
}

void Tutorial::Update()
{
	m_background->Update();

	CheckEnd();
}

void  Tutorial::CheckEnd()
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

void Tutorial::Draw()
{
	m_renderer->DrawOnBloomFilter();		//DrawFilter
	m_background->DrawBack();				//”wŒi
	m_background->DrawFront();				//‘OŒi
	m_renderer->DrawBloom();				//BloomEffect


}

void Tutorial::Shutdown()
{
}