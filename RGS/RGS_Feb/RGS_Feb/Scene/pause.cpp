//-------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.22
// ���e�@�FPause�V�[��
//-------------------------------------------------------
#include <Scene\pause.h>

using namespace Scene;

Pause::Pause(std::shared_ptr<SceneBase> game_play)
	:m_game_play(game_play)
{
}

void Pause::Initialize(SceneType previous)
{
	m_previous = previous;

	m_blur_ratio = 10;
	m_blur_switch = true;
	m_is_end = false;
}

void Pause::Update()
{
	if (CheckEnd())
		return;

	if (m_input->IsKeyTrigger(KEY_INPUT_B))	//ToDo:Pause���������l����������
		m_blur_switch = false;

	UpdateEffect();
}

void Pause::UpdateEffect()
{
	if (m_blur_switch)
	{
		m_blur_ratio += 10;
		m_blur_ratio = (m_blur_ratio >= kBlurMax) ? kBlurMax : m_blur_ratio;
	}
	else
	{
		m_blur_ratio -= 10;
	}
}

bool Pause::CheckEnd()
{
	if (m_blur_ratio > 0)						//�ڂ��������ɖ߂�܂ő҂�
		return false;

	m_is_end = true;
	m_next = m_previous;
	return true;
}

void Pause::Draw()
{
	m_renderer->DrawOnGaussFilter();					//RenderTarget�ɕ`��

	m_game_play->Draw();						//�Q�[���V�[���`��

	m_renderer->GaussFilter(m_blur_ratio);		//Filter���ʂŕ`��

	m_renderer->DrawString("Pause", Math::Vector2(150, 0));
}

void Pause::Shutdown()
{
}